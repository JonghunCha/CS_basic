/*
Insertion Sort(삽입 정렬)
- 공간 복잡도 = O(1) = in-place 정렬 (추가로 필요로 하는 공간은 현재 key값을 위한 공간 정도로 배열의 사이즈와 무관)
- 시간 복잡도 = O(n^2) (최악의 경우(역으로 정렬된 상태) 비교하는 탐색이 (n - 1) + (n - 2) ... + (1)번이기 때문이다. 만약 제대로 정렬된 경우 한 번씩 비교를 하기에 n번만 비교하면 된다)
- stable 정렬
*/
#include <stdio.h>

void InsertionSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("기존 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	InsertionSort(arr, 10);
	printf("정렬 후 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	return 0;
}

void InsertionSort(int* arr, int arrlen) {
	int a, b;
	int key, temp;

	for (a = 1; a < arrlen; a++) {
		key = arr[a];
		b = a - 1;
		while (b >= 0 && key < arr[b]) {
			arr[b + 1] = arr[b];
			b--;
		}
		arr[b + 1] = key;
	}
}