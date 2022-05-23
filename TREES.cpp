#include <iostream>
using namespace std;

struct node
{
    string label;
    node *children[5];
    int children_count;
};

struct node *TreeBuild()
{
    string BookName;
    cout << "Enter the name of Book: ";
    cin >> BookName;
    struct node *root = new struct node;
    root->label = BookName;

    int chapterNumber;
    cout << "Enter the number of chapters: ";
    cin >> chapterNumber;
    root->children_count = chapterNumber;

    for (int i = 0; i < chapterNumber; i++)
    {
        cout << "Enter the name of " << i << " th chapter: ";
        string chapterName;
        cin >> chapterName;

        struct node *chapter = new struct node;
        chapter->label = chapterName;
        root->children[i] = chapter;

        cout << "Enter the number of Sections in " << chapterName << " chapter: ";
        int sectionNumber;
        cin >> sectionNumber;
        chapter->children_count = sectionNumber;

        for (int j = 0; j < sectionNumber; j++)
        {
            cout << "Enter the name of the section: ";
            string sectionName;
            cin >> sectionName;

            struct node *section = new struct node;
            section->label = sectionName;

            chapter->children[j] = section;
        }
    }
    return root;
}

void displayTree(node *root)
{
    cout << "\nBOOK NAME: ";
    cout << root->label << endl
         << endl;

    for (int i = 0; i < root->children_count; i++)
    {
        cout << "CHAPTER NAME: ";
        cout << root->children[i]->label << endl
             << endl;

        for (int j = 0; j < root->children[i]->children_count; j++)
        {
            cout << "SECTION NAME: ";
            cout << root->children[i]->children[j]->label << endl;
        }
        cout << endl;
    }
}

int main()
{
    cout << "choose\n1. To Enter The Tree \n2. To Display The Tree \n3. To Stop\n";
    int choice;
    cin >> choice;
    struct node *root = new struct node;
    root = NULL;
    while (choice != 3)
    {
        if (choice == 1)
        {
            root = TreeBuild();
        }
        else if (choice == 2)
        {
            if (root == NULL)
            {
                cout << "No Tree To Display First Build The tree." << endl;
            }
            else
            {
                displayTree(root);
            }
        }
        else
        {
            cout << "Enter Valid Choice\n";
        }
        cout << "choose\n1. To Enter The Tree \n2. To Display The Tree \n3. To Stop\n";
        cin >> choice;
    }
}

// dsa 2 trees 2 bst gt hashmap 2 hashing collision