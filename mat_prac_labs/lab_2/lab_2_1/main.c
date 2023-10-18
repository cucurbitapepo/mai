#include "functions.h"

int main(int argc, char** argv) {
    if(argc < 2)
    {
        printf("Invalid amount of arguments.\n");
        return 0;
    }
    int check = check_flag(&argv[1]);
    if(!check)
    {
        printf("Invalid flag given.\n");
        return 0;
    }

    int count = 0;
    char* str = 0;
    char* digits = "";
    char* letters = "";
    char* rest = "";
    int total_size = 0;
    int flag = argv[1][1];

    switch (flag)
    {
        case 'l':
        {
            if(argc < 3)
            {
                printf("Invalid amount of arguments.\n");
                break;
            }
            count = string_length(&argv[2]);
            printf("String \"%s\" is %d symbols long.\n", argv[2], count);
            break;
        }
        case 'r':
        {
            if(reverse_str(&argv[2], &str) == memory_error)
            {
                printf("Memory error:/\n");
                break;
            }
            printf("%s reversed is %s", argv[2], str);
            break;
        }
        case 'u':
        {
            if(odd_to_upper(&argv[2], &str) == memory_error)
            {
                printf("Memory error:/\n");
                break;
            }
            printf("%s reversed is %s", argv[2], str);
            break;
        }
        case 'n':
        {
            str = argv[2];
            qsort(str, string_length(&argv[1]), sizeof(char), compare);
            printf("%s\n", str);
        }
        case 'c':
        {
                
        }
        default:
        {

        }
    }

    return 0;
}
