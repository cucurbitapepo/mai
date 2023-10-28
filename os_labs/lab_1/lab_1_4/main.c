#include "functions.h"

int main(int argc, char** argv) {
    if(argc < 3 || argc > 4)
    {
        printf("Invalid amount of arguments.\n");
        return 0;
    }

    unsigned int result = 0;
    int length = 0;
    int sign = 0;
    int hex = 0;
    int flag;
    flag = define_flag(&argv[2]);
    FILE* origin;
    result = 0;
    if((origin = fopen(argv[1], "r")) == NULL)
    {
        printf("Couldn't open file at %s\n", argv[2]);
        return 0;
    }

    switch(flag)
    {
        case _xor8:
        {
            if(argc != 3)
            {
                printf("Invalid amount of arguments\n");
                break;
            }
            result = xor8(origin);
            printf("Result of XOR for each byte is %d\n", result);
            break;
        }
        case _xor32:
        {
            if(argc != 3)
            {
                printf("Invalid amount of arguments\n");
                break;
            }
            result = xor32(origin);
            printf("Result of XOR for each 4 bytes is %d\n", result);
            break;
        }
        case _mask:
        {
            if(argc != 4)
            {
                printf("Invalid amount of arguments\n");
                break;
            }
            length = strlen(argv[3]);
            hex = to_decimal(&argv[3], length, 16, &sign);
            result = mask(origin, hex);
            printf("There are %d 4-byte groups that match given mask\n", result);
            break;
        }
        case _invalid_flag:
        {
            printf("Invalid flag given\n");
            break;
        }
        default:
        {
            printf("unexpected error ???\n");
            break;
        }
    }
    fclose(origin);
    printf("Program finished\n");
    return 0;
}
