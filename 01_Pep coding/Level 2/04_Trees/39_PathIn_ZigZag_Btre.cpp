// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// https://www.youtube.com/watch?v=2Hn_dhDbHRE&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=62
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val){
        this->val = val;
    }
};

vector<int> pathInZigZagTree(int label) {
    vector<int> result;
    result.push_back(label); 

    int height=log2(label); //height of label from root
    while(height!=0){
        //Calculating range of level
        int start = pow(2,height-1); 
        int end = pow(2,height)-1;
        //Calculating parent value 
        label = start + end - label/2;
                                    
        result.push_back(label);  
        height--;
    }
    
    reverse(result.begin(),result.end());
    return result;
}



int main(){
    int label;
    cin >> label;

    vector<int> ans = pathInZigZagTree(label);
    for(int &i : ans)
        cout << i << " ";
    return 0;
}