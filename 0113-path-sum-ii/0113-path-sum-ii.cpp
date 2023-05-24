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
void solve(TreeNode* root,vector<vector<int>> &ans,vector<int> &temp,int x,int& mx){
    if(root == NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
            
            if(x+root->val==mx){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        solve(root->left,ans,temp,x+root->val,mx);
        solve(root->right,ans,temp,x+root->val,mx);
        temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,ans,temp,0,targetSum);
        return ans;
    }
};