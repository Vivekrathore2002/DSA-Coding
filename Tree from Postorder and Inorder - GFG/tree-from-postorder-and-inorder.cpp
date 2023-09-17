//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/


//Function to return a tree created from postorder and inoreder traversals.

// https://www.youtube.com/watch?v=LgLRTaEMRVc&t=46s

Node* build(int inorder[],int is,int ie,int postorder[],int ps,int pe,map<int,int> &mpp)
    {
        if(ps>pe || is>ie)
            return NULL;
        
        Node* root = new Node(postorder[pe]);
        int inroot = mpp[postorder[pe]];
        int numleft = inroot-is;
        root->left = build(inorder,is,inroot-1,postorder,ps,ps+numleft-1,mpp);
        root->right = build(inorder,inroot+1,ie,postorder,ps+numleft,pe-1,mpp);
        return root;
    }
Node *buildTree(int inorder[], int postorder[], int n) {
    // Your code here
        map<int,int> mpp;
        
        for(int i = 0;i<n;i++)
        {
            mpp[inorder[i]] = i;
        }
        return build(inorder,0,n-1,postorder,0,n-1,mpp);
}
