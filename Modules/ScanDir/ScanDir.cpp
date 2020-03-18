static inline int32_t cmp_file_time(const struct dirent **p1,
                                    const struct dirent **p2)
{
  struct stat st1, st2;

  stat((*p1)->d_name, &st1);
  stat((*p2)->d_name, &st2);
  return (st1.st_mtime - st2.st_mtime);//Bk!:true表示p1笔记新，否则p2是新文件；
}

static int32_t scan_dir_filter(const struct dirent *p_dir)
{
  struct stat st;
  stat(p_dir->d_name, &st);

  // skip not regular and dir files
  if (!S_ISREG(st.st_mode) &&
    !S_ISDIR(st.st_mode)) {
    return 0;
  }

  if (strcmp(p_dir->d_name, ".") == 0 ||
    strcmp(p_dir->d_name, "..") == 0) {
    return 0;
  }

  return 1;//Bk!:到这里表明是普通文件，且非"."和".."
}


int AMStorageManagerSdcard::delete_oldest_file(const char *dir_path)
{
	char cur_dir[AM_MAX_PATH_LEN] ={0};
	char rm_file_path[AM_MAX_PATH_LEN * 2] = {0};
	struct dirent **list = nullptr;
	int32_t n = 0;
	int ret = 0;

	do 
	{
		if (!dir_path || !is_dir(dir_path) || !getcwd(cur_dir, AM_MAX_PATH_LEN -1)) 
		{
			ERROR("path error!");
			ret = -1;
			break;
		}

		if (chdir(dir_path))//Bk?:那个函数要求必须切到这个目录才能工作？ 
		{//Bk?:某个线程中调用该函数将工作目录改变了，别的线程如果存在"写操作"会不会影响？
			ERROR("%s is not exist\n", dir_path);
			ret = -1;
			break;
		}

		if ((n = scandir(".", &list, scan_dir_filter, cmp_file_time)) > 0) 
		{//Bk!:list[0]应该是最老的文件
			snprintf(rm_file_path, sizeof(rm_file_path) - 1, "%s/%s", dir_path,list[0]->d_name);//Bk?:这里会不会多一个"/"？
			/*remove sub folder of files*/
			if (is_dir (rm_file_path)) 
			{
				ret = delete_oldest_file(rm_file_path);//Bk!:递归删除文件
			} else 
			{
				INFO("succeed to remove file : %s", rm_file_path);
				if (remove(rm_file_path) < 0) 
				{
					ERROR("failed to remove file : %s !!!", rm_file_path);
					ret = -1;
				}
			}

			while (n--) 
			{
				free(list[n]);
				list[n] = nullptr;
			}

			free(list);
			list = nullptr;
		} else if (n == 0)//Bk?:什么时候会返回0
		{
			std::string s(dir_path);
			auto i = m_reserved_size_map.find(s);
			if (i != m_reserved_size_map.end())
			{
				WARN("folder %s is empty!\n", dir_path);//Bk!:检测的路径下本身大小就小于要保留的大小
			} 
			else 
			{
				chdir(cur_dir);
				INFO("succeed to remove folder : %s", dir_path);
				if (remove(dir_path) < 0) 
				{
					ERROR("failed to remove folder : %s !!!", dir_path);
					ret = -1;
				}
			}
		}
		else 
		{
			perror("scandir failed! \n");
			ret = -1;
		}
		chdir(cur_dir);
	} while (0);

	return ret;
}



