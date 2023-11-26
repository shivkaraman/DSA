/*
1. Pepcoder is feeling confident after solving many problems on Bit Manipulation.
2. So, his teacher ask him to find out the count of positive integers strictly less than N, having same 
     number of set bits as that of N.
3. Let us see that if pepcoder can solve it or not.  

Sample Input
    1024
Sample Output
    10
*/
#include<bits/stdc++.h>
using namespace std;

long ncr(long n, long r){ //Combination -> choosing r bit positions out of n positions
    if(n < r)
        return 0L;    

    long res = 1L;
    for(long i = 0L; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int csb(long n){ //count set bits
    int res = 0;
    while(n > 0){
        long rsb = n & -n;
        n -= rsb;
        res++;
    }
    return res;
}

long  solution(long n,long k,int i){
    if(i == 0)
        return 0;
    long res = 0;
    long mask = (1L << i);
    //Checking if ith bit is on or off
    if((n & mask) == 0) //If OFF -> do nothing
        res = solution(n, k, i-1);
    else{
        long res1 = solution(n, k-1, i-1); //Finding numbers with k-1 bits turned on in rest of bits
        long res0 = ncr(i, k);// Not considering the current bit as 1 and choosing k bits in rest of bits
        res = res0 + res1;
    }
    return res;
}

int main(){
    long n;
    cin>>n;
    
    long k = csb(n); //Get no of set bits in n
    long ans = solution(n,k,63); //63 -> no of bits in n(long int)
    cout << ans << "\n";
    return 0;
    
}