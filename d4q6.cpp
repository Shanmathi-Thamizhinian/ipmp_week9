/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& p, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        unordered_map<TreeNode*,TreeNode*> p;
        unordered_map<TreeNode*, bool> visited;
        markparents(root,p,target);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int currlevel=0;
        while(!q.empty()){
            int n=q.size();
            if(currlevel++==k) break;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front(); 
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
        }    
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
