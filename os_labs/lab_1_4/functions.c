//
// Created by cucurbita on 08.10.2023.
//

#include "functions.h"

unsigned int xor8(FILE* file)
{//works i guess
    unsigned int c;
    unsigned int result;
    result = 0;
    c = fgetc(file);
    while(c != EOF)
    {
        result = result ^ c;
        c = fgetc(file);
    }
    return result;
}

unsigned int xor32(FILE* file)
{
    int c;
    unsigned int result;
    unsigned int group;

    result = 0;
    c = fgetc(file);
    while(c != EOF)
    {
        group = 0;
        for(int i = 0; i < 4; i++)
        {
            if(c == EOF)
            {
                group <<= (8 * (4-i));
                break;
            }
            group <<= 8;
            group += c;
            c = fgetc(file);
        }
        result ^= group;
    }
    return result;
}

size_t mask(FILE* file, unsigned int hex)
{
    size_t result;
    unsigned int group;
    result = 0;
    int c;
    c = fgetc(file);
    while(c != EOF)
    {
        group = 0;
        for(int i = 0; i < 4; i++)
        {
            if(c == EOF)
            {
                group <<= (8 * (4-i));
                break;
            }
            group <<= 8;
            group += c;
            c = fgetc(file);
        }
        if (hex == group) result++;
    }
    return result;
}

int to_decimal(char** string, int length, int base, int* sign)
{
    if((*string)[0] == '-')
    {
        (*string)++;
        length--;
        *sign = -1;
    }
    else
    {
        *sign = 1;
    }
    while((*string)[0] == '0')
    {
        (*string)++;
        length--;
    }
    int result = 0;
    int next;
    for(int i = 0; i < length; i++)
    {
        char c = (*string)[i];
        if(!isalnum(c) || tolower(c) != c)
        {
            return not_a_number;
        }
        if(isalpha(c)) next = c - 'a' + 10;
        else
        {
            next = c - '0';
        }
        if (next > base) return not_a_number;
        result = result * base + next;
    }
    return result;
}

int define_flag(char** string)
{
    if(strcmp(*string, "xor8") == 0) return _xor8;
    if(strcmp(*string, "xor32") == 0) return _xor32;
    if(strcmp(*string, "mask") == 0) return _mask;
    return _invalid_flag;
}