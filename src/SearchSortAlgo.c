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
void Merge(int iArray[], int l, int m, int r)
{
    int i,j,k;
    
    int iLArraySize =   m - l + 1;
    int iRArraySize =   r - m;
    
    int *iLArray    =   (int*) malloc(iLArraySize*sizeof(int));
    int *iRArray    =   (int*) malloc(iRArraySize*sizeof(int));
    
    for(i=0;i<iLArraySize;i++)
        iLArray[i] = iArray[l+i];
    
    for(j=0;j<iRArraySize;j++)
        iRArray[j] = iArray[m+1+j];
    
    i = j = k = 0;
    
    k=  l;
    while (i< iLArraySize && j < iRArraySize)
    {
        if(iLArray[i] <= iRArray[j])
        {
            iArray[k] = iLArray[i];
            i++;
        }
        else
        {
            iArray[k] = iRArray[j];
            j++;
        }
        k++;
    }
    
    while(i < iLArraySize)
    {
        iArray[k] = iLArray[i];
        k++;
        i++;
    }
    
    
    
    while(j < iRArraySize)
    {
        iArray[k] = iRArray[j];
        k++;
        j++;
    }
    
    
    free(iRArray);
    free(iLArray);
}


void MergeSort(int iArray[], int iLeft, int iRight)
{
    int iMiddle;
    
    if(iLeft < iRight)
    {
        iMiddle = (iLeft + (iRight- iLeft)/2);
        MergeSort(iArray,iLeft,iMiddle);
        MergeSort(iArray,iMiddle+1,iRight);
        Merge(iArray,iLeft,iMiddle,iRight);
    }
    
}

/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void Search_Driver()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given array is \n");
    printArray(arr, arr_size);
    
    MergeSort(arr, 0, arr_size - 1);
    
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    
}