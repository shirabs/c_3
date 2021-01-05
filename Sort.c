#include "Sort.h"

void shift_element(int* arr, int i)
{
	while (i > 0) {
		
		*(arr + i ) = *(arr + i-1);
		i--;
	}
}

void insertion_sort(int* arr, int len) 
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
			while (*(arr + i) < *(arr + j-1)&&j>0){
				j--;
		}
		int val2move = *(arr + i);	
		shift_element(arr + j, i - j);
		*(arr + j) = val2move;
    }

}
