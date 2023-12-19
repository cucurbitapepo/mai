#include <stdio.h>
#include <dirent.h>

enum exit_codes
{
    invalid_dir,
    success,
};

int _ls(const char *dir)
{
    struct dirent *d;
    DIR *dh = opendir(dir);
    if(dh == NULL) return invalid_dir;
    while ((d = readdir(dh)) != NULL)
    {
        if(d->d_name[0] != '.') printf("%s\n", d->d_name);
    }
    return success;
}

int main(int argc, char** argv)
{

    if(argc == 1)
    {
        if(_ls(".") == invalid_dir) { printf("unexpected error\n"); return 1; }
    }
    for(int i = 1; i < argc; i++)
    {
        printf("Parsing directory: '%s'\n", argv[i]);
        if(_ls(argv[i]) == invalid_dir)
        {
            printf("Couldn't parse the directory @ '%s'\n", argv[i]);
        }
    }
    return 0;
}