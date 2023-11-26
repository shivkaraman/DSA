#include<bits/stdc++.h>
using namespace std;


void decToBinary(int n){
    string Binary;
    while(n){
        int rem = n%2;
        n /= 2;
        Binary += to_string(rem);
    }
    reverse(Binary.begin(), Binary.end());
    cout << Binary << endl;
}


int main(){
    int n;
    cin>>n;

    //Rsbmask of X = X & (2's comp of X) ie X & X"
    // int rsbMask = (n & ((~n) + 1));
    //Or it is simply X & -X (coz X" = -X)
    int rsbMask = n & -n;
    decToBinary(rsbMask);
}