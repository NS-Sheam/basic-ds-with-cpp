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

ListNode *swapNodes(ListNode *head, int k)
{
    int listSize = sz(head);
    cout << listSize << endl;
    ListNode *tmp1 = head;
    // for (int i = 0; i < k - 1; i++)
    // {
    //     tmp1 = tmp1->next;
    // }

    ListNode *tmp2 = head;
    for (int i = 0; i < listSize - k; i++)
    {
        if (i < k - 1)
        {
            tmp1 = tmp1->next;
        }
        tmp2 = tmp2->next;
    }
    int tmp = tmp1->val;
    tmp1->val = tmp2->val;
    tmp2->val = tmp;
    cout << "tmp1 " << tmp1->val << " tmp2 " << tmp2->val << " " << "listSize " << (listSize - k) << endl;

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
    cout << "After swap : " << endl;
    swapNodes(head, 2);
    // cout << endl;
    print_linked_list(head);

    return 0;
}