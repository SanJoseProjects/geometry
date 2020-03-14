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

int BegSearch(char* string)
{
    int j = 0;
    while (string[j] == ' ') {
        j++;
    }
    return j;
}

int CheckArgName(char* cstring, Circle* ccircle)
{
    int j = BegSearch(cstring);

    char circle[] = {"circle"};
}

int main()
{
    Circle circle;
    char string[100];
    printf("Input circle and his parametres: \n");
    fgets(string, 100 - 1, stdin);
    int check = CheckArgName(string, &circle);

    return 0;
}
