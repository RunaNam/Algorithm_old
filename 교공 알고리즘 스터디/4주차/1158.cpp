#include <cstdio>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
};

int n, k;

Node *newNode = NULL;
Node *head = NULL;
Node *tail = NULL;
Node *cur = NULL;
Node *past = NULL;
int cnt = 0;

void Josephus()
{

    for (int i = 1; i < k; i++)
    {
        past = cur;
        cur = cur->next;
    }
    printf("<%d, ", cur->data);
    past->next = cur->next;
    cnt = 1;

    while (cnt < n - 1)
    {
        for (int i = 0; i < k; i++)
        {
            past = cur;
            cur = cur->next;
        }
        printf("%d, ", cur->data);
        past->next = cur->next;
        cnt++;
    }

    for (int i = 0; i < k; i++)
    {
        cur = cur->next;
    }
    printf("%d>", cur->data);
}

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        newNode = new Node();
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
    cur = head;
    past = head;

    if (n > 1)
        Josephus();
    else
        printf("<%d>", cur->data);

    return 0;
}