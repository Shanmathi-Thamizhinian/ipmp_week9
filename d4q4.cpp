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


BinaryTreeNode<int>* markparents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& p, int start){
        queue<BinaryTreeNode<int>*> q;
        BinaryTreeNode<int>* res;
        q.push(root);
        while(!q.empty()){
            BinaryTreeNode<int>* curr=q.front();
            if(curr->data==start) res=curr;
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
        return res;
    }
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
        unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> p;
        unordered_map<BinaryTreeNode<int>*, bool> visited;
        BinaryTreeNode<int>* target=markparents(root,p,start);
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
                
            }
            time++;
        }    
        return time;
    // Write your code here
}
