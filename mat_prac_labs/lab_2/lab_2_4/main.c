#include "functions.h"
#define VERTEX_AMOUNT 4
#define VALUE 2.718281828
#define DEGREE 1

int main() {
    int _convex = is_convex(VERTEX_AMOUNT, (point_2d){1, 1}, (point_2d){1,1}, (point_2d){1,1}, (point_2d){1,1});
    if(_convex == memory_error)
    {
        printf("memory_error\n");
        return 1;
    }
    printf("%s\n", _convex == convex ? "convex" : "concave" );


    double poly = polynomial(VALUE, DEGREE, VALUE);
    printf("%lf\n", poly);
    return 0;
}
