#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *left, *right;
        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        f->left = left;
        f->right = right;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
}
void level_order(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
void level_nodes(Node *root, int matchedLevel)
{
    queue<pair<Node *, int>> q;
    if (root)
        q.push({root, 0});
    bool isMatched = false;
    while (!q.empty())
    {
        pair<Node *, int> parent = q.front();
        q.pop();
        Node *node = parent.first;
        int level = parent.second;
        // cout << level << " " << matchedLevel << endl;
        if (level == matchedLevel)
        {
            cout << node->val << " ";
            isMatched = true;
        }

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    if (!isMatched)
        cout << "Invalid";
}

int max_depth(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int main()
{

    Node *root = input_tree();
    int val;
    cin >> val;
    // level_order(root);
    level_nodes(root, val);

    return 0;
}