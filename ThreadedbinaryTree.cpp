#include <iostream>
using namespace std;

struct node
{
    int data, lbit, rbit;
    node *left, *right;
};

void insertNode(node *root, node *newNode, node *head)
{
    if (root->data > newNode->data)
    {
        if (root->left == head)
        {
            root->left = newNode;
            root->lbit = 1;
            newNode->left = head;
            newNode->right = root;
        }
        else
            insertNode(root->left, newNode, head);
    }
    else if (root->data < newNode->data)
    {
        if (root->right == head)
        {
            root->right = newNode;
            root->rbit = 1;
            newNode->right = head;
            newNode->left = root;
        }
        else
            insertNode(root->right, newNode, head);
    }
}

node *createTree()
{
    struct node *head = new struct node;
    head->data = INT_MIN;
    head->left = NULL;
    head->right = head;
    head->lbit = 0;
    head->rbit = 1;

    struct node *root = NULL;

    char ch;

    do
    {
        struct node *newNode = new struct node;
        cout << "Enter the data of the node: ";
        cin >> newNode->data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->lbit = 0;
        newNode->rbit = 0;
        if (root == NULL)
        {
            root = newNode;
            root->left = head;
            root->right = head;
            head->left = root;
            head->lbit = 1;
        }
        else
        {
            insertNode(root, newNode, head);
        }

        cout << "Do you want to continue(y/n): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
    return head;
}

void inorderDisplay(node *head)
{
    node *temp = head->left;

    do
    {
        while (temp->lbit != 0)
        {
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rbit == 0 && temp->right != head)
        {
            temp = temp->right;
            cout << temp->data << " ";
        }
        temp = temp->right;
    } while (temp != head);
}

int main()
{
    node *head = NULL;

    cout << "\nchoose: \n1. For creating the Threaded Binary Search Tree \n2. For displaying the Threaded Binary Search Tree \n3. To stop\n";
    int ch;
    cin >> ch;
    while (ch != 3)
    {
        if (ch == 1)
        {
            head = createTree();
        }
        else if (ch == 2)
        {
            if (head == NULL)
                cout << "First create a Threaded Binary Search Tree\n";
            else
                inorderDisplay(head);
        }
        else if (ch == 3)
        {
            cout << "THANK YOU !!\n";
        }
        else
            cout << "Enter valid option\n";
        cout << "choose: \n1. For creating the Threaded Binary Search Tree \n2. For displaying the Threaded Binary Search Tree \n3. To stop\n";
        cin >> ch;
    }
}