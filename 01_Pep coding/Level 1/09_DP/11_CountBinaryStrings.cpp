/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.

Sample Input
6

Sample Output
21
*/


#include <iostream>
using namespace std;
/*
Now we start a new type of problems -> Include and not include
Storage-> 2 1D arrays
Meaning-> arr1[i]-> Stores the no of binary strings of  length i that have no repetetive 0's and //* end with 0 
          arr2[i]-> Stores the no of binary strings of  length i that have no repetetive 0's and //* end with 1
Direction->0->n 
Traverse and solve-> To find arr1[i] -> we append 0 to all the strings ending with 1
                                        we get all the strings with no repetitive 0's 
                                        and end with 0
                     To find arr2[i] -> we append 1 to all the strings ending with both 0
                                        and 1 we get all the strings with no repetitive 
                                        0's and end with 1
https://www.youtube.com/watch?v=nqrXHJWMeBc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=18
*/
int noOfBinaryStrings(int n){
    int *dp0 = new int[n+1]; 
    int *dp1 = new int[n+1];
    dp0[0] = dp1[0] = 0;
    dp0[1] = dp1[1] = 1;
    for(int i = 2; i <= n; i++){
        dp0[i] = dp1[i-1];
        dp1[i] = dp0[i-1] + dp1[i-1];
    }
    return dp0[n] + dp1[n];
}

int noOfBinaryStringsOptimal(int n){
    int oczeros = 1; //Old count zeros
    int ocones = 1;  //Old count ones
    for(int i = 2; i <= n; i++){
       int nczeros = ocones;
       int ncones = oczeros + ocones;
       ocones = ncones;
       oczeros = nczeros;
    }
    return ocones + oczeros;
}

int main(){
    int n;
    cin >> n;
    cout << noOfBinaryStringsOptimal(n) << endl;
}