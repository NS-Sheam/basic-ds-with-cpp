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
int count_linked_list(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
        count++;
    }
    return count;
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
int main()
{

    Node *headA = NULL;
    Node *headB = NULL;
    int valA;
    int valB;
    while (true)
    {
        cin >> valA;
        if (valA == -1)
            break;
        insert_at_tail(headA, valA);
    }
    while (true)
    {
        cin >> valB;
        if (valB == -1)
            break;
        insert_at_tail(headB, valB);
    }
    cout << "Linked List:" << endl;
    int countA = count_linked_list(headA);
    int countB = count_linked_list(headB);

    cout << (countA == countB ? "Yes" : "No") << endl;

    return 0;
}