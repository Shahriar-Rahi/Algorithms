#include<bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

void insertionSort(int *arr, int n);
int partition(int *arr, int start, int end);
void quickSort(int arr[], int start, int end);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
int main(){
	int size;
	cout << "Size of array: " << endl;
	cin >> size;
	int array[size];
	srand((unsigned)time(0));
	for(int i=0; i<size; i++)
   		array[i] = rand();
   	
   	int start_t =clock();
	insertionSort(array, size);
	int stop_t =clock();
	cout << "Execution time for insertion sort: " << (stop_t-start_t)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	int start_s =clock();
	quickSort(array, 0, size);
	int stop_s =clock();
	cout << "Execution time for quick sort: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	int start_m =clock();
	heapSort(array, size);
	int stop_m =clock();
	cout << "Execution time for heap sort: " << (stop_m-start_m)/double(CLOCKS_PER_SEC)*1000 << endl;
	
   	
	return 0;
}

void insertionSort(int *arr, int n){
	int value, hole;
	for(int i=1; i<n; i++){
		value = arr[i];
		hole = i;
		while(hole > 1 && arr[hole-1] > value){
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole] = value;
	}
}

int partition(int* arr, int start, int end){
	int pivot = arr[end];
	int pIndex = start;
	for(int i = start; i < end; i++){
		if(arr[i] <= pivot){
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}	
	swap(arr[pIndex], arr[end]);
	return pIndex;
}

void quickSort(int *arr, int start, int end){
	if(start < end){
		int pIndex = partition(arr, start, end);
		quickSort(arr, start, pIndex-1);
		quickSort(arr, pIndex+1, end);
	}
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
