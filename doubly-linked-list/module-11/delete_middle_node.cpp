#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *new_node = new ListNode(val);
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

void print_linked_list(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int sz(ListNode *head)
{
    ListNode *tmp = head;
    int listSize = 0;
    while (tmp != NULL)
    {
        listSize++;
        tmp = tmp->next;
    }

    return listSize;
};

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *tmp = head;
    int sizeList = sz(head);
    int midPoint = sizeList / 2;
    int toGo = (midPoint % 2 == 0) ? midPoint : ceil(midPoint);
    // cout << "Midpoint " << midPoint << " ToGo " << toGo << endl;
    for (int i = 0; i < toGo - 1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;

    return head;
};

int main()
{

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    cout << "Original Linked List : ";
    print_linked_list(head);
    cout << "After delete : " << endl;
    deleteMiddle(head);
    // cout << endl;
    print_linked_list(head);

    return 0;
}