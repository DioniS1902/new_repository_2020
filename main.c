#include <stdio.h>
#define n 10

int dominant(int arr[n]) {
	int help = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = help; j < n; j++)
		{
			if (arr[i] < arr[j]) {
				int k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}
		help += 1;
	}
	int count = 0, number = 0, corrct_count = 0, corrct_number = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (corrct_number == arr[i]) {
			corrct_count += 1;
		}
		else
		{
			corrct_number = arr[i];
			if (count < corrct_count) {
				count = corrct_count, number = arr[i - 1];
			}
			corrct_count = 1;
		}
	}
	if (count > n / 2) {
		return number;
	}
	else
	{
		return -1;
	}
}


void main() {
	int arr[n] = {3,3, 4, 3, 2, 3, 1, 3, 3,10};
	printf("%d",dominant(arr));
}