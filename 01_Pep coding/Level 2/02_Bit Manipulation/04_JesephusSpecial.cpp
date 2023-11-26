#include<bits/stdc++.h>
using namespace std;
  
//Represent n as 2^x + l 
//Answer is 2l+1
int powOf2(int n){
  int i = 1;
  while(i * 2 <= n){
    i *= 2;
  }
  return i;
}

int solution(int n){
  int highestPowOf2 = powOf2(n);
  int l = n - highestPowOf2;

  return 2*l + 1;
}


int main(){
  int n;
  cin>>n;

  cout<<solution(n);
}