//
// Created by cucurbita on 13.10.2023.
//

#include "functions.h"

int check_flag(char** word)
{
    if(((*word)[0] != '-' && (*word)[0] != '/') || (*word)[2] != '\0') return 0;
    return 1;
}

int string_length(char** string)
{
    int count = 0;
    while((*string)[count] != '\0')
    {
        count++;
    }
    return count;
}

int reverse_str(char** string, char** result)
{
    int count = string_length(string);
    *result = (char*)malloc(sizeof(char)*(count+1));
    if(*result == NULL)
    {
        return memory_error;
    }
    for(int i = 0; i < count; i++)
    {
        (*result)[i] = (*string)[count-i-1];
    }
    (*result)[count] = '\0';
    return success;
}

int odd_to_upper(char** origin, char** result)
{
    int count = string_length(origin);
    *result = (char*)malloc(sizeof(char)*(count+1));
    if (*result == NULL)
    {
        return memory_error;
    }
    for(int i = 0; i < count; i++)
    {
        (*result)[i] = (i%2 == 0) ? (*origin)[i] : toupper((*origin)[i]);
    }
    (*result)[count] = '\0';
    return success;
}

int rearrange_string(char** result, char** origin)
{
    int length = string_length(origin);
    *result = (char*)malloc(sizeof(char)*(length+1));
    if(*result == NULL)
    {
        return memory_error;
    }
    for(int i = 0; i < length; i++)
    {
        if(isalpha((*origin)[i]))
        {

        }
    }
    return success;
}

int compare(void const* a, void const* b)
{
    if(isalpha(*(int*)a) && isalpha())
}

int concatenate;