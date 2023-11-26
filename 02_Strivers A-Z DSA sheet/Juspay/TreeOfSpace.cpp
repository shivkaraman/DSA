// https://thejoboverflow.com/p/p703/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class TreeNode{
public:
    string name;
    vector<TreeNode*> children;
    TreeNode *par;
    int id, asc_locked, des_locked;
    bool isLocked;

    TreeNode(string name, TreeNode *par){
        this->name = name;
        this->par = par;
        isLocked = false;
        id = -1, asc_locked = 0, des_locked = 0;
    }
};

class myPair{
public:
    int qid, uid;
    string name;
    myPair(int qid, string name, int uid){
        this->qid = qid;
        this->name = name;
        this->uid = uid;
    }
};

TreeNode* createTree(vector<string> nodes, int n, int m, unordered_map<string, TreeNode*> &mp){
    TreeNode *root = new TreeNode(nodes[0], nullptr);
    queue<TreeNode*> q;
    q.push(root);
    mp[nodes[0]] = root;
    int idx = 1;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode *node = q.front();
            q.pop();

            int range = idx+m;
            while(idx < n && idx < range){
                TreeNode *newNode = new TreeNode(nodes[idx], node);
                node->children.push_back(newNode);
                q.push(newNode);
                mp[nodes[idx]] = newNode;
                idx++;
            }

        }
    }
    return root;
}

void display(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode *node = q.front();
            q.pop();

            cout << node->name << " ";
            for(TreeNode* child: node->children){
                q.push(child);
            }
        }
        cout << endl;
    }
}

void lockDescendents(TreeNode *node, int val){
    if(node == nullptr) return;
    node->asc_locked += val;

    for(TreeNode *child : node->children){
        lockDescendents(child, val);
    }
}

bool lock(TreeNode *node, int id){
    //If node is locked or if its descendent is locked or its ascendent is locked => CANNOT BE LOCKED
    if(node->isLocked || node->asc_locked > 0 || node->des_locked > 0)
        return false;

    //Marking all ascendents as locked
    TreeNode *curr = node->par;
    while(curr){
        curr->des_locked++;
        curr = curr->par;
    }

    //Maeking all descendents as locked
    lockDescendents(node, 1);

    //Locking node
    node->isLocked = true;
    node->id = id;
    return true;
}

bool unlock(TreeNode *node, int id){
    //If node is not locked or if someone else is trying to unlock
    if(node->isLocked == false || node->id != id) return false;

    //Marking all ascendents unlocked
    TreeNode *curr = node->par;
    while(curr){
        curr->asc_locked--;
        curr = curr->par;
    }

    //Maring all descendents unlocked
    lockDescendents(node, -1);

    //Unlocking Node
    node->isLocked = false;
    node->id = -1;
    return true;
}

//Get all children who are locked by the same uid
bool getAllChildren(TreeNode *node, vector<TreeNode*> &children, int id){
    if(node == nullptr) 
        return false;

    //If node is locked by another user => return false
    if(node->isLocked == true){
        if(node->id != id)
            return false;
        else    
            children.push_back(node);
    }
    if(node->des_locked == 0) return true;

    for(TreeNode *child: node->children){
        bool res = getAllChildren(child, children, id);
        if(!res) return false;
    }
    return true;
}

bool upgrade(TreeNode *node, int id){
    if(node->isLocked || node->des_locked == 0)
        return 0;

    vector<TreeNode*> children;
    bool res = getAllChildren(node, children, id);
    if(!res) return false;

    for(TreeNode *child: children){
        unlock(child, id);
    }
    lockDescendents(node, 1);
    node->isLocked = true;
    node->id = id;
    return true;
}

int main(){
    int n, m; //No of nodes, no of children each node has
    cin >> n >> m;

    vector<string> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    int noOfq;
    cin >> noOfq;
    vector<myPair> queries;
    for(int i = 0; i < noOfq; i++){
        int qid, uid;
        string name;
        cin >> qid >> name >> uid;
        myPair p(qid, name, uid);
        queries.push_back(p);
    }

    unordered_map<string, TreeNode*> mp; //map<name, node>
    //1. Tree Creation
    TreeNode *root = createTree(nodes, n, m, mp);

    //2. Querying the tree
    for(myPair &q : queries){
        if(q.qid == 1)
            cout << lock(mp[q.name], q.uid) << endl;
        else if(q.qid == 2)
            cout << unlock(mp[q.name], q.uid) << endl;
        else
            cout << upgrade(mp[q.name], q.uid) << endl;

    }
    return 0;
}