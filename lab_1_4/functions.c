//
// Created by cucurbita on 30.09.2023.
//

#include "functions.h"

int exclude_arabic_digits(FILE** origin, FILE** destination){
    int c;
    while((c = fgetc(*origin)) != EOF){
        if(c >= '0' && c <= '9'){
            continue;
        }
        if(fputc(c, *destination) == EOF) return 0;
    }
    return 1;
}

int count_latin_letters(FILE** origin, FILE** destination){
    int c = '1';
    int counter = 0;
    while(c != EOF){
        c = fgetc(*origin);
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            counter++;
        }else if(c == '\n' || c == EOF){
            if(!fprintf(*destination, "%d\n", counter)) return 0;
            counter = 0;
        }
    }
    return 1;
}

int count_non_latin_arabic(FILE** origin, FILE** destination){
    int c = '1';
    int counter = 0;
    while(c != EOF){
        c = fgetc(*origin);
        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || (c >= '0' && c <= '9')) && c != '\n' && c != EOF) {
            counter++;
        }else if(c == '\n' || c == EOF){
            if(!fprintf(*destination, "%d\n", counter)) return 0;
            counter = 0;
        }
    }
    return 1;
}

int swap_with_ascii16(FILE** origin, FILE** destination){
    int c;
    while((c = fgetc(*origin)) != EOF){
        if(!(c >= '0' && c <= '9')){
            if(c == '\n' || c == EOF) {
                fprintf(*destination, "\n");
            }else{
                fprintf(*destination, "%X", c);
            }
        }else{
            fprintf(*destination, "%c", c);
        }
    }
    return 1;
}

int find_dash(char** path, size_t length){
    for(int i = length; i >= 0; i--){
        if((*path)[i] == '\\'){
            return i;
        }
    }
    return 0;
}

int check_flag(char** word){
    size_t length = strlen(*word);
    if(((*word)[0] != '-' && (*word)[0] != '/')) return 0;
    if(length == 3 && (*word)[1] != 'n') return 0;
    return 1;
}