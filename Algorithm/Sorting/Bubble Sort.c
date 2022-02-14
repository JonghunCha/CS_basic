/*
Bubble Sort(버블 정렬)
- 공간 복잡도 = O(1) = in-place 정렬 (추가로 필요로 하는 공간은 swap을 위한 공간 정도로 배열의 사이즈와 무관)
- 시간 복잡도 = O(n^2) (첫 for문 부터 마지막 for문까지 비교하는 탐색이 (n - 1) + (n - 2) ... + (1)번이기 때문이다.)
- stable 정렬
*/
#include <stdio.h>

void BubbleSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("기존 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	BubbleSort(arr, 10);
	printf("정렬 후 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	return 0;
}

void BubbleSort(int* arr, int arrlen) {
	int temp;

	for (int a = 0; a < arrlen - 1; a++) {
		for (int b = 1; b < arrlen - a; b++) {
			if (arr[b - 1] > arr[b]) {
				temp = arr[b - 1];
				arr[b - 1] = arr[b];
				arr[b] = temp;
			}
		}
	}
}