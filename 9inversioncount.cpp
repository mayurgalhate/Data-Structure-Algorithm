#include <iostream>
using namespace std;

int mergeandCount(int *arr, int s, int e)
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

    int index1 = 0, index2 = 0, invCount=0;;
   
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

            //inversion count
            invCount += (len1 - index1); //because.....a[idx1]>b[idx2]
            
        }
    }
    while (index1 < len1)
    
        arr[mainArrayindex++] = first[index1++];
    
    while (index2 < len2)
    
        arr[mainArrayindex++] = second[index2++];
    
    return invCount;
}

int mergeSortandCount(int *arr, int s, int e)
{
    
    // // base case
    // if (s >= e)
    //     return;
    int invCount=0;
    if(s<e){
    // find mid
    int mid = (s + e) / 2;


    // left part sorting
   invCount += mergeSortandCount(arr, s, mid);

    // right part sorting
    invCount += mergeSortandCount(arr, mid + 1, e);

    // merge array
    invCount += mergeandCount(arr, s, e);
    }
    return invCount;
}

int main()
{

    int arr[4] = {4,3,2,1};

    int n = 4;

    cout << " C O U N T --> " << mergeSortandCount(arr, 0, n-1 ) << endl;

    
    return 0;
}