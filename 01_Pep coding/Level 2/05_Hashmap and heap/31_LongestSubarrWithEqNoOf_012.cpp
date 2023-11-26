/*
say count of 0, 1 and 2 till idx I is x0 x1 and x2 
and a = x0-x1, b = x1-x2

say count of 0, 1 and 2 till idx J is x0' x1'and  x2'
and a' = x0'-x1', b' = x1'-x2'

if a = a' and b = b' then that means subarray from idx I to J has equal no of 0 1 and 2's

This equallity implies that No of 0 has increased by same no of times as 1 and as well as 2
which is why the difference between count0-count1 and count1-count2 is same

https://www.youtube.com/watch?v=MRoWBJvJeLQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=33

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &arr) {
    //map <ab, idx>
    unordered_map<string, int> mp;   
    int c0 = 0, c1 = 0, c2 = 0, maxL = 0; 
    mp["0#0"] = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) c0++;
        else if(arr[i] == 1) c1++;
        else c2++;

        int a = c0-c1;
        int b = c1-c2;
        string key = to_string(a)+"#"+to_string(b);
        if(mp.find(key) != mp.end()) maxL = max(maxL, i - mp[key]);
        else mp[key] = i;
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