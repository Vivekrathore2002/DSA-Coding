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
        cout << node->data%10; 
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

class Solution
{
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr!= NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head) {
        // Reverse the linked list to process digits from the least significant digit to the most significant digit.
        head = reverse(head);

        Node* curr = head;
        int carry = 1; // Initialize carry to 1, as we want to add 1 to the number.

        while (curr != NULL) {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            curr = curr->next;
        }

        // If there is a carry left after processing all digits, add a new node to represent the carry.
        if (carry > 0) {
            Node* newCarryNode = new Node(-1);
            newCarryNode->data = carry;
            newCarryNode->next = NULL;

            // Find the last node and append the new carry node.
            Node* lastNode = head;
            while (lastNode->next != NULL) {
                lastNode = lastNode->next;
            }
            lastNode->next = newCarryNode;
        }

        // Reverse the linked list again to restore the original order.
        return reverse(head);
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends