//Check if a given number is power of 2

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    //If there is only one set bit in a number, then it is a power of 2
    if(n & (n-1) == 0)
        cout << "true" << endl;
    else    
        cout << "false" << endl;
    return 0;
}