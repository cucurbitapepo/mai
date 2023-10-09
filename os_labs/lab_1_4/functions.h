//
// Created by cucurbita on 08.10.2023.
//

#ifndef LAB_1_4_FUNCTIONS_H
#define LAB_1_4_FUNCTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum exit_codes
{
    not_a_number = -1,
    success,
};

enum flags
{
    _xor8,
    _xor32,
    _mask,
    _invalid_flag,
};

int to_decimal(char** string, int length, int base, int* sign);
int define_flag(char** string);


unsigned int xor8(FILE* file);
unsigned int xor32(FILE* file);
size_t mask(FILE* file, unsigned int hex);

#endif //LAB_1_4_FUNCTIONS_H
