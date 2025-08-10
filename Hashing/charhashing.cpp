#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    //pre compute
    int hash[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        // hash[s[i] - 'a']++;
        hash[s[i]]++;
    }
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while(q--) {
        char c;
        cout << "Enter the character :";
        cin >> c;
        //fetch
        // cout << hash[c - 'a'] << endl;
         cout << hash[c] << endl;
    }
    return 0;
}