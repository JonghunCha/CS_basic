/*
Bubble Sort(���� ����)
- ���� ���⵵ = O(1) = in-place ���� (�߰��� �ʿ�� �ϴ� ������ swap�� ���� ���� ������ �迭�� ������� ����)
- �ð� ���⵵ = O(n^2) (ù for�� ���� ������ for������ ���ϴ� Ž���� (n - 1) + (n - 2) ... + (1)���̱� �����̴�.)
- stable ����
*/
#include <stdio.h>

void BubbleSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("���� �迭 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	BubbleSort(arr, 10);
	printf("���� �� �迭 : ");
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