//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// https://youtu.be/_9F2VgZcvdw?si=2zMs2xS7mSeA3Rqr
class Solution {
  public:
  int countNodes(struct Node* tree){
      if(tree==NULL){
          return 0;
      }
      int ans = 1+countNodes(tree->left)+countNodes(tree->right);
      return ans;
  }
  bool isCbt(struct Node* tree,int index,int cnt){
      if(tree==NULL){
          return true;
      }
      //if a parent would have only right node(not left node) which is not complete binary
    //   tree then the right node would have index more than whole number of nodes 
    //possible in the tree
    //in that case print false;
      if(index>=cnt){
          return false;
      }
      else{
          //to check left node 2*i+1;
          //to check right node 2*i+2;
          bool left = isCbt(tree->left,2*index+1,cnt);
          bool right = isCbt(tree->right,2*index+2,cnt);
          return left&&right;
      }
  }
  bool isMaxOrder(struct Node* tree){
      //by now we are sure that the tree is cbt since the first condition in main function
    //if condition was this only that first cbt should be there
    //three possiblities can be there either the node can be leaf node or only left node
    // is there(right node is can not be there since that can not be cbt) and the node
    // do have left and right
    //1st only leaf node is there
    if(tree->left==NULL && tree->right ==NULL){
        return true;
    }
    //2nd only left node is there
    if(tree->right==NULL){
        return tree->data>tree->left->data;
    }
    //3rd both nodes are there
    else{
        bool left = isMaxOrder(tree->left);
        bool right = isMaxOrder(tree->right);
        if(left && right && (tree->data>tree->left->data && tree->data>tree->right->data)){
            return true;
        }
        else{
            return false;
        }
    }
  }
    bool isHeap(struct Node* tree) {
        
        //first we would find out all the nodes(i.e. count Nodes)
        int index = 0;
        int totalCount = countNodes(tree);
        
        //a heap is a complete binary tree(cbt) and all the nodes have higher values than
        //their child nodes
        // isCbt is to check whether a tree is a complete binary tree or not and
        //isMaxOrder is to check the condition that all the parent nodes have greater 
        // values than the child nodes or not
        
        if(isCbt(tree,index,totalCount) && isMaxOrder(tree)){
            //if both true than print true
            return true;
        }
        else{
            //else false
            return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends