//
// Created by cucurbita on 04.10.2023.
//

#include "functions.h"

int is_number(const char* string){
    size_t string_length = strlen(string);
    int i = 0;
    if(string[0] == '-') i = 1;
    for(; i < string_length; i++){
        if(!isdigit(string[i])) return 0;
    }
    return 1;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int* a, int* b){
    if(*a < *b) return -1;
    if(*a == *b) return 0;
    return 1;
}

int find_nearest(int** origin, int length, int value){

    int a = 0;
    int b = length;
    int middle = (a+b)/2;

    while(middle != a && middle != b){

        int difference = abs(value - (*origin)[middle]);
        if(abs(value - (*origin)[middle - 1]) < difference){
            b = middle;
        }else if(abs(value - (*origin)[middle + 1]) < difference){
            a = middle;
        }else{
            return (*origin)[middle];
        }
        middle = (a+b)/2;
    }
    return (*origin)[middle];
}
