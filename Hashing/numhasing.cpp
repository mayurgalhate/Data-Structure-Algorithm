#include <iostream>
using namespace std;

int main() {
  int n;
 cout << "Enter a number: ";
cin >> n;
int arr[n];
 cout << "Enter element: ";
for(int i=0; i<n; i++){
   
    cin >> arr[i];
}

//pre compute
int hash[13] = {0}; 
 for(int i=0; i<n; i++){
 
    hash[arr[i]]++;
 }
int q;
cout << "Enter the number of queries: ";
cin >> q;
cout << "Enter the element to query: ";
while(q--) {
int number;

cin >> number;
//fetch
cout << hash[number] << endl;
}
return 0;
}
