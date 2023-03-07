#include <stdio.h>

int main()
{
    double x = 1234567890.123;
    double y = 12345.123;
    double a = x/y;
    double b = x/y;

    if (a == b)
        puts("iguais");
    else
        puts("diferentes");

    printf("%.10f \n%.10f\n", a, b);
    
    return 0;
}