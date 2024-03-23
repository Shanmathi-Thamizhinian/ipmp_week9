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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int v=it.second.first;
            int l=it.second.second;
            mpp[v][l].insert(node->val);
            if(node->left){
                q.push({node->left,{v-1,l+1}});
            }
            if(node->right){
                q.push({node->right,{v+1,l+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i: mpp){
            vector<int> temp;
            for(auto j: i.second){
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;   
    }
};
