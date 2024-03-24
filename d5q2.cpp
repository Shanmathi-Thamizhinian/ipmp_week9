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
    TreeNode* construct(vector<int>& pre, int pres, int pree, vector<int>& in, int ins, int ine, map<int,int> inmap){
        if(pres>pree||ins>ine) return NULL;
        TreeNode* root=new TreeNode(pre[pres]);
        int rooti=inmap[root->val];
        int nl=rooti-ins;
        root->left=construct(pre,pres+1,pres+nl,in,ins,rooti-1,inmap);
        root->right=construct(pre,pres+nl+1,pree,in,rooti+1,ine,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
};
