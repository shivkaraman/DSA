/*
1. You are given a positive number N.
2. You have to find the minimum number of operations required to convert N into 1.
3. Operations allowed :
     (i)  If n is even, you have to replace n with n/2.
     (ii) If n is odd, you can replace n with either n-1 or n+1.
    
Sample Input
    8
Sample Output
    3
*/     
#include<bits/stdc++.h>
using namespace std;

/*
    *For even number we have only one opption -> n/2
    *For odd we have two options -> n-1 and n+1, we need to figure out for what type of odd numbers n+1 is beneficial and n-1 beneficial
    *We can categorise the odd numbers as 4x+1 and 4x+3
        For 4x+1 -> n-1 is beneficial
        For 4x+3 -> n+1 is beneficial

    But 3 is a special case -> 3 belongs to 4x+3 but n-1 is beneficial
    
    modulo operator is time extensive (n%4)
    WKT 4n+1 ends with 00001 in binary
        4n+3 ends with 00011 in binary
    
    In this question we are using bitwise operator only to modify the % operator

*/
int solution(long n){
    int count = 0;
    while(n != 1){
        count++;
        if(n % 2 == 0)
            n = n/2; //or n >> 1
        else if(n == 3)
            return count+2;
        else if ((n & 3) == 1) // n%4 == 1
            n = n-1;
        else if((n & 3) == 3)  // n%4 == 3
            n = n+1;
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    
    cout<<solution(n)<<endl;
    
}