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
void print_reverse(Node *head)
{
    while (head == NULL)
        return;
    print_reverse(head->next);
    cout << head->val << endl;
}
void insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
int find_max(Node *head)
{
    int maxVal = INT_MIN;
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val > maxVal)
        {
            maxVal = tmp->val;
        }
        tmp = tmp->next;
    }
    return maxVal;
}
int main()
{

    Node *head = NULL;
    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, val);
    }

    cout << "Linked List:" << endl;
    Node *tmp = head;
    int maxValue = find_max(tmp);
    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}