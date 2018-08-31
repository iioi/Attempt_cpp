#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void QuickSort(int R[], int low, int high) {
	if (low >= high)
		return;
	int i = low, j = high, tmp = R[i];
	while (i < j)
	{
		while (i < j && R[j] >= tmp) j--;
		if (i < j) {
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i] < tmp)	i++;
		if (i < j) {
			R[j] = R[i];
			j--;
		}
	}
	R[i] = tmp;
	QuickSort(R, low, i - 1);
	QuickSort(R, i + 1, high);
}

int main() {
	int R[] = {23,12,22,34,21,19,33};
	QuickSort(R, 0, 6);
	for (int i = 0; i < 7; i++)
		cout << R[i] << " ";
	getchar();
	return 0;
}