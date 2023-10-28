//
// Created by cucurbita on 25.10.2023.
//

#include "functions.h"


void to_roman(int number)
{

}

char *convert(unsigned int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }
    while(num != 0);

    return(ptr);
}

void overprintf(const char* format, ...)
{

    va_list args;
    va_start(args, format);
    const char* string;
    char* s;
    unsigned int i;
    for(string = format; *string != '\0'; string++)
    {
        while(*string != '%')
        {
            putchar(*string);
            string++;
        }
        string++;

        switch(*string) {
            //individual
            case 'R':
            {

            }
            case 'Z':
            {

            }
            case 'C':
            {

            }
            case 't':
            {

            }
            case 'T':
            {

            }
            case 'm':
            {

            }
            //stock
            default:
            {
                //put_to_stack(stack, *string);
                break;
            }
        }

    }
}

void WriteFormatted (FILE * stream, const char * format, ...)
{
    va_list args;
    va_start (args, format);
    vfprintf (stream, format, args);
    va_end (args);
}
