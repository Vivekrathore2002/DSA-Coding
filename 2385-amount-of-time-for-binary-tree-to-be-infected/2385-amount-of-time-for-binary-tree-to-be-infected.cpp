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

//  https://www.youtube.com/watch?v=XLdpy0_6MR4
class Solution {
public:
 //step-1 create mapping and return the target node
  TreeNode* createParentMapping(TreeNode* root,int target,map<TreeNode*,TreeNode*> &nodeToParent){
      TreeNode* res = NULL; //to store the result;
      queue<TreeNode*> q;
      q.push(root);
      nodeToParent[root] = NULL;
      while(!q.empty()){
          TreeNode* front = q.front();
          q.pop();
          if(front->val==target){
              res = front;
          }
          if(front->left){
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              nodeToParent[front->right] = front;
              q.push(front->right);
          }
      }
      return res;
  }
  int burnTree(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent){
      map<TreeNode*,bool> visited;
      queue<TreeNode*> q;
      q.push(root);
      visited[root] = true;
      int ans = 0;
      while(!q.empty()){
          bool flag = 0;
          int size = q.size();
          for(int i=0;i<size;i++){
              //process neighbours
              TreeNode* front = q.front();
              q.pop();
              if(front->left && !visited[front->left]){
                  flag = 1;
                  q.push(front->left);
                  visited[front->left] = 1;
              }
              if(front->right && !visited[front->right]){
                  flag = 1;
                  q.push(front->right);
                  visited[front->right] = 1;
              }
              if(nodeToParent[front] && !visited[nodeToParent[front]]){
                  flag = 1;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]] = 1;
              }
          }
          if(flag==1){
              ans++;
          }
      }
      return ans;
  }
    int amountOfTime(TreeNode* root, int target) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root,target,nodeToParent);
        int ans = burnTree(targetNode,nodeToParent);
        return ans;
    }
};