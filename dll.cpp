#include<bits/stdc++.h>
using namespace std;

// Creating Node
struct node
{
    int val;
    struct node *next;
    struct node *prev;
};
node *head; // global head
node *createNewNode(node* previousNode,int value)
{
    node *newNode = new node(); // Created a new node
    newNode->val = value; // initialisde value
    newNode->next = NULL;
    newNode->prev = previousNode;
    return newNode;
}
void display()
{
    // traversing first front to last
    cout << "Displaying nodes from first to last :\n";
    node *temp = head->next;
    while (temp->next!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout <<temp->val<<"->NULL";

    // traversing from last to first
    cout << "Displaying nodes from last to first :\n";
    while (temp->prev!=NULL)
    {
        cout << temp->val << "->";
        temp = temp->prev;
    }
    cout << "NULL";
}
int main()
{
    head = new node();
    node *temp = head;
    head->prev = NULL;
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter values :\n";
    for (int i = 0; i < n;++i)
    {
        int value;
        cin >> value;
        temp->next = createNewNode(temp, value);
        temp = temp->next;
    }
    display();
    return 0;
}
