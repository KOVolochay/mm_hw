#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //printf("%d", 1/3);
    //printf("Result=%20.15f\n", ((pow(sin(1.28)*sin(1.28) + 1, (1.0/3)) - 26 + atan(1.17 + 2.95))/(pow((2.01 - cos(3.68)*cos(3.68)), 5.84) + 25.362)));
    double x = 10;
    printf("%7s", "ARG");
    printf("%17s\n", "VALUE");
    printf("%7.3f", x);
    printf("%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf("%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    x += 0.5;
    printf("%7.3f", x);
    printf( "%17.12f\n", sin(x*x)*log(x));
    return EXIT_SUCCESS;
}
