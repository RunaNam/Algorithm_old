#include <cstdio>
using namespace std;

typedef struct Node
{
    int data;
    int idx;
    struct Node *next;
    struct Node *past;
};

int n, k;

Node *newNode = NULL;
Node *head = NULL;
Node *tail = NULL;
Node *cur = NULL;
Node *past = NULL;
Node *t = NULL;

int cnt = 0;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        newNode = new Node();
        scanf("%d", &k);
        newNode->data = k;
        newNode->idx = i;
        newNode->next = NULL;
        newNode->past = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        if (past != NULL)
            newNode->past = past;

        tail = newNode;
        past = newNode;
    }

    tail->next = head;
    head->past = tail;
    cur = head;
    printf("%d ", cur->idx);
    t = cur;
    cur->past->next = t->next;
    cur->next->past = t->past;

    for (int i = 1; i < n; i++)
    {
        int tmp = cur->data;
        if (tmp > 0)
        {
            while (tmp--)
            {
                cur = cur->next;
            }
        }
        else
        {
            tmp = -tmp;
            while (tmp--)
            {
                cur = cur->past;
            }
        }
        printf("%d ", cur->idx);
        t = cur;
        cur->past->next = t->next;
        cur->next->past = t->past;
    }

    return 0;
}
