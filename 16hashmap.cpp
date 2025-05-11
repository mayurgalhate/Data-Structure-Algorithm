#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){

    // creation 
    map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("Mayur", 7);
    m.insert(p);

    //2
    pair<string, int> pair2("myself", 8);
    m.insert(pair2);

    //3
    m["me"] = 1;

    //what will happen? updation wil happen
    m["me"] = 2;

    //Search
cout << m["me"] << endl;
cout << m.at("Mayur") << endl;
cout << m.at("myself") << endl;
cout << m["unknown"] << endl;
cout << m.at("unknown") << endl;

//size

cout << m.size() << endl;

//to check presence give O/P -> 0/1
cout << m.count("hello") << endl;

//erase
m.erase("Mayur");
cout << m.size() << endl;

//1
// for(auto i:m){
//     cout << i.first << " " << i.second << " " << endl;
// }

//2. iterator
map<string, int>::iterator it = m.begin();
while(it != m.end()){
    cout << it->first << " " << it->second  << endl;
     it++;
}  

    return 0;
}