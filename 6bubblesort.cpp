#include <iostream>
using namespace std;
int bubblesort(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
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

    int arr[6] = {22, 20, 19, 188, 10, 2};
    bubblesort(arr, 6);
    printarray(arr, 6);
    return 0;
}