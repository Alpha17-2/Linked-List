#include<bits/stdc++.h>
using namespace std;
// Node
struct node
{
    int data;
    struct node *next;
};
node* head = NULL; // Global 
node *createnode(int val)
{
    node *tempNode=new node();
    tempNode->data = val;
    tempNode->next = NULL;
    return tempNode;
}
void display()
{
    node *displayNode = head->next;
    while ( displayNode!=NULL)
    {
        cout << displayNode->data << "->";
        displayNode = displayNode->next;
    }
    cout << "NULL";
}
void insertatbeginning()
{
    cout << "Insert at begining \n";
    cout << "Enter value";
    int value;
    cin >> value;
    node *initialStart = head->next;
    head->next = createnode(value);
    head->next->next = initialStart;
}
void insertAfterN(int N)
{
    node *beforeNewNode = head->next;
    int ind = 1;
    while(ind<N)
    {
        beforeNewNode = beforeNewNode->next;
        ind++;
    }
    node *afterNewNode = beforeNewNode->next;
    int value;
    cout << "Enter value : ";
    cin >> value;
    beforeNewNode->next = createnode(value);
    node* newNode = beforeNewNode->next;
    newNode->next = afterNewNode;
}
void deleteFirstNode()
{
    if(head!=NULL)
    {
        head->next = head->next->next;
    }
    else
    {
        cout << "Head is Null";
    }
}
void insertatend()
{
    cout << "Insert at end\n";
    cout << "Enter value";
    int value;
    cin >> value;
    node *currentLastNode = head->next;
    // Traversing until we find the last node
    while(currentLastNode->next!=NULL)
    {
        currentLastNode = currentLastNode->next;
    }
    currentLastNode->next = createnode(value);
}
void deletelastnode()
{
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    head = new node;
    node *tempnode=head;
    cout << "Enter number of nodes\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        tempnode->next = createnode(value);
        tempnode = tempnode->next;
    }
    cout << "initial :\n";
    display();
    cout << "\n";
    deletelastnode();
    cout << "After deleting last node :\n";
    display();
    return 0;
}