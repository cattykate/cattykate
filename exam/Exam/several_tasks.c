#include <stdlib.h>
#define SIZE 8

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
//bad!!!!!!!!! only equal number of characters in substrings
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

void swapElem(int arr[]){
	int temp = 0;
	for (int i = 0; i < SIZE; i = i + 2)
	{
		temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
}

void swapMinMax(int arr[]){
	int max = arr[0];
	int min = arr[0];
	int posmin = 0;
	int posmax = 0;
	int temp = 0;

	for (int i = 1; i < SIZE; i++){
		if (arr[i] > max) {
			max = arr[i];
			posmax = i;
		}
	}
	for (int i = 1; i < SIZE; i++){
		if (arr[i] < min) {
			min = arr[i];
			posmin = i;
		}
	}
		temp = arr[posmin];
		arr[posmin] = arr[posmax];
		arr[posmax] = temp;

	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
}

int calculateSum(int arr[]){
	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum = sum + arr[i];
	}
	return sum;
}

int calculateMax(int arr[]){
	int max = arr[0];
	for (int i = 1; i < SIZE; i++){
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int calculateSumPositiveOddInd(int arr[]){
	int sum = 0;
	for (int i = 1; i < SIZE; i = i + 2){
		if (arr[i]>0) {
			sum = sum + arr[i];
		}
	}
	return sum;
}

int main()
{
	int arr[SIZE] = { 3, 2, 1, 5, 6, 7, 4, 8 };

	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	printf("\nResult \n");
	//sortBubble(arr);
	//sortSelection(arr);
	//sortInsertion(arr);
	//swapElem(arr);
	swapMinMax(arr);
	
	char str[SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	char substr[NSIZE] = { 'd', 'e' };
	char newsubstr[NSIZE] = { 'o', 'k' };

	int res = 0;
	//replaceSubstring(str, substr, newsubstr);
	//res = calculateSum(arr);
	//res = calculateSumPositiveOddInd(arr);
	res = calculateMax(arr);
	return 0;
}
