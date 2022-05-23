#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class set
{
    vector<T> arr;

public:
    vector<T> &getarr()
    {
        return arr;
    }

    void copy(vector<T> &arr, vector<T> &arr2)
    {
        for (int i = 0; i < arr.size(); i++)
            arr2.push_back(arr[i]);
    }

    bool search(T data, vector<T> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == data)
                return true;
        }
        return false;
    }

    void removeDuplicates()
    {
        vector<T> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            bool check = search(arr[i], ans);

            if (!check)
                ans.push_back(arr[i]);
        }
        arr.clear();
        copy(ans, arr);
    }

    void removeDuplicates(vector<T> &arr)
    {
        vector<T> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            bool check = search(arr[i], ans);

            if (check == false)
                ans.push_back(arr[i]);
        }
        arr.clear();
        copy(ans, arr);
    }

    vector<T> intersection(vector<T> arr2)
    {
        vector<T> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            if (search(arr[i], arr2))
                ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<T> difference(vector<T> arr2)
    {
        vector<T> inter = intersection(arr2);
        vector<T> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (search(arr[i], inter) == false)
                ans.push_back(arr[i]);
        }
        return ans;
    }

    void print(vector<T> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";

        cout << "\n\n";
    }

    vector<T> Union(vector<T> arr2)
    {
        vector<T> uni;

        for (int i = 0; i < arr.size(); i++)
        {
            uni.push_back(arr[i]);
        }

        for (int i = 0; i < arr2.size(); i++)
        {
            uni.push_back(arr2[i]);
        }

        removeDuplicates(uni);

        return uni;
    }

    void takeInput()
    {
        cout << "Enter the elements of set and -1 to stop entering :    \n";
        T data;
        cin >> data;
        for (; data != -1;)
        {
            arr.push_back(data);
            cin >> data;
        }
        removeDuplicates();
    }

    void InsertElement(T element)
    {
        arr.push_back(element);
        removeDuplicates();
    }

    void removeElement(T element)
    {
        removeDuplicates();

        int position = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == element)
                position = i;
        }

        if (position != -1)
        {
            arr.erase(arr.begin() + position);
            cout << element << " was removed\n";
        }
        else
        {
            cout << "the element that you entered does not exist in the set\n";
        }
    }

    void menu(set s2)
    {
        cout << "choose :  \n1. insert element in set \n2. delete element from set \n3. search element in set \n4. union of set1 and set2 \n5. intersection of set1 and set2 \n6. differece of set1 and set2 \n-1. to stop \n\n";
        int choice;
        cin >> choice;
        while (choice != -1)
        {
            if (choice == 1)
            {
                cout << "Enter the element that you want to insert: ";
                T element;
                cin >> element;
                InsertElement(element);
                print(arr);
            }
            else if (choice == 2)
            {
                cout << "Enter the element that you want to remove: ";
                T element;
                cin >> element;
                removeElement(element);
                print(arr);
            }
            else if (choice == 3)
            {
                cout << "Enter the element that you want to search: ";
                T element;
                cin >> element;
                cout << "\nthe elment is " << (search(element, arr) ? "present " : "not present ") << "in the set\n";
                print(arr);
            }
            else if (choice == 4)
            {
                vector<int> uni = Union(s2.getarr());
                cout << "the union of set1 and se2 is :   \n";
                print(uni);
            }
            else if (choice == 5)
            {
                vector<int> inter = intersection(s2.getarr());
                cout << "the interesection of set1 and set2 is :   \n";
                print(inter);
            }
            else if (choice == 6)
            {
                vector<int> diff = difference(s2.getarr());
                cout << "the difference of set1 and set2 is :   \n";
                print(diff);
            }
            else
            {
                cout << "enter valid choice";
            }
            cout << "choose :  \n1. insert element in set1 \n2. delete element from set1 \n3. search element in set1 \n4. union of set1 and set2 \n5. intersection of set1 and set2 \n6. differece of set1 and set2 \n-1. to stop \n\n";
            cin >> choice;
        }
    }
};

int main()
{
    set<int> s1;
    set<int> s2;

    s1.takeInput();
    s2.takeInput();

    cout << "set1 after duplicates were removed: ";
    s1.print(s1.getarr());

    cout << "set2 after duplicates were removed: ";
    s2.print(s2.getarr());

    int choice;
    cout << "Choose: \n1. for operating on set1 \n2. for operating on set2 \n-1. to stop\n ";
    cin >> choice;

    while (choice != -1)
    {
        if (choice == 1)
            s1.menu(s2);
        else if (choice == 2)
            s2.menu(s1);
        else
            cout << "Enter valid option\n";
        cout << "Choose: \n1. for operating on set1 \n2. for operating on set2 \n-1. to stop\n ";
        cin >> choice;
    }

    cout << "Thank you!!!";
}

// 1 2 3 1 4 5 7 8 2 2 -1
// 3 5 2 5 7 8 9 9 0 1 -1