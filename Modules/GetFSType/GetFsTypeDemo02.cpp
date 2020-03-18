#include <stdio.h>
#include <blkid/blkid.h>
int main(int argc, char **argv)
{
        blkid_cache cache;
        const char *pfstype;
        if(argc != 2)
        {
                printf("Usage: %s devicename/n", argv[0]);
                return 0;
        }
        blkid_get_cache(&cache, "/dev/null");
        pfstype = blkid_get_tag_value(cache, "TYPE", argv[1]);
        blkid_put_cache(cache);
        printf("The fstype by probing is %s/n", pfstype==NULL?"<don’t know>":pfstype);
        return 0;
}



