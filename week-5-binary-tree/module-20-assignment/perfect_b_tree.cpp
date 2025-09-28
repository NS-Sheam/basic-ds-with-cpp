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
bool isPerfect(Node *root, int depth, int level = 1)
{
    if (!root)
        return true;

    if (!root->left && !root->right)
        return depth == level;
    if (!root->left || !root->right)
        return false;

    bool l = isPerfect(root->left, depth, level + 1);
    bool r = isPerfect(root->right, depth, level + 1);
    return l && r;
}

int max_depth(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int main()
{
    vector<int> v;

    Node *root = input_tree();
    // level_order(root);
    int depth = max_depth(root);
    cout << " depth " << depth << endl;
    bool is_perfect = isPerfect(root, depth);
    cout << " c " << is_perfect;

    return 0;
}