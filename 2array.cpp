#include <iostream>
using namespace std;

// reverse array

void revArray(int arr[], int size)
{

    for (int s = 0, e = size - 1; s <= e; s++, e--)
    {
        swap(arr[s], arr[e]);
    }
}
// print array via function

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
}

// maximum element in array using pre-defined function

int maxi(int arr[], int size)
{

    int maxi = arr[0];
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

// minimum element in array using pre-defined function

int mini(int arr[], int size)
{

    int mini = arr[0];
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

// linear search in array--search element one by one in array
//TimeComplexity= O(n)
//use in non sorted array

int linearSearch(int arr[], int key, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[5] = {12, 6, 4, 5, 7};
    printArray(arr, 5);
    cout << endl;

    revArray(arr, 5);

    printArray(arr, 5);

    int key;

    cout << endl;

    cout << "max-->" << maxi(arr, 5) << endl;
    cout << "min-->" << mini(arr, 5) << endl;

    cout << linearSearch(arr, 7, 5) << endl;

    cout << linearSearch(arr, 454, 5) << endl;

    return 0;
}