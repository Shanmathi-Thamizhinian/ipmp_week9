/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL) return true;
    int sum=0;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL && root->right) sum=root->right->data;
    else if(root->right==NULL && root->left) sum=root->left->data; 
    else sum=root->left->data + root->right->data;

    if(sum!=root->data) return false;
    return isParentSum(root->left) && isParentSum(root->right);
}
