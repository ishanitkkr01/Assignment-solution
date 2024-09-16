// 3.  Palindrome Linked List 

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int ele)
    {
        val=ele;
        next=nullptr;
    }
};

Node * reverseLink(Node* head)
{
    Node * prev=nullptr;
    Node * cur=head;
    Node * next;
    
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

bool identical(Node * n1, Node * n2)
{
    for(; n1 && n2;n1=n1->next,n2=n2->next)
    {
        if(n1->val !=n2->val)
        {
            return 0;
        }
    }
    return 1;
}

bool isPalindrome(Node *head)
{
    if(!head || !head->next)
    {
        return true;
    }
    Node * slow=head;
    Node * fast=head;
    
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node * head2=reverseLink(slow->next);
    slow->next=nullptr;
    bool iden=identical(head,head2);
    slow->next=head2;
    
    return iden;
}


int main()
{
    Node head(1);
    head.next=new Node(2);
    head.next->next=new Node(3);
    head.next->next->next=new Node(2);
    head.next->next->next->next=new Node(1);
    
    bool ans= isPalindrome(&head);
    
    if(ans)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}