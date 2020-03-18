static bool get_fs_type(const char *p_dev, _OUTPUT AM_FS_TYPE &fs_type)
{
  bool ret = true;
  blkid_cache cache = nullptr;
  blkid_dev dev;
  blkid_tag_iterate iter;
  const char *ptype = nullptr;//Bk!:没啥用呀？
  const char *pvalue =nullptr;

  DEBUG("p_dev : %s", p_dev);
  do {
    if (blkid_get_cache(&cache, NULL) < 0) {
      ret = false;
      break;
    }

    dev = blkid_get_dev(cache, p_dev, BLKID_DEV_NORMAL);
    iter = blkid_tag_iterate_begin(dev);

    while (blkid_tag_next(iter, &ptype, &pvalue) == 0) {
      DEBUG("value : %s", pvalue);
      if (!strcmp(ptype, "TYPE"))
        break;
    }
    blkid_tag_iterate_end(iter);

    if (!pvalue) {
      ERROR("Cannot get filesystem type!");
      ret = false;
      break;
    }

    DEBUG("p_dev : %s, pvalue %s", p_dev, pvalue);
    if (!strcmp(pvalue, "vfat") || !strcmp(pvalue, "fat")) {
      fs_type = AM_VFAT;
    } else if (!strcmp(pvalue, "exfat")) {
      fs_type = AM_EXFAT;
    } else if (!strcmp(pvalue, "ubifs")) {
      fs_type = AM_UBIFS;
    } else if (! strcmp(pvalue, "ext4")) {
      fs_type = AM_EXT4;
    } else {
      ERROR("unknown filesystem type");
      ret = false;
      break;
    }
    } while (0);

  if (cache) {
    blkid_put_cache(cache);
  }

  return ret;
}

