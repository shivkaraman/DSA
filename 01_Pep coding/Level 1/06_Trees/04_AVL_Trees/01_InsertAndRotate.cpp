// C++ program to insert a node in AVL tree
#include<iostream>
#include<queue>
using namespace std;
 
// An AVL tree node
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        int height;
};

int height(Node *root){
    if (root == NULL)
        return 0;
    return root->height;
}
 
/* Helper function that allocates a
   new node with the given data and
   NULL left and right pointers. */
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return(node);
}
 /*
    Right rotate
                Y               X
               /  \            / \
             X     T3        T1   Y
            /\                    / \
          T1  T2                T2  T3

    Left rotate
                X             Y             
               / \          /  \          
             T1   Y       X     T3       
            / \          /\                  
          T2  T3      T1  T2              

                
*/
Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // Return new root
    return x;
}
 
// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(Node *root){
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
 
// Recursive function to insert a data
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int data){
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

void levelOrder(Node *root){
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node *temp = q.front();
            q.pop();
            //print cvurrent child
            cout<<temp->data<<" ";
            //At level 'l' add nodes of 'l+1'th level to queue
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        cout<<endl;
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    /* The constructed AVL Tree would be
              30
              / \
            20  40
            / \   \
          10  25  50
    */
    cout << "LevelOrder traversal of the constructed AVL tree is"<<endl;
    levelOrder(root);
     
    return 0;
}
