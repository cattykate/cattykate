#include <stdlib.h>
#define SIZE 7

void sortBubble(int arr[]){

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

void sortSelection(int arr[]){

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

void sortInsertion(int arr[]) {
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


#define NSIZE 2

void replaceSubstring(char str[], char substr[], char newsubstr[]){
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NSIZE; j++){
			if (str[i] == substr[j] && str[i + 1] == substr[j + 1]){
				str[i] = newsubstr[j];
				str[i + 1] = newsubstr[j + 1];
			}
		}
	}
	for (int i = 0; i < SIZE; i++){
		printf("%c ", str[i]);
	}
}

int main()
{
	int arr[SIZE] = { 3, 2, 4, 5, 6, 7, 1 };

	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	printf("\nResult \n");
	sortBubble(arr);
	//sortSelection(arr);
	//sortInsertion(arr);

	char str[SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	char substr[NSIZE] = { 'd', 'e' };
	char newsubstr[NSIZE] = { 'o', 'k' };


	printf("\nResult \n");
	replaceSubstring(str, substr, newsubstr);


	return 0;
}
