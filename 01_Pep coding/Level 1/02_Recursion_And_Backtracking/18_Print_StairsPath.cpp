#include <iostream>
using namespace std;

//level -> No of steps
//option-> how much steps to take
void printStairPaths(int n ,string psp){
    if(n==0){
        cout<<psp<<endl;
        return;
    }
    if(n<0)
        return;
    printStairPaths(n-1 ,psp+"1");
    printStairPaths(n-2 ,psp+"2");
    printStairPaths(n-3 ,psp+"3");
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n ,"");
}