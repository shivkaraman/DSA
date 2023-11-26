//Union of two sorted arrays


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector < int > UnionOfArray(vector < int > a, vector < int > b) {
    int i1 = 0, i2 = 0;
    int n1 = a.size(), n2 = b.size();
    vector<int> un;
    while(i1 < n1 && i2 < n2){
        if(a[i1] < b[i2])
            un.push_back(a[i1++]);
        else if (a[i1] > b[i2])
            un.push_back(b[i2]++);
        else{
            un.push_back(a[i1]);
            i1++;
            i2++;
        }
    }
    while(i1 < n1) un.push_back(a[i1++]);
    while(i2 < n2) un.push_back(b[i2]++);

    return un;
}

int main(){
    int n1, n2;
    cin >> n1;

    vector<int> a(n1);
    for(int i = 0; i < n1; i++) cin >> a[i];

    cin >> n2;
    vector<int> b(n2);
    for(int i = 0; i < n2; i++) cin >> b[i];

    vector<int> Union = UnionOfArray(a, b);
    for(int num : Union) cout << num << " ";
    return 0;
}