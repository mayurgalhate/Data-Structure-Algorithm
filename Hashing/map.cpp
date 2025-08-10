#include<iostream>
#include<map>
using namespace std;


int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int arr[n];
    //pre compute 
    map<int ,int> mpp;
    for(int i = 0; i < n; i++) {
        cout << "enter element :";
        cin >> arr[i];
        mpp[arr[i]]++;
    }  

    for(auto it: mpp) {
        cout << it.first << " -> " << it.second << endl;
    }  
    
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    while(q--) {
        int number;
        cout << "Enter the element to query: ";
        cin >> number;

        //fetch
        cout << mpp[number] << endl;
    }

    return 0;
}