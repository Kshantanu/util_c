//
//  SearchSortAlgo.h
//  util_package
//
//  Created by Shantanu Konwar on 11/01/16.
//  Copyright © 2016 Shantanu Konwar. All rights reserved.
//

#ifndef SearchSortAlgo_h
#define SearchSortAlgo_h


void SwapInt(int *p, int *q);
int BinarySearch(int iArray[],int l,int r,int x);
void SelectionSort(int iArray[], int iSize);
void BubbleSort(int iArray[],int iSize);
void InsertionSort(int iArray[], int iSize);



//#ifdef IOS_ENVIRONMENT
int main_search();
//#endif

#endif /* SearchSortAlgo_h */
