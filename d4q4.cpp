/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int>* findstart(int start, BinaryTreeNode<int>* root){
    if(root==NULL) return nullptr;
    if(root->data==start) return root;
    if(root->left) findstart(start, root->left);
    if(root->right) findstart(start, root->right);
    return nullptr;
}
void markparents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& p, BinaryTreeNode<int>* target){
        queue<BinaryTreeNode<int>*> q;

        q.push(root);
        while(!q.empty()){
            BinaryTreeNode<int>* curr=q.front();
            q.pop();
            if(curr->left){
                p[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                p[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
        unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> p;
        unordered_map<BinaryTreeNode<int>*, bool> visited;
        BinaryTreeNode<int>* target=findstart(start, root);
        markparents(root,p,target);
        queue<BinaryTreeNode<int>*> q;
        q.push(target);
        visited[target]=true;
        int time=-1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode<int>* node=q.front(); 
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(p[node] && !visited[p[node]]){
                    q.push(p[node]);
                    visited[p[node]]=true;
                }
                time++;
            }
        }    
        return time;
    // Write your code here
}
