#include "functions.h"

int main(int argc, char** argv) {
    if(argc != 3){
        printf("\nWrong amount of arguments given. Exiting.\n");
        return 1;
    }
    if(!is_number(argv[1])){
        printf("\n\"%s\" is not a number. Exiting.\n", argv[1]);
        return 1;
    }
    int flag;
    int given_number;
    flag = define_flag(argv[2]);
    given_number = atoi(argv[1]);

    switch(flag){
        case 0:
        {
            int* array_of_numbers;
            int count;
            multiples(given_number, &array_of_numbers, &count);

            if(array_of_numbers){
                printf("Numbers that are multiples for %d are: ", given_number);
                for(int i = 0; i < count; i++){
                    printf("%d ",array_of_numbers[i]);
                }
                free(array_of_numbers);
                return 0;
            }else{
                if(count == -1){
                    printf("Internal Error.\n");
                    free(array_of_numbers);
                    return 1;
                }
                if(count == 0){
                    printf("Given number is more than 100.\n");
                    free(array_of_numbers);
                    return 0;
                }
            }
        }
        case 1:
        {
            (is_prime(given_number)) ? printf("%d is a prime number.\n", given_number) : printf("%d is a composite number.\n", given_number);
        }
        case 2:
        {
            char* digits_reversed;
            int length;
            split_number(given_number, &digits_reversed, &length);

            if(length == -1){
                printf("Internal Error.\n");
                free(digits_reversed);
                return 1;
            }
            printf("%d split looks like this: ", given_number);
            for(int i = length-1; i >= 0; i--){
                printf("%d ", digits_reversed[i]);
            }
            free(digits_reversed);
            return 0;
        }
        case 3:
        {
            long long int** table;
            system("chcp 65001");
            create_table_of_powers(given_number, &table);
            if(table == NULL){
                printf("Internal Error.\n");
                free(table);
                return 1;
            }
            print_table_of_powers(given_number, &table);
            for(int i = 0; i < given_number; i++){
                free(table[i]);
            }
            free(table);
            return 0;
        }
        case 4:
        {
            printf("Sum of all natural numbers from 1 to %d is %d", given_number, (1+given_number)*given_number/2);
            return 0;
        }
        case 5:
        {
            char* result;
            size_t length;
            factorial(given_number, &result, &length);

            if(result == NULL){
                printf("Internal Error.\n");
                return 1;
            }

            for(int i = (int)length - 1; i >= 0; i--){
                printf("%c", result[i]);
            }
            free(result);
            return 0;
        }
        default:
        {
            printf("Unknown flag: %s",argv[2]);
            return 0;
        }
    }
}