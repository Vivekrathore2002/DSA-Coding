//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to add two numbers represented by linked lists.
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    // Check if both lists are empty, return NULL.
        if (!first && !second) {
            return NULL;
        }
        
        first = reverse(first);
        second = reverse(second);
        
        Node* l3 = new Node(0);
        int carry = 0;
        Node* head = l3;
    
        while (first && second) {              
            int value = first->data + second->data + carry; 
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            first = first->next;
            second = second->next;           
        }
    
        while (first) { 
            int value = first->data + carry; 
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            first = first->next;
        }
    
        while (second) {
            int value = second->data + carry; 
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            second = second->next;     
        }
    
        if (carry) {
            l3->next = new Node(carry);
        }
    
        Node* result = head->next;
        delete head; // Free the memory used by the initial zero node.
        return reverse(result);
    }
    

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends