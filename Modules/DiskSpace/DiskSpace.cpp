static uint32_t free_space(const char *dir_path)
{
  struct statfs s;
  int free_bsz;

  statfs(dir_path, &s);//Bk!:获取硬盘使用情况

  free_bsz = (s.f_bsize >> 10) * s.f_bavail;
  DEBUG("path : %s free space %dMB", dir_path, free_bsz >> 10);

  return (free_bsz >> 10); // MiB
}



