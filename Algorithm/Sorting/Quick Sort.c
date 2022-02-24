/*
Quick Sort(퀵 정렬)
- 공간 복잡도 = O(1) = in-place 정렬 (추가로 필요로 하는 공간은 swap을 위한 공간 정도로 배열의 사이즈와 무관)
- 시간 복잡도 = O(N*logN) (일반적인 경우 N*logN이나 선택한 pivot이 전체 데이터의 최소 혹은 최대 값에 가깝다면 분할의 효과를 받지 못하여 N^2에 가까운 시간복잡도를 가질 수 있다)
- non-stable 정렬
*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* arr, int start, int end);

int main() {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("기존 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	QuickSort(arr, 0, 9);
	printf("정렬 후 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	return 0;
}

void QuickSort(int* arr, int start, int end) {
	if (start >= end)	return;
	
	int pivot = start, a = start + 1, b = end, temp;

	while (a <= b) {
		while (a <= end && arr[a] <= arr[pivot])	a++;
		while (b > start && arr[b] >= arr[pivot])	b--;

		if (a > b) {
			temp = arr[b];
			arr[b] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
	}

	QuickSort(arr, start, b - 1);
	QuickSort(arr, b + 1, end);
}