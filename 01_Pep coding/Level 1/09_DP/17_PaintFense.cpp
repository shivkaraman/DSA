/*
1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two consecutive  fences have same colors.

Sample Input
8
3

Sample Output
3672
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Storage-> 2 1D arrays SAME and DIFFERENT
Meaing -> 
        same[i] -> No of ways in which the first i fences can be painted with k colors with last two fenses having the same color 
                   ie //* i and i-1 th fence painted with SAME color
        diff[i] -> No of ways in which the first i fences can be painted with k colors with last two fenses having the diff color 
                   ie //* i and i-1 th fence painted with DIFFERENT color
Direction -> 1->n
Traverse and solve->
        same[2] = K*1 ie We can color the first fense with any color ie we have k options and we have to color the second fence wi
                  with the same color which was used in the prev fense ie only one option
        diff[2] = K * (K-1) ie we can color the first fence with any color ie we have K options, and we can color the second 
                  fence with any other color excluding the prev color ie K-1 options
    For 3rd to nth fence
        same[i] = diff[i-1] because we can color the fence with same color as prev fence only when prev two fences aare painted 
                  with different color ie diff[i-1]
        diff[i] = ( same[i-1]-diff[i-1] ) * (K-1)  -> We can choose any of the previous options and color it with a color 
                  different than previous color i
*/
int paintFence(int n, int k){
    if(n == 1) return k;
    int same = k;
    int diff = k * (k-1);
    int total = same+diff;
    for(int i = 3; i <= n; i++){
        same = diff * 1; 
        diff = total * (k-1);
        total = same + diff;
    }
    return total;
}

int main() {
    int n ;
    cin >> n ;

    int k ;
    cin >> k ;
    
    cout << paintFence(n, k);
    return 0;
}

