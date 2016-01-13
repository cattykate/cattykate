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

void sortSelection(int arr[], int size){

	int pos = 0;
	int min = 0;
	
	for (int j = 0; j < SIZE; j++){
		pos = j;
		min = arr[j];

		for (int i = j+1; i < SIZE; i++){
			if (arr[i] < min)
			{
				pos = i;
				min = arr[i];
			}
		}
		arr[pos] = arr[j];
		arr[j] = min;
	}
	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
}

void sortInsertion(int arr[], int size) {
	int temp = 0;
	for (int i = 1; i < SIZE; i++) {
		for (int j = i; j>0 && arr[j - 1]>arr[j]; j--) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
}


int main()
{
	const int size = SIZE;
	int arr[SIZE] = { 3, 2, 4, 5, 6, 7, 1 };

	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	printf("\nArray after sort \n");
	//sortBubble(arr, size);
	//sortSelection(arr, size);
	sortInsertion(arr, size);

	return 0;
}
