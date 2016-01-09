#include <stdio.h>
#include <stdlib.h>


/*
*	SwapInt() : Swaps two integers in place
*	using bitwise operators.
*/
void SwapInt(int *p, int *q)
{
	*p	=	*p	^	*q;
	*q	=	*p	^	*q;
	*p	=	*p	^	*q;
}

/* 
*	Binary Sort Algorithm
*	Runtime: O(Log n)
*/

int BinarySearch(int iArray[],int l,int r,int x)
{
	int mid	=	0;
	if( r >= l)
	{
		mid	=	l + (r - l)/2;

		if(iArray[mid] > x)
		{
			return BinarySearch(iArray,l,mid,x);
		}
		else if (iArray[mid] < x)
		{
			return BinarySearch(iArray,mid+1,r,x);
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

/*
*	Selection Sort Algorithm
*	Running Time: O(n*n)
*/
void SelectionSort(int iArray[], int iSize)
{
	int i	=	0,	j	=	0;
	int small	=	0;
	int pos	=	-1;
	for(i=0;i<iSize;i++)
	{
		small	=	iArray[i];
		for(j=i+1;j<iSize;j++)
		{
			if(small > iArray[j])
			{
				small	=	iArray[j];
				pos		=	j;
			}
		}
		if(pos > -1)
		{
			SwapInt(&iArray[pos],&iArray[i]);
			pos	=	-1;
		}
	}
}

/*
*	Bubble Sort Algorithm
*	Running Time: O(n*n)
*/
void BubbleSort(int iArray[],int iSize)
{
	int i	=	0,	j	=	0;

	for(i=0;i<iSize;i++)
	{
		for(j=i+1;j<iSize;j++)
		{
			if(iArray[i] > iArray[j])
			{
				SwapInt(&iArray[i],&iArray[j]);
			}
		}
	}
}

/*
*	Insertion Sort Algorithm
*	Running Time: O(n * n)
*/
void InsertionSort(int iArray[], int iSize)
{
	int i	=	0,	j	=	0;
	int *iPivot	=	NULL;
	for(i=1;i<iSize;i++)
	{
		iPivot	=	&iArray[i];
		for(j=0;j<i;j++)
		{
			if(*iPivot < iArray[j])
			{
				SwapInt(iPivot,&iArray[j]);
			}
		}
	}
}

/*
*	Merge Sort Algorithm
*	Running Time: O(nLog n)
*/

int main(void)
{
	int n = 0, x = 0, result = 0;
	int arr[] = {12, 23, 14, 160, 40};
	n = sizeof(arr)/ sizeof(arr[0]);
	x = 10;
	InsertionSort(arr,5);
	BubbleSort(arr,5);
	SelectionSort(arr,5);
	result = BinarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}