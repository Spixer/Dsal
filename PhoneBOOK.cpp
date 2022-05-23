#include <iostream>
using namespace std;

class hashnode
{
public:
    string key;
    long phoneNumber;
    int probes;
    hashnode()
    {
        key = "";
        phoneNumber = 0;
        probes = 0;
    }
};

class hashmap
{
public:
    hashnode linear[10], quadratic[10];
    int hashfunction(string key);
    void linearInsert();
    void quadraticInsert();
    void displaylinear();
    void displayQuadratic();
    int sqaure(int a) { return a * a; };
};

int hashmap::hashfunction(string key)
{
    int sum = 0;
    for (int i = 0; i < key.size(); i++)
    {
        sum = sum + key[i];
    }
    int hashindex = (sum) % 10;
    return hashindex;
}

void hashmap::linearInsert()
{
    cout << "Enter the number of entries ";
    int entries;
    cin >> entries;

    for (int i = 0; i < entries; i++)
    {
        string name;
        long number;
        bool full = false;
        cout << "Enter the name ";
        cin >> name;
        cout << "Enter the Phone Number ";
        cin >> number;

        int hashindex = hashfunction(name);
        int iterator = hashindex;
        int p = 0;
        for (;;)
        {
            if (linear[iterator].phoneNumber == 0)
            {
                linear[iterator].key = name;
                linear[iterator].phoneNumber = number;
                linear[iterator].probes = p;
                break;
            }

            iterator = (++iterator) % 10;
            p++;

            if (iterator == hashindex)
            {
                cout << "hashmap is full for linear probing\n";
                full = true;
                break;
            }
        }
        if (full)
            break;
    }
    quadraticInsert();
}

void hashmap::quadraticInsert()
{
    for (int j = 0; j < 10; j++)
    {
        if (linear[j].phoneNumber == 0)
            continue;

        string name;
        long number;
        bool full = false;
        name = linear[j].key;
        number = linear[j].phoneNumber;

        int hashindex = hashfunction(name);
        int iterator = hashindex;
        int k = 1, p = 0;
        for (;;)
        {
            if (quadratic[iterator].phoneNumber == 0)
            {
                quadratic[iterator].key = name;
                quadratic[iterator].phoneNumber = number;
                quadratic[iterator].probes = p;
                break;
            }

            iterator = (iterator + sqaure(k++)) % 10;
            p++;

            if (iterator == hashindex)
            {
                cout << "hasmap is full for quadratic probing\n";
                full = true;
                break;
            }
        }
        if (full)
            break;
    }
}

void hashmap::displaylinear()
{
    cout << "\nhashmap with linear probing\n";
    cout << "name\t\t||PhoneNumber\t||Probes\n";
    for (int i = 0; i < 10; i++)
    {
        if (linear[i].key == "\0")
            continue;

        cout << linear[i].key << "\t\t||" << linear[i].phoneNumber << "\t\t||" << linear[i].probes << endl;
    }
    cout << "\nhashmap with Quadratic probing\n";
    cout << "name\t\t||PhoneNumber\t||Probes\n";
    displayQuadratic();
}

void hashmap::displayQuadratic()
{
    for (int i = 0; i < 10; i++)
    {
        if (quadratic[i].key == "\0")
            continue;

        cout << quadratic[i].key << "\t\t||" << quadratic[i].phoneNumber << "\t\t||" << quadratic[i].probes << endl;
    }
}

int main()
{
    hashmap h1;
    h1.linearInsert();
    h1.displaylinear();
}