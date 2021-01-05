#include <stdio.h>
#include "Str.h"

int main()
{
    char word[WORD] = { '\0' };
    char op = { '\0' };
    if (!getWord(word)) printf("Error");
    char choice = getc(stdin);
    while ((choice != '\n'))
    {
        if (choice == 'a') op = 'a';
        if (choice == 'b') op = 'b';
        choice = getc(stdin);
    }
    char first[1];
    if (getLine(first)!=0) printf("Error");

    switch (op) {
    case 'a':
        print_lines(word);
        break;
    case 'b':
        print_similar_words(word);
        break;
    default:
        printf("invalid input");
    }
    return 0;
}
