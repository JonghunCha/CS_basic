/*
Insertion Sort(���� ����)
- ���� ���⵵ = O(1) = in-place ���� (�߰��� �ʿ�� �ϴ� ������ ���� key���� ���� ���� ������ �迭�� ������� ����)
- �ð� ���⵵ = O(n^2) (�־��� ���(������ ���ĵ� ����) ���ϴ� Ž���� (n - 1) + (n - 2) ... + (1)���̱� �����̴�. ���� ����� ���ĵ� ��� �� ���� �񱳸� �ϱ⿡ n���� ���ϸ� �ȴ�)
- stable ����
*/
#include <stdio.h>

void InsertionSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("���� �迭 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	InsertionSort(arr, 10);
	printf("���� �� �迭 : ");
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