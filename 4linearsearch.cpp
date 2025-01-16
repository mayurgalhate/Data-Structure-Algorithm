#include<iostream>
using namespace std;
//recursive 
void print(int arr[], int size){
    for (int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}
int linearSearch(int arr[],int size,int key){
    print(arr,size);

    if(size==0)
    return -1;

    if(arr[size-1]==key)
    return size-1;

    else
    return linearSearch(arr+1,size-1,key);
}

int main(){
    int arr[6]={ 5, 16, 67, 45, 46,78};
    int key=78;
      int ans=linearSearch(arr,6,key);

      if(ans==-1)
      cout<<"not";
      else
      cout<<"yes - index : "<<ans;

    return 0;
}