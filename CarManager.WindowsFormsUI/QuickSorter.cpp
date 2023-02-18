#include "QuickSorter.h"
using namespace System;
using namespace CarManagerWindowsFormsUI::OrderProviders;

void QuicSorter::Sort(array<Car^>^ arr, IComparer<Car^>^ comparer)
{
	if (arr == nullptr) {
		throw gcnew ArgumentNullException("arr is null!");
	}

	if (comparer == nullptr) {
		throw gcnew ArgumentNullException("comparer is null!");
	}

	if (arr->Length == 1 || arr->Length == 0) {
		return;
	}

	Sort(arr, 0, arr->Length - 1, comparer);
}

void QuicSorter::Sort(array<Car^>^ arr, int left, int right, IComparer<Car^>^ comparer)
{
	int mid = (left + right) >> 1;

	Car^ pivot = arr[mid];

	int i = 0;
	int j = right;

	while (i <= j)
	{
		while (comparer->Compare(arr[i], pivot) < 0)
		{
			i++;
		}

		while (comparer->Compare(arr[j], pivot) > 0)
		{
			j--;
		}

		if (i <= j)
		{
			Car^ tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	}

	if (left < j)
	{
		Sort(arr, left, j, comparer);
	}

	if (i < right)
	{
		Sort(arr, i, right, comparer);
	}
}
