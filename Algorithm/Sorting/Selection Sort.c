/*
Selection Sort(선택 정렬)
- 공간 복잡도 = O(1) = in-place 정렬 (추가로 필요로 하는 공간은 swap을 위한 공간 정도로 배열의 사이즈와 무관)
- 시간 복잡도 = O(n^2) (비교하는 탐색이 (n - 1) + (n - 2) ... + (1)번이기 때문)
- non-stable 정렬 (ex.(5, 5, 1)을 selection sort로 정렬한다고 생각해보자)
*/
#include <stdio.h>

void selectionSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("기존 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	selectionSort(arr, 10);
	printf("정렬 후 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	return 0;
}

void selectionSort(int* arr, int arrlen) {
	int a, b;
	int candidate, temp;

	for (a = 0; a < arrlen - 1; a++) {
		candidate = a;
		for (b = a + 1; b < arrlen; b++) {	
			if (arr[b] < arr[candidate])	candidate = b;
		}
		temp = arr[candidate];
		arr[candidate] = arr[a];
		arr[a] = temp;
	}
}