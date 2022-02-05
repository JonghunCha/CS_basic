/*
Selection Sort(���� ����)
- ���� ���⵵ = O(1) = in-place ���� (�߰��� �ʿ�� �ϴ� ������ swap�� ���� ���� ������ �迭�� ������� ����)
- �ð� ���⵵ = O(n^2) (���ϴ� Ž���� (n - 1) + (n - 2) ... + (1)���̱� ����)
- non-stable ���� (ex.(5, 5, 1)�� selection sort�� �����Ѵٰ� �����غ���)
*/
#include <stdio.h>

void selectionSort(int* arr, int arrlen);

int main(void) {
	int a;
	int arr[10] = { 8, 9, 1, 6, 4, 3, 5, 10, 2, 7 };

	printf("���� �迭 : ");
	for (a = 0; a < 10; a++)	printf("%d ", arr[a]);
	printf("\n");

	selectionSort(arr, 10);
	printf("���� �� �迭 : ");
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