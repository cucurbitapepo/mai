//
// Created by cucurbita on 13.10.2023.
//

#ifndef LAB_2_1_FUNCTIONS_H
#define LAB_2_1_FUNCTIONS_H

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

enum exit_codes
{
    memory_error,
    success,
};

int check_flag(char** word);
int string_length(char** str);
int reverse_str(char** string, char** result);
int odd_to_upper(char** origin, char** result);
int rearrange_string(char** result, char** origin);

int compare(void const* a, void const* b);



#endif //LAB_2_1_FUNCTIONS_H
