/*
Merge Sort(합병 정렬)
- 공간 복잡도 = O(N) = not-in-place 정렬 (정렬할 배열과 같은 크기의 공간을 필요로 함)
- 시간 복잡도 = O(N*logN) (분할 및 합병의 과정 수가 logN개, 합병의 각 과정에서 비교 연산이 N번씩 일어난다)
- stable 정렬
*/
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int* arr, int start, int end, int arrlen);
void Merge(int* arr, int start, int middle, int end, int arrlen);

int main() {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("기존 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	MergeSort(arr, 0, 9, 10);
	printf("정렬 후 배열 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	return 0;
}

void MergeSort(int* arr, int start, int end, int arrlen) {
	int middle;

	if (start < end) {
		middle = (start + end) / 2;
		MergeSort(arr, start, middle, arrlen);
		MergeSort(arr, middle + 1, end, arrlen);
		Merge(arr, start, middle, end, arrlen);
	}
}

void Merge(int* arr, int start, int middle, int end, int arrlen) {
	int idx1 = start, idx2 = middle + 1, idx_total = start;
	int *temp = malloc(sizeof(int) * arrlen);

	while (idx1 <= middle && idx2 <= end) {
		if (arr[idx1] <= arr[idx2])	temp[idx_total++] = arr[idx1++];
		else	temp[idx_total++] = arr[idx2++];
	}
	while (idx1 <= middle)	temp[idx_total++] = arr[idx1++];
	while (idx2 <= end)	temp[idx_total++] = arr[idx2++];

	for (int a = start; a <= end; a++)	arr[a] = temp[a];

	free(temp);
}