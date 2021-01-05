#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Str.h"


int getLine(char s[])
{
	char c = getc(stdin);
	int i = 0;
	while ((i < LINE) && (c != '\n') && (c != EOF))
	{
		s[i] = c;
		c = getc(stdin);
		i++;
	}
	s[i] = c;
	return i;
}

int getWord(char w[])
{
	char c = getc(stdin);
	int i = 0;
	while ((i < WORD) && (c != '\n') && (c != ' ') && (c != '\t') && (c != EOF))
	{
		w[i] = c;
		c = getc(stdin);
		i++;
	}
	w[i] = '\0';
	return i;
}

int substring(char* str1, char* str2)
{
	int lenstr1 = strlen(str1);
	int lenstr2 = strlen(str2);
	if (lenstr1 < lenstr2)
	{
		return 0;
	}
	int i = 0, j = 0;
	while (j < lenstr2 && i < lenstr1)
	{
		if (*(str1 + i) == *(str2 + j))
		{
			i++;
			j++;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = 0;
		}
	}
	if (j == lenstr2) return 1;
	return 0;

}

int similar(char* s, char* t, int n)
{
	if (substring(s, t) == 1 && substring(t, s) == 1 && n == 0) return 1;
	int diffchar = 0;
	int  point_s = 0, point_t = 0;
	int lens = strlen(s);
	int lent = strlen(t);
	if (lens < lent - 1) return 0;
	while (point_s < lens && point_t < lent)
	{
		if (*(t + point_t) != *(s + point_s)) {
			diffchar++;
			point_s++;
		}
		else {
		    point_t++;
			point_s++;
		}
	}
    if (point_s < lens)
			diffchar += lens-point_s ;
	return(diffchar == n);
}

void print_lines(char* str)
{
	int flag = 1;
	while (flag )
	{
		char line[LINE] = { '\0' };
		flag = getLine(line);
		for (int i = 0; i < LINE; i++)
		{
			int j = 0;
			char w[WORD] = { '\0' };
			while ((j < WORD) && (line[i] != '\n') && (line[i] != ' ') && (line[i] != '\t'))
			{
				w[j] = line[i];
				i++;
				j++;
			}
			w[j] = '\0';
			
			if (substring(w,str)==1)
			{
				printf("%s \n", line);
				break;
			}
			if (line[i] == '\n') break;
		}
	}
}

void print_similar_words(char* str)
{
	int flag = 1;
	while (flag)
	{
		char w[WORD] = { '\0' };
		flag = getWord(w);
		if (similar(w, str, 1)==1 || similar(w, str, 0)==1)
		{
			printf("%s \n", w);
		}
	}
}
