#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{

    int val;
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    Node *current = head;
    while (current != NULL)
    {

        Node *prev = current;
        Node *nextNode = current->next;
        while (nextNode != NULL)
        {
            if (current->val == nextNode->val)
            {
                Node *toDelete = nextNode;
                prev->next = nextNode->next;
                nextNode = nextNode->next;
                delete toDelete;
            }
            else
            {
                prev = nextNode;
                nextNode = nextNode->next;
            }
        }

        current = current->next;
    }
    print_list(head);

    return 0;
}