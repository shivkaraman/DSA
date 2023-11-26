// https://leetcode.com/problems/rabbits-in-forest/description/
/*
Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

As we see in this explaination, we can see that in , the rabits are refering to each other 
So we can generalise that the rabits whose answers are the same may be refering to one another
hencer we need a formula to calculate no of rabit based on freq of each answer -> Shown in the code
*/
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;

int numRabbits(vector<int>& answers) {
       unordered_map<int, int> mp;
       for(int &num : answers) mp[num]++;

        int ans = 0;
       for(pair<int, int> p : mp){ // n->m
            int n = p.first;
            int m = p.second;

            if(m > n) ans += ceil(float(m)/(n+1)) * (n+1);
            else ans += n+1;
       }
       return ans;
    }



int main(){
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    };

    cout << numRabbits(arr);
    return 0;
}
