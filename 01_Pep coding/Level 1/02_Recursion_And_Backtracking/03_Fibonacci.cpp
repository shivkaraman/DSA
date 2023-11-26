
#include <iostream>
using namespace std;
 
int fibonacci(int n){   //T(n)= T(n-1)+T(n-2)+1 == 2T(n-1) + 1 = O(2^n)
    if(n==2)
        return 1;
    else if(n==1)
        return 0;
    else
        return (fibonacci(n-1)+fibonacci(n-2));
}

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cout<<fibonacci(i)<<" ";
    return 0;
}