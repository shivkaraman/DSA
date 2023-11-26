/*
1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

youtube.com/watch?v=0nF-BMYy7tc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=19
*/

#include <iostream>
using namespace std;

/*
This problem is similar to Binary strings problem
if 1- Building is present
   0- Plot is left empty
The question is that no two 1's should occur consecutively
*/
void arrangeBuilding(int n){
   long int ob = 1;
   long int os = 1;
   for(int i = 2; i <= n; i++){
       int nb = os;
       int ns = ob + os;
       ob = nb;
       os = ns;
   }
   cout << (ob + os)*(ob + os);
}

int main(){
    int n;
    cin >> n;
    arrangeBuilding(n);
    return 0;
}