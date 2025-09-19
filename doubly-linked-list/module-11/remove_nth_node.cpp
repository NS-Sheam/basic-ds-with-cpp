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

ListNode *removeElements(ListNode *&head, int n)
{
    ListNode *tmp = head;
    int listSize = 0;
    while (tmp != NULL)
    {
        listSize++;
        tmp = tmp->next;
    }
    int toDeleteIdx = listSize - n;
    if (toDeleteIdx == 0)
        head = head->next;
    else
    {
        ListNode *tmp2 = head;
        for (int i = 0; i < toDeleteIdx - 1; i++)
        {
            tmp2 = tmp2->next;
        }

        tmp2->next = tmp2->next->next;
    }
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

    cout << "Original Linked List: ";
    print_linked_list(head);
    removeElements(head, 2);
    cout << endl;
    cout << "After remove List: ";
    print_linked_list(head);

    return 0;
}