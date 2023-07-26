//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    Node* divide(int N, Node *head) {
        vector<int> l1;
        vector<int> l2;
        Node* temp = head;
        
        // Divide the list into two separate vectors
        while (temp != NULL) {
            if (temp->data % 2 != 0) {
                l2.push_back(temp->data);
            } else {
                l1.push_back(temp->data);
            }
            temp = temp->next;
        }
        
        // Combine the two lists back together
        Node* curr = head;
        for (int i = 0; i < l1.size(); i++) {
            curr->data = l1[i];
            curr = curr->next;
        }
        for (int i = 0; i < l2.size(); i++) {
            curr->data = l2[i];
            curr = curr->next;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends