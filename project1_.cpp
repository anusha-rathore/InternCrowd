#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
class node
{
public:
    string name;
    string bdy;
    int date, year;
    string month;
    node *next;

    node()
    {
        next = NULL;
    }
};
class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insert(string name, int date, string month, int year)
    {
        node *temp = new node();
        temp->name = name;
        temp->date = date;
        temp->month = month;
        temp->year = year;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
    void Edit(node *temp)
    {
        cout << "Enter what you wants to edit  your name or Birthdate:" << endl;
        cout << "1. Edit your Name " << endl;
        cout << "2. Edit your Birthdate " << endl;
        cout << "3.Edit your  birth Month " << endl;
        cout << "4. Edit your birth year " << endl;
        cout << "5.exit";
        int choice;
        cout << "Enter your Choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string n;
            cout << "Enter your Name : ";
            cin.ignore();
            getline(cin, n);

            temp->name = n;
            break;
        }
        case 2:
        {
            int d;
            cout << "Enter your birthdate :";
            cin >> d;
            temp->date = d;
            break;
        }
        case 3:
        {
            string m;
            cout << "Enter your month : ";
            cin >> m;
            temp->month = m;
            break;
        }
        case 4:
        {
            int y;
            cout << "Enter your year :" << endl;
            cin >> y;
            temp->year = y;
            break;
        }
        case 5:
        {
            exit(0);
        }
        }
    }
    node *search(string name)
    {
        node *temp = head;

        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            int count = 0;
            while (temp != NULL)
            {
                count++;
                if (temp->name == name)
                {
                    cout << "Name found" << endl;
                    return temp;
                }

                temp = temp->next;
            }
            cout << "Name Not Found" << endl;
            return NULL;
        }
    }
    void Show()
    {
        node *t = head;
        while (t != NULL)
        {
            cout << "\nName :" << t->name << endl;
            cout << "DOB : " << t->date << "\\" << t->month << "\\" << t->year << endl;
            t = t->next;
        }
        cout << endl
             << endl;
    }
};
int main()
{
    LinkedList ll;
    while (1)
    {
        string name;
        int date, year;
        string month;

        int choice;
        cout << "1. Create Birthday List" << endl;
        cout << "2. Edit List" << endl;
        cout << "3. Show List" << endl;
        cout << "4. Serach Your Name: " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter your Choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter your name:" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter your Birthdate: " << endl;
            cin >> date >> month >> year;
            ll.insert(name, date, month, year);
            break;
        }
        case 2:
        {
            string s;
            cout << "Enter your name for Edit your list:" << endl;
            cin.ignore();
            getline(cin, s);
            node *x = ll.search(s);
            if (x != NULL)
                ll.Edit(x);
            else
                cout << "\nName not found";
            break;
        }
        case 3:
        {
            cout << "=====================================================================================" << endl;
            cout << "||                            Birthday list :                                     ||  " << endl;
            cout << "=====================================================================================" << endl;

            ll.Show();
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter your Name which you want to Search:";
            cin.ignore();
            getline(cin, name);

            break;
        }
        case 5:
            exit(0);
        }
    }
    return 0;
}