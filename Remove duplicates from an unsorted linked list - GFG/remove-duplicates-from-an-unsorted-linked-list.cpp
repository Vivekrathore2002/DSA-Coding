//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


#include <set>

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node* head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
            return head;
        set<int> s1;
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL) {
            if (s1.find(current->data) != s1.end()) {
                // Duplicate node found, remove it
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                // Unique node, add it to the set
                s1.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends