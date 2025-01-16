#include<iostream>
using namespace std;
void selectionSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int minindex=i;
        for (int j = i+1 ; j < size; j++)
        {
           
            if(arr[j] < arr[minindex]);
             minindex=j;
        }
        swap(arr[minindex],arr[i]);
        
    }
    
}
void printArr(int arr[],int size){

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl ;
    
}

int main(){

    int arr[6]={5,89,25,46,2,1};
    printArr(arr,6);
    selectionSort(arr,6);
    printArr(arr,6);
    return 0;
}