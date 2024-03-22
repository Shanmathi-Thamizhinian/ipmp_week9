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
    int maxpath(TreeNode* node, int& maxi){
        if(node==NULL) return 0;
        int ls,rs;
        ls=max(0,maxpath(node->left,maxi));
        rs=max(0,maxpath(node->right,maxi));
        maxi=max(maxi,node->val+ls+rs);
        return node->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
};
