#include <stdio.h>

int main(int argc, char** argv) {
    if(argc != 3)
    {
        printf("Invalid amount of arguments.\n");
        return 0;
    }
    FILE* origin;
    FILE* destination;
    int c;

    origin = fopen(argv[1], "r");
    if(origin == NULL)
    {
        printf("Can't open file at %s", argv[1]);
        return 0;
    }
    destination = fopen(argv[2], "w");
    if(destination == NULL)
    {
        printf("Couldn't create copy file at %s", argv[2]);
        return 0;
    }
    c = fgetc(origin);
    while(!feof(origin))
    {
        if(fputc(c, destination) == EOF)
        {
            printf("Copying failed, sorry :/\n");
            return 0;
        }
        c = fgetc(origin);
    }
    if(fputc(EOF, destination) == EOF)
    {
        printf("Copying failed, sorry :/\n");
        return 0;
    }
    printf("Copying successful.\nOrigin: %s\nDestination: %s", argv[1], argv[2]);
    return 0;
}
