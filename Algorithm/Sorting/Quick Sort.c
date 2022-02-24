/*
Quick Sort(�� ����)
- ���� ���⵵ = O(1) = in-place ���� (�߰��� �ʿ�� �ϴ� ������ swap�� ���� ���� ������ �迭�� ������� ����)
- �ð� ���⵵ = O(N*logN) (�Ϲ����� ��� N*logN�̳� ������ pivot�� ��ü �������� �ּ� Ȥ�� �ִ� ���� �����ٸ� ������ ȿ���� ���� ���Ͽ� N^2�� ����� �ð����⵵�� ���� �� �ִ�)
- non-stable ����
*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* arr, int start, int end);

int main() {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("���� �迭 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	QuickSort(arr, 0, 9);
	printf("���� �� �迭 : ");
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