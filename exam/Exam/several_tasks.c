#include <stdlib.h>
#define SIZE 7

void sortBubble(int arr[], int size){

	int temp = 0;

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (arr[j] < arr[j + 1]){
				temp = arr[j + 1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
}

int main()
{
	const int size = SIZE;
	int arr[SIZE] = { 1, 2, 4, 5, 6, 7, 3 };

	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	printf("\nArray after sort \n");
	sortBubble(arr, size);

	return 0;
}
