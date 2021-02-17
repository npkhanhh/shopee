#include <iostream>
#include <queue>

using namespace std;

//TODO optimize
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root==NULL) {
            return root;
        }
        queue<Node *> myqueue;
        myqueue.push(root);
        while (!myqueue.empty())
        {
            Node *parent = myqueue.front();
            myqueue.pop();
            Node *left = parent->left;
            Node *right = parent->right;

            if (left != NULL)
            {
                Node *head = parent;
                if (right != NULL)
                {
                    left->next = right;
                }
                else if (head->next != NULL)
                {
                    left->next = NULL;
                    while (head != NULL)
                    {
                        if (head->next != NULL)
                        {
                            if (head->next->left != NULL)
                            {
                                left->next = head->next->left;
                                break;
                            }
                            else if (head->next->right != NULL)
                            {
                                left->next = head->next->right;
                                break;
                            }
                        }
                        head = head->next;
                    }
                }
                myqueue.push(left);
            }
            if (right != NULL)
            {
                Node *head = parent;
                right->next = NULL;
                while (head != NULL)
                {
                    if (head->next != NULL)
                    {
                        if (head->next->left != NULL)
                        {
                            right->next = head->next->left;
                            break;
                        }
                        else if (head->next->right != NULL)
                        {
                            right->next = head->next->right;
                            break;
                        }
                    }
                    head = head->next;
                }
                myqueue.push(right);
            }
        }
        return root;
    }
};
