// https://www.youtube.com/watch?v=iK2VFYxFC4o&list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2&index=17 -> Pepcoding -> 07:05
/*
        Approach              Time         Space                  
    1. Search Compliment     O(nlogn)     O(logn)
    2. Inorder Vector        O(n)         O(n)
    3. Iterative Inorder     O(logn)      O(n)
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

Node* createTree(vector<int> vec, int l, int h){    
    if(l > h)   
        return NULL;
    int mid = (l + h)/2;
    int data = vec[mid];
    Node *lt = createTree(vec, l, mid - 1);
    Node *rt = createTree(vec, mid + 1, h);
    Node *root = new Node(data);
    root->left = lt;
    root->right = rt;
    return root;
}

Node* getNextElementFromInorder(stack <pair<Node*, int>> &s){
    while (!s.empty()){
        pair <Node*, int> temp = s.top();
        if(temp.second == 0){           //We are in Pre order
            s.top().second++;
            if(temp.first->left)
                s.push({temp.first->left, 0});
        }
        else if(temp.second == 1){      //We are in In order
            s.top().second++;
            if(temp.first->right)
                s.push({temp.first->right, 0});
            return temp.first;
        }
        else                            //We are in Post order  
            s.pop();
    }  
    return NULL;
}

Node* getNextElementFromReverseInorder(stack <pair<Node*, int>> &s){
    while (!s.empty()){
        pair <Node*, int> temp = s.top();
        if(temp.second == 0){           //We are in Pre order
            s.top().second++;
            if(temp.first->left)
                s.push({temp.first->right, 0});
        }
        else if(temp.second == 1){      //We are in In order
            s.top().second++;
            if(temp.first->right)
                s.push({temp.first->left, 0});
            return temp.first;
        }
        else                            //We are in Post order  
            s.pop();
    }  
    return NULL;
}

void targetSumPair(Node *root, int target){ // T=O(n) S=O(h)=O(logn)
    //pair <Node, state>
    stack<pair<Node*, int>> ls, rs;
    ls.push({root, 0});
    rs.push({root, 0});

    Node *left = getNextElementFromInorder(ls);
    Node *right = getNextElementFromReverseInorder(rs);
    while(left->data < right->data){
        int sum = left->data + right->data;
        if(sum < target)
            left = getNextElementFromInorder(ls);
        else if(sum > target)
            right = getNextElementFromReverseInorder(rs);
        else{
            cout << left->data << " " << right->data << endl;
            left = getNextElementFromInorder(ls);
            right = getNextElementFromReverseInorder(rs);
        }
    }

}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  38  62  87 
*/  
int main(){
    vector<int> vec = {12, 25, 38, 50, 62, 75, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);
    targetSumPair(root, 100);
    return 0;
}