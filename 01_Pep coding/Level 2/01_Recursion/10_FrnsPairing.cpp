/*
1. You are given an integer n, which represents n friends numbered from 1 to n.
2. Each one can remain single or can pair up with some other friend.
3. You have to print all the configurations in which friends can remain single or can be paired up.

Sample Input
    3

Sample Output
    1.(1) (2) (3) 
    2.(1) (2,3) 
    3.(1,2) (3) 
    4.(1,3) (2) 
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Level - person i
//Option - 1. To be single
//         2. To pair with any ony one of other n-1 people(who are not already paired)
void friends(int n, int x, string fsf, vector<bool> paired){
    if(x == n){
        static int count = 1;
        if(paired[x] != true)
            cout << count << "." << fsf << "(" << x << ") " << endl;
        else
            cout << count << "." << fsf << endl;
        count++;
        return;
    }
    if(paired[x] == true)
        friends(n, x+1, fsf, paired);
    else{
        paired[x] = true;
        friends(n, x+1, fsf + "(" + to_string(x) + ") ", paired); //Single
        for(int i = x+1; i <= n; i++){
            if(paired[i] != true){
                paired[i] = true;
                friends(n, x+1, fsf + "(" +to_string(x) + "," + to_string(i) + ") ", paired); //Pair up with other unpaired frnz
                paired[i] = false;
            }
        } 
    }

}

int main(){
    int n;
    cin >> n;
    vector<bool> paired(n+1, false);
    friends(n, 1, "", paired);
}