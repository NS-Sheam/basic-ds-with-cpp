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

ListNode *mergeNodes(ListNode *head)
{
    head = head->next;
    cout << "headval " << head->val << endl;
    ListNode *tmp1 = head;
    ListNode *tmp2 = head;
    int sum = 0;
    while (1)
    {
        if (tmp2->val == 0)
        {
            tmp1->val = sum;
            sum = 0;
            if (tmp2->next == NULL)
            {
                tmp1->next = NULL;
                break;
            }
            tmp1 = tmp1->next;
        }
        else
        {
            sum += tmp2->val;
        }
        tmp2 = tmp2->next;
    }
    cout << "headval " << head->val << endl;
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

    // cout << "Original Linked List : ";
    print_linked_list(head);
    // cout << "After merge : " << endl;
    mergeNodes(head);
    // cout << endl;
    print_linked_list(head);

    return 0;
}