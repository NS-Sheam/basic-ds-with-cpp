#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
    tail = new_node;
}

void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse_list(Node *&head, Node *&tail)
{
    for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
    {
        swap(i->val, j->val);
    }
}

bool isPalindrome(Node *head, Node *tail)
{
    bool is_palindrome = true;
    Node *left = head;
    Node *right = tail;
    while (left != right && left->prev != right)
    {
        if (left->val != right->val)
        {
            is_palindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }
    return is_palindrome;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
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
    Node *head2 = NULL;
    Node *tail2 = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val);
    }

    Node *tmp1 = head;
    Node *tmp2 = head2;
    bool same = true;
    while (tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1->val != tmp2->val)
        {
            same = false;
            break;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    if (same && tmp1 == NULL && tmp2 == NULL)
    {
        cout << "Both lists are the same." << endl;
    }
    else
    {
        cout << "Lists are not the same." << endl;
    }

    reverse_list(head, tail);
    print_forward(head);
    bool is_palindrome = isPalindrome(head, tail);
    cout << (is_palindrome ? "YES" : "NO") << endl;

    return 0;
}