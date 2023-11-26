//Diameter -> number of edges between two nodes which are farthest from each other in terms of edges

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public : 
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }   
};

Node* createTree(vector<int> vec){
    stack<pair<Node*, int>> s;
    Node *root = new Node(vec[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(vec[i] != 0){
                temp.first->left = new Node(vec[i]);    
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(vec[i] != 0){
                temp.first->right = new Node(vec[i]);    
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

int height(Node *root){
    if(root == NULL)
        return -1;
    int lh = height(root->left);        //Gives max height on left side
    int rh = height(root->right);       //Gives max height on right side
    int h = max(lh, rh) + 1;            
    return h;
}

int diameter1(Node *root){
    if(root == NULL)
        return 0;
    //max distance between two nodes on lhs (When both the two deepest nodes are present on LHS)
    int ld = diameter1(root->left);
    //max distance between two nodes on rhs (When both the two deepest nodes are present on RHS)
    int rd = diameter1(root->right);
    //max distance btw left deepest node and right deepest node (When one deepest node is peresent on RHS and other on LHS)
    int f = height(root->left) + height(root->right) + 2;
    int diameter = max(ld, max(rd, f));
    return diameter;
}
// But the above approach is inneficient --> because a recursive function 'diameter1' itself is calling another recurcive 
// function 'height' which increases time complexity--> Which is why we calculate both diameter and height in the same function
// https://www.youtube.com/watch?v=S0Bwgtn32uI&list=PL-Jc9J83PIiHYxUk8dSu2_G7MR1PaGXN4&index=45

// pair<diameter, height> 
pair<int, int> diameter2(Node *root){ //--> Finding height and diameter at the same time
    if(root == NULL)
        return {0, -1};
    
    //max distance between two nodes on lhs and height of lhs
    pair<int, int> lp = diameter2(root->left);  
    //max distance between two nodes on rhs and height of rhs
    pair<int, int> rp = diameter2(root->right);  
    //max distance btw left deepest node and right deepest node
    int f = lp.second + rp.second + 2;
    //Finding height 
    pair<int, int> myPair;
    myPair.second = max(lp.second, rp.second) + 1; 
    //Finding diameter
    myPair.first = max(f, max(lp.first, rp.first));
    return myPair;
}

/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /    \  
            30      70
                    /
                   90
*/  

int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, 90, NULL, NULL, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);
    // cout<<diameter1(root)<<endl; -> Inneficient 
    pair<int, int> p = diameter2(root);
    cout<<p.first<<endl;
    return 0;
}