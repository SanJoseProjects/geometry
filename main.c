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

int sequal(char s1[], char s2[], int j)
{
    int i;
    int flg = 1;
    for (i = 0; flg && s1[i] != '\0' && s2[i + j] != '\0'; i++) {
        if ((s1[i] != s2[i + j] + 0x20) && (s1[i] != s2[i + j] - 0x20)
            && (s1[i] != s2[i + j])) {
            flg = 0;
        }
    }
    return flg;
}

int BegSearch(char* string)
{
    int j = 0;
    while (string[j] == ' ') {
        j++;
    }
    return j;
}

void ErrorOutputCoordinates(char* string)
{
    printf("\n");
    printf("%s\n", string);
    printf("Incorrect input of coordinates...\n");
}

void InputXOfCircle(char* string, int i, int m, Circle* circle)
{
    i = i - m;
    int j = 0;
    char* str;
    char* endStr;
    str = malloc((m + 1) * sizeof(char));
    while ((i < i + m) && (j < m)) {
        if (j < m) {
            *(str + j) = string[i];
            j++;
        }
        i++;
    }
    *(str + m + 1) = '\0';
    circle->centre.x = strtol(str, &endStr, 10);
    free(str);
}

int CheckCircleArguments(char* string, Circle* circle)
{
    int i = 0;
    while (string[i] != '(') {
        i++;
    }
    i++;
    while (string[i] == ' ') {
        i++;
    }
    int m = 0;
    if (string[i] == '-' || (string[i] >= 0x30 && string[i] <= 0x39)) {
        while (string[i] == '-' || (string[i] >= 0x30 && string[i] <= 0x39)) {
            m++;
            i++;
        }
        InputXOfCircle(string, i, m, circle);
    } else {
        ErrorOutputCoordinates(string);
        return 0;
    }
    if (string[i] != ' ') {
        ErrorOutputCoordinates(string);
        return 0;
    }
    while (string[i] == ' ') {
        i++;
    }
    m = 0;
    if (string[i] == '-' || (string[i] >= 0x30 && string[i] <= 0x39)) {
        while (string[i] == '-' || (string[i] >= 0x30 && string[i] <= 0x39)) {
            m++;
            i++;
        }
        InputYOfCircle(string, i, m, circle);
    } else {
        ErrorOutputCoordinates(string);
        return 0;
    }
}

int CheckArgName(char* cstring, Circle* ccircle)
{
    int j = BegSearch(cstring);

    char circle[] = {"circle"};

    int flagc = sequal(circle, cstring, j);

    if (flagc) {
        return CheckCircleArguments(cstring, ccircle);
    } else {
        printf("\n%s\n", cstring);
        printf("Incorrect input name of figure...\n");
        return 0;
    }
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
