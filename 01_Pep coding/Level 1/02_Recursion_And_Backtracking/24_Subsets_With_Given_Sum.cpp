//Given an array of n elements , print all subsets/subsequences with sum of elements equal to target

#include <iostream>
#include <vector>
using namespace std;

void subsetsWithGivenSum(vector<int> vec, int idx, int target, string subSet, int sos){
    if (sos == target){
        cout << subSet << endl;
        return;
    }
    if (sos > target || idx == vec.size()) return;
    subsetsWithGivenSum(vec, idx + 1, target, subSet + to_string(vec[idx]) + " ", sos + vec[idx]);
    subsetsWithGivenSum(vec, idx + 1, target, subSet + "", sos);
}
int main()
{
    int size, target;
    cin >> size;

    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];

    cin >> target;
    subsetsWithGivenSum(v, 0, target, "", 0);
    return 0;
}