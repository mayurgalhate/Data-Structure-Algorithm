#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
void printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[6] = {22, 20, 18, 154, 100, 2};
    insertionSort(arr, 6);
    printarray(arr, 6);

    return 0;
}