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
    TreeNode* construct(vector<int>& po, int pos, int poe, vector<int>& in, int ins, int ine, map<int,int> inmap){
        if(pos>poe||ins>ine) return NULL;
        TreeNode* root=new TreeNode(po[poe]);
        int rooti=inmap[root->val];
        int nl=rooti-ins;
        root->left=construct(po,pos,pos+nl-1,in,ins,rooti-1,inmap);
        root->right=construct(po,pos+nl,poe-1,in,rooti+1,ine,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=construct(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
};
