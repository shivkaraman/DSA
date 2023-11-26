/*
We treat 0 as -1 and 
         1 as 1
Now if a subarray contains equal no of 0s and 1s => Sum = 0
Now the problem is reduced to LONGEST SUBARRAY WITH SUM = 0 which we have solved before
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &arr) {
    //map <sum, idx>
    unordered_map<int, int> mp;
    mp[0] = -1;
    int cumSum = 0, maxL = 0;
    for(int i = 0;i < arr.size(); i++){
        cumSum += (arr[i] == 0 ? -1 : 1);
        auto it = mp.find(cumSum);
        if(it != mp.end()) maxL = max(maxL, i-it->second+1);
        else mp[cumSum] = i;
    }
    return maxL;
}

int main()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  };

  cout << solution(arr);
  return 0;
}