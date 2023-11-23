//
// Created by cucurbita on 22.11.2023.
//

#include "tree.h"
#include "functions.h"

int get_string(FILE* stream, char** string, int* length, const char* separators)
{
    *length = 0;
    int capacity = 1;
    char* for_realloc;
    int c = fgetc(stream);
    *string = (char*)malloc(sizeof(char)*1);
    if(*string == NULL) return memory_error;
    size_t sep_amount = strlen(separators);
    int word_ended = 0;
    while(c != EOF)
    {
        for(int i = 0; i < sep_amount; i++) if(c == separators[i])
        {
            (*string)[*length] = '\0';
            if(c == ' ') return space_reached;
            if (c == EOF) return eof_reached;
            if (c == '\n') return newline_reached;
            if (c == '\0') return endl_reached;
        }
        (*string)[(*length)++] = c;
        if(*length >= capacity)
        {
            capacity *= 2;
            for_realloc = realloc(*string, capacity * sizeof(char));
            if(for_realloc == NULL)
            {
                free(*string);
                return memory_error;
            }
            *string = for_realloc;
        }
        c = fgetc(stream);
    }
    (*string)[*length] = '\0';

    return success;
}

int read_from_file(FILE* stream, struct Node* head, char* separators)
{
    while(!feof(stream))
    {
        char* string;
        int length;
        if(get_string(stream, &string, &length, separators) == memory_error) return memory_error;
        if(length != 0) insert(head, string);
    }

    return success;
}

int get_cmd_code(const char* command)
{
    if(!strcmp(command, "find")) return find;
    if(!strcmp(command, "common")) return common;
    if(!strcmp(command, "shortest")) return shortest;
    if(!strcmp(command, "longest")) return longest;
    if(!strcmp(command, "print")) return print;
    if(!strcmp(command, "quit")) return quit;
    return unknown;
}

int is_number(const char* string)
{
    size_t string_length = strlen(string);
    for(int i = 0; i < string_length; i++){
        if(!isdigit(string[i])) return 0;
    }
    return 1;
}