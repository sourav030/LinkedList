#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class SiglyLinkList
{
public:
    Node *head;
    SiglyLinkList()
    {
        head = NULL;
    }
    void insertBegining(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }
    void insertTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }

    void insertAtPosition(int val, int post)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            cout << "List is empty. Cannot insert at position." << endl;
            return;
        }
        if (post == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        int i = 0;
        Node *temp = head;
        while (i < post - 2 and temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }

    void deleteNodeHead()
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from head." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    void deleteNodeTail()
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from tail." << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return;
    }
    void deleteAtAnyPosition(int a)
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from any position." << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        int i = 1;
        Node *temp = head;
        while (i != a-1)
        {
            temp = temp->next;
            i++;
        }
        if (i == a-1)
        {
            temp->next = temp->next->next;
            delete temp->next->next;
            return;
        }
        else
        {
            cout << "Position not found." << endl;
        }
        return;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    SiglyLinkList list;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> val;
        // list.insertTail(val);
        list.insertBegining(val);
    }
    list.insertAtPosition(14, 2);
    list.display();
    list.deleteNodeHead();
    list.deleteNodeTail();
    list.deleteAtAnyPosition(3);
    cout<<"After Deletion of node";
    list.display();

    return 0;
}