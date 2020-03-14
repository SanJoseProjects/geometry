#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int x;
    long int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
} Triangle;

typedef struct {
    Point centre;
    long int radius;
} Circle;

int main()
{
    Circle circle;
    char string[100];
    printf("Input circle and his parametres: \n");
    fgets(string, 100 - 1, stdin);

    return 0;
}
