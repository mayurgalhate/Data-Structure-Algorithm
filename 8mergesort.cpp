#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{

    int mid = (s + e) / 2;

    // find lenght of left part and right part

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create 2 array for left and right part

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayindex++];
    }
    mainArrayindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayindex++];
    }
    // merge two sorted array logic

    int index1 = 0, index2 = 0;
    mainArrayindex = s;


    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayindex++] = first[index1++];
        }
        else
        {
            arr[mainArrayindex++] = second[index2++];
            
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayindex++] = second[index2++];
    }
}

void mergeSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
        return;

    // find mid
    int mid = (s + e) / 2;

    // left part sorting
    mergeSort(arr, s, mid);

    // right part sorting
    mergeSort(arr, mid + 1, e);

    // merge array
    merge(arr, s, e);
}

int main()
{

    int arr[11] = {45, 84, 4, 1, 1, 654, 7, 24, 9, 22, 2};

    int n = 11;

    mergeSort(arr, 0, n - 1);

    //print array
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}