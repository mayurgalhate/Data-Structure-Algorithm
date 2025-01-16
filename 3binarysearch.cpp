#include<iostream>
using namespace std;
/*
Itreative

int binarySearch(int arr[] , int key , int size){
     int s=0 , e = size-1 ;
     int mid = s+(e-s)/2 ;
    
    while(s<=e){
        
        if(arr[mid]==key){
        return mid;
        }

         if(arr[mid]<key){
            return s=mid+1;
         }
        

        else{
            return e=mid-1;
        }
        
    }
    
}
*/
void printarray(int arr[],int s,int e){

    for (int i = s; i <=e; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
// Recursive 
int recbinarySearch(int arr[] , int s , int e ,int key){
    printarray( arr,s,e);
     if(s<=e){
    int mid=s+(e-s)/2;
        if(arr[mid]==key)
        return mid;
         if(arr[mid]<key)
        return recbinarySearch(arr,mid+1,e,key);
       else
        return recbinarySearch(arr,s,mid-1,key);
     }
    
    return (-1);
}

int main(){
     
     int arr[6]={2, 3, 4, 10, 40 ,50 };
     
     int key=2;
     int size=6;
     
    cout<<recbinarySearch(arr,0,size-1,key);
    return 0;
}

//TimeComplexity= O(logn)
//use in sorted ass-dec-array 
// use when elements are in monotonic or monotonus function i.e elements are in incre or decre order