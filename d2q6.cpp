/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>> ();
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int direc=1;
        while(!q.empty()){
        int n=q.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            int ind=(direc)?i:n-i-1;
            temp[ind]=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        direc=!direc;
        ans.push_back(temp);
    }
    return ans;
    }
};
