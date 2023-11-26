/*
We calculate cumulative sum of the array
while doing so, if value of cumulative sum repeats => sum after prev occurance till curridx is 0

we update max len if the length of substring is greater then prev length
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> arr) {
    //map <sum, idx>
    unordered_map<int, int> mp;
    int cumSum = 0, maxL = 0;
    mp[0] = -1;
    for(int i = 0; i < arr.size(); i++){
        cumSum += arr[i];
        auto it = mp.find(cumSum);
        if(it != mp.end()) maxL = max(maxL, i - it->second);
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