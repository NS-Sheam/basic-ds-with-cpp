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

int find_index(Node *head, int val)
{
    Node *tmp = head;
    int index = 0;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            return index;
        }
        tmp = tmp->next;
        index++;
    }
    return -1;
}

int main()
{

    int n;
    cin >> n;
    while (n--)
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
        int search_val;
        cin >> search_val;
        int index = find_index(head, search_val);
        cout << index << endl;
    }

    return 0;
}