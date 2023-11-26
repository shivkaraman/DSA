
#include <iostream>
#include <map>
using namespace std;

int main(){
    /*
    Maps
        Insert -> O(log n)
        Delete -> O(log n)
        Access -> O(log n)
        find/Search -> O(log n)
    UNordered Map
        Insert -> O(1)
        Delete -> O(n)
        Access -> O(1)
        find/Search -> O(1)

    */
    map <int, string> HT;
    HT.emplace(10, "abc");
    HT.insert({20, "xyz"});
    HT[50] = "lmn";
    HT[6]; // --> This creates an object of {6, ""}
    for(auto &p : HT){
        cout << p.first << "->" << p.second << endl;
    }

    auto it = HT.find(20); //Returns an iterator to key 20( or end if 20 doesnto exist)
    HT.erase(20);           //Removes 20
    
    for(auto &p : HT){
        cout << p.first << "->" << p.second << endl;
    }
    return 0;
}