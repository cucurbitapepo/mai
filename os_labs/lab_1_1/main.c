#include <stdio.h>

int main(int argc, char** argv) {

    if(argc != 2)
    {
        printf("Invalid amount of arguments.\n");
        return 0;
    }
    FILE* input;
    char buf[5];
    int c;

    input = fopen(argv[1], "w");
    if(input == NULL)
    {
        printf("Couldn't create file at %s", argv[1]);
        return 0;
    }
    if(fwrite("31415926535", sizeof(char), 11, input) != 11)
    {
        printf("Couldn't write to file %s", argv[1]);
        fclose(input);
        return 0;
    }

    fclose(input);
    input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("Can't open file at %s\n", argv[1]);
        return 0;
    }
    c = fgetc(input);
    while(!feof(input))
    {
        printf("\n%c _base: %s _ptr: %s _tmpfname: %s _cnt: %d _charbuf: %d _bufsize: %d _file: %d _flag: %d", c, input->_base, input->_ptr, input->_tmpfname, input->_cnt, input->_charbuf, input->_bufsiz, input->_file, input->_flag);
        c = fgetc(input);
    }
    fclose(input);

    input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("Can't open file at %s\n", argv[1]);
        return 0;
    }
    fseek(input, 3, SEEK_SET);
    fread(&buf, sizeof(char), 4, input);
    fclose(input);
    printf("\n%s", buf);

    return 0;
}
