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
//  https://www.youtube.com/watch?v=ffE1xj51EBQ&ab_channel=CodeHelp-byBabbar
class Solution {
public:
int findPosition(vector<int>& inorder,int element,int n){
    //We can optimise here by not using the for loop or this function to get the inde for that we can simply use a map function which will store the mapping of all the elements 
    for(int i=0;i<n;i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& inorder,vector<int>& preorder,int &index,int inOrderStart,int inOrderEnd,int n){
    //Base cases 
    //first case case when start will Be greater then end itself
    //second when we covered whole length of inorder 
    if(index>=n || inOrderStart>inOrderEnd){
        return NULL;
    }
    int element=preorder[index];
    index++;
    TreeNode* root=new TreeNode(element);
    int position = findPosition(inorder,element,n);

    //Now recursive calls 
    root->left=solve(inorder,preorder,index,inOrderStart,position-1,n);
    root->right=solve(inorder,preorder,index,position+1,inOrderEnd,n);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int preOrderIndex=0;
        TreeNode* ans = solve(inorder,preorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};