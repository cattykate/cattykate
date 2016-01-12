#include <stdio.h>

#define SIZE 6

void returnReverseOrder(int arr[], int size);

int main()
{
	const int size = SIZE;
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };
	returnReverseOrder(arr, size);
	return 0;
}

void returnReverseOrder(int arr[], int size)
{
	for (int i = (size - 1); i >= 0; i--){
		printf("%d ", arr[i]);
	}
}
