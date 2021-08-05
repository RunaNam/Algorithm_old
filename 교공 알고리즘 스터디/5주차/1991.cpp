#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
};

vector<Node *> leaf;

void pre(Node *a)
{
    char tmp(a->data);
    cout << tmp;
    if (a->left != NULL)
        pre(a->left);
    if (a->right != NULL)
        pre(a->right);
}

void in(Node *a)
{
    if (a->left != NULL)
        in(a->left);
    char tmp(a->data);
    cout << tmp;
    if (a->right != NULL)
        in(a->right);
}

void post(Node *a)
{
    if (a->left != NULL)
        post(a->left);
    if (a->right != NULL)
        post(a->right);
    char tmp(a->data);
    cout << tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = NULL;
    Node *cur = NULL;
    Node *left = NULL;
    Node *right = NULL;

    int n;
    char a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    // 첫노드 - root이므로 일단 값을 넣어줌
    root = new Node();
    root->data = a;
    if (b == '.')
    {
        root->left == NULL;
    }
    else
    {
        left = new Node();
        left->data = b;
        root->left = left;
        leaf.push_back(left);
    }
    if (c == '.')
    {
        root->right == NULL;
    }
    else
    {
        right = new Node();
        right->data = c;
        root->right = right;
        leaf.push_back(right);
    }

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        // 이후 - leaf vector 탐색을 한 뒤 해당 값에 넣어줌.
        for (int i = 0; i < leaf.size(); i++)
        {
            if (leaf[i]->data == a)
            {
                if (b == '.')
                {
                    leaf[i]->left = NULL;
                }
                else
                {
                    left = new Node();
                    left->data = b;
                    leaf[i]->left = left;
                    leaf.push_back(left);
                }

                if (c == '.')
                {
                    leaf[i]->right = NULL;
                }
                else
                {
                    right = new Node();
                    right->data = c;
                    leaf[i]->right = right;
                    leaf.push_back(right);
                }
                leaf.erase(leaf.begin() + i);
                break;
            }
        }
    }

    pre(root);
    cout << '\n';
    in(root);
    cout << '\n';
    post(root);

    return 0;
}
