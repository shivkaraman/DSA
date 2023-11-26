/*
Given Target and K, Print all nodes which are k distance away in any direction from node with value equal to target.
                50  
               /  \
            25     75
            / \    / \
          12  37 62  87
              /\  \  
            30 60  70
               /
              25
1. First find node to root path of The target element
2. 1.Now call Print kth level from target element
   2.Call print (K-1)th level from 2nd last element in path
   3.Call print (K-2)th level from 3nd last element in path
eg-> target->37 , k = 2
     Ans -> 25 12 50
    1. Path -> 37 25 50
    2. 1. kth(2ND)level from 37-->25
       2. (k-1)th(1st)level from 25-->12 ans 37(we need to avoid printing 37)
       3. (k-2)th(0th)level from 50-->50
3. To avoid printing extra elements at (k-n)th level we use a BOLCKER in printKthLevel function
    3. for 25 we need to avoid printing 37, so we pass 37 as blocker

*/ 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node{
    public :
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* createTree(vector<int> pre){
    stack<pair<Node*, int>> s;
    Node *root = new Node(pre[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(pre[i] != 0){   
                temp.first->left = new Node(pre[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(pre[i] != 0){  
                temp.first->right = new Node(pre[i]);
                s.push({temp.first->right, 1});
            }
            i++;
        }
        else{
            s.pop();
        }
    }
    return root;
}

void printKthlevel(Node *root, int K, Node *blocker){
    if(root == NULL || K<0 || root == blocker)
        return;
    if(K == 0)  //K is ZERo only when we have reached Kth level
        cout<<root->data<<" ";
    printKthlevel(root->left, K-1, blocker);
    printKthlevel(root->right, K-1, blocker);
}

static vector<Node*> path;
bool findPath(Node *root, int target){
    if(root == NULL)
        return false;
    if(root->data == target){
        path.push_back(root);
        return true;
    }
    bool checkLeft = findPath(root->left, target);  //Faith->Gives path from node to root->left(if target is found)
    if(checkLeft){
        path.push_back(root);
        return true;
    }
    bool checkRight = findPath(root->right, target); //Faith->Gives path from node to root->right(if target is found)
    if(checkRight){
        path.push_back(root);
        return true;
    }
    return false;
}

void printKnodesFar(Node *root, int target, int k){
    findPath(root, target);
    for(int i=0; i<path.size(); i++){
        printKthlevel(path[i], k-i, i == 0 ? NULL : path[i-1]);
    } 
}
/*
                50  
               /  \
            25     75
            / \    / \
          12  37 62  87
              /\  \  
            30 60  70
               /
              25
*/ 
void preOrderTraversal(Node *ptr){
    if(ptr == NULL)
        return;
    cout<<ptr->data<<" ";
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

int main(){
    vector<int> pre = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 60, 25,NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(pre);
    int target;
    cin>>target;
    int k;
    cin>>k;
    printKnodesFar(root, target, k);
    return 0;
}