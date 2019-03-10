#include <iostream>

int* merge(int* arr1, int* arr2, int count1, int count2)
{
	int merge[50];
	int j = 0;
	int k = 0;

	for (size_t i = 0; i < count1 + count2; i++)
	{
		if (j >= count1)
		{
			merge[i] = arr1[k++];
			continue;
		}
		else if (k >= count2)
		{
			merge[i] = arr2[j++];
			continue;
		}

		if (arr1[j] < arr2[k])
		{
			merge[i] = arr1[j++];
		}
		else// (arr1[i] < arr2[k])
		{
			merge[i] = arr2[k++];
		}
	}
	return merge;
}

int* mergeSort(int* arr, int count, int start = 0)
{
	if (count < 2)
	{
		return arr;
	}
	else
	{
		arr = &arr[start];

		return merge(
			mergeSort(arr, count / 2, count / 2 + 1),
			mergeSort(arr, count / 2, 0),
			count / 2,
			(count+1) / 2);
	}
}


int main()
{
	int size1 = 8;
	int arr[] = { 3,5,6,7,4,2,1,1 };
	/*
	std::cout << "Enter Array 1 Size : ";
	std::cin >> size1;
	std::cout << "Enter Array 1 Elements : ";
	for (int i = 0; i < size1; i++)
	{
		std::cin >> arr[i];
	}
	*/

	int* out = mergeSort(arr, size1);

	for (size_t i = 0; i < size1; i++)
	{
		std::cout << out[i] << std::endl;
	}
	while (true) {}
}
