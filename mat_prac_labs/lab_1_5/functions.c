//
// Created by cucurbita on 04.10.2023.
//

#include "functions.h"

double binary_power(double base, unsigned long long exponent){
    double v = 1.0;
    while(exponent){
        if(exponent & 1){
            v *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return v;
}

double task_a(double x, double epsilon){
    double result = 1.0;
    if(x == 0.0){
        return result;
    }
    double result_next = x + result;

    int n = 1;
    while(fabs(result_next - result) > epsilon){
        n++;
        result = result_next;
        result_next = result_next * x / n;
    }
    return result_next;
}
