
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    bool isOriginal;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *input_tree()
{
    int val;
    cin >> val;

    queue<TreeNode<int> *> q;
    TreeNode<int> *root;
    if (val == -1)
        root = NULL;
    else
        root = new TreeNode<int>(val);
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        TreeNode<int> *left, *right;

        if (l == -1)
            left = NULL;
        else
            left = new TreeNode<int>(l);
        if (r == -1)
            right = NULL;
        else
            right = new TreeNode<int>(r);

        f->left = left;
        f->right = right;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
};
void print_level_order(TreeNode<int> *root)
{
    if (!root)
        return;
    queue<TreeNode<int> *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
};

int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    // Write your code here.
    if (!root)
        return 0;
    if (root->val == searchedValue)
        return 1;
    // cout << "hello" << endl;
    int l = nodeLevel(root->left, searchedValue);
    int r = nodeLevel(root->right, searchedValue);

    if (l != 0)
        return l + 1;
    if (r != 0)
        return r + 1;
    return 0;
};

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int searchVal;
        TreeNode<int> *root = input_tree();
        cin >> searchVal;
        int level = nodeLevel(root, searchVal);
        print_level_order(root);
        cout << endl;
        cout << level << endl;
    }
    return 0;
}
