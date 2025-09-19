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

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     ListNode *tmp1 = headA;
//     ListNode *tmp2 = headB;

//     while (tmp1 != NULL)
//     {
//         tmp2 = headB;
//         while (tmp2 != NULL)
//         {
//             if (tmp1 == tmp2)
//             {

//                 cout << tmp1->val << "tmp1" << endl;
//                 return tmp1;
//             }
//             tmp2 = tmp2->next;
//         }
//         tmp1 = tmp1->next;
//     }
//     return NULL;
// };
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tmp1 = headA;
    ListNode *tmp2 = headB;

    while (tmp1 == tmp2)
    {
        if (tmp1 == NULL)
            tmp1 = headB;
        else
            tmp1 = tmp1->next;
        if (tmp2 == NULL)
            tmp2 = headA;
        else
            tmp2 = tmp2->next;
    }
    return tmp1;
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
    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val);
    }

    cout << "Original Linked List1 : ";
    print_linked_list(head);
    cout << "Original Linked List2 : ";
    print_linked_list(head2);
    cout << "After intersect : " << endl;
    ListNode *n = getIntersectionNode(head, head2);
    cout << endl;
    print_linked_list(n);

    return 0;
}