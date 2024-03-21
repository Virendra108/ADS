#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class cms
{
public:
    int id, amount;
    long int phone;
    string donorName, city;
    cms *next, *prev;
    void accept();
    void display();
    void search();
    void update();
    void Delete();
    void swapdata(cms *a, cms *b);
    void sort();
    // void sort();
    void count();
} *start, *end1;


void cms::accept()
{   
    cout << "\n--------------Enter data---------------\n"
                 << endl;
    cms *newnode;
    int f = 0;
    newnode = new cms;
    newnode->next = newnode->prev = 0;

    cout << endl
         << "Enter donor ID: ";
    cin >> newnode->id;

    if (start == 0)
    {
        cout << endl
             << "Enter donor name: ";
        cin >> newnode->donorName;
        cout << endl
             << "Enter amount donated: ";
        cin >> newnode->amount;
        cout << endl
             << "Enter donor Contact number: ";
        cin >> newnode->phone;
        cout << endl
             << "Enter Address: ";
        cin >> newnode->city;
        end1 = start = newnode;
    }
    else
    {
        cms *temp = start;
        while (temp != 0)
        {
            if (temp->id == newnode->id)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            cout << endl
                 << "Enter donor name: ";
            cin >> newnode->donorName;
            cout << endl
                 << "Enter amount donated: ";
            cin >> newnode->amount;
            cout << endl
                 << "Enter donor Contact number: ";
            cin >> newnode->phone;
            cout << endl
                 << "Enter Address: ";
            cin >> newnode->city;
            end1->next = newnode;
            newnode->prev = end1;
            end1 = newnode;
        }
        else
        {
            cout << "\nError: ID already exists" << endl;
        }
    }
}
void cms::display()
{
    cout << "\n--------------Charity Data---------------\n"
                 << endl;
    cms *temp = start;
    if (temp == NULL)
    {
        cout << "\nList is empty.";
    }
    else
    {
        cout << setw(10) << left << "Donor ID";
        cout << setw(20) << left << "Donor name";
        cout << setw(20) << left << "Amount donated";
        cout << setw(20) << left << "Contact no.";
        cout << setw(10) << left << "Address";

        while (temp != NULL)
        {
            cout << endl;
            cout << setw(10) << left << temp->id;
            ;
            cout << setw(20) << left << temp->donorName;
            cout << setw(20) << left << temp->amount;
            cout << setw(20) << left << temp->phone;
            cout << setw(10) << left << temp->city;

            temp = temp->next;
        }
    }
}

void cms::search()
{
    int bid, flag = 0;
    cms *temp = start;

    cout << "\nEnter the id of the donor you want to search: ";
    cin >> bid;
    while (temp != NULL)
    {
        if (bid == temp->id)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        cout << "\nDonor found." << endl;
        cout << setw(10) << left << "Donor ID";
        cout << setw(20) << left << "Donor name";
        cout << setw(20) << left << "Amount donated";
        cout << setw(20) << left << "Contact no.";
        cout << setw(10) << left << "Address";

        while (temp != NULL)
        {
            cout << endl;
            cout << setw(10) << left << temp->id;
            ;
            cout << setw(20) << left << temp->donorName;
            cout << setw(20) << left << temp->amount;
            cout << setw(20) << left << temp->phone;
            cout << setw(10) << left << temp->city;

            temp = temp->next;
        }
    }
    else
    {
        cout << "\nDonor not found";
    }
}

void cms::update()
{
    cms *temp = start;
    int id1, ch3, amount1, flag1 = 0;
    long int phone1;
    string name1, address1;
    cout << "\nEnter the donor ID whose details you want to update: ";
    cin >> id1;
    while (temp != NULL)
    {
        if (temp->id == id1)
        {
            flag1 = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag1 == 0)
    {
        cout << "\nDonor ID not found.";
    }
    else
    {

        cout << "\nWhat do you want to update?\n1.Donor name\n2.Donation amount\n3.Contact number\n4.Address\nEnter your choice: ";
        cin >> ch3;
        switch (ch3)
        {
        case 1:
            cout << "\nEnter new donor name: ";
            cin >> name1;
            temp->donorName = name1;
            break;

        case 2:
            cout << "\nEnter new donation amount: ";
            cin >> amount1;

            temp->amount = amount1;

            break;
        case 3:
            cout << "\nEnter new Contact number: ";
            cin >> phone1;

            temp->phone = phone1;

            break;

        case 4:
            cout << "\nEnter new address: ";
            cin >> address1;

            temp->city = address1;

            break;

        default:
            cout << "\nInvalid choice.";
            break;
        }
        cout << "\nData updated.";
    }
}

void cms::Delete()
{
    int id1;
    cout << "\nEnter the ID of the donor you want to delete: ";
    cin >> id1;
    cms *temp = start, *p;
    // delete first node
    if (start->id == id1)
    {
        start = temp->next;
        temp->next->prev = 0;
        delete temp;
        cout << "\nRecord deleted";
    }
    // delete last node
    else if (end1->id == id1)
    {
        p = end1;
        end1 = end1->prev;
        end1->next = 0;
        delete (p);
        cout << "\nRecord deleted." << endl;
    }
    // delete any node
    else
    {
        while (temp != 0)
        {
            if (temp->next->id == id1)
            {
                p = temp->next;
                temp->next = p->next;
                p->next->prev = temp;
                delete (p);
                cout << "\nRecord deleted.";
                break;
            }
            temp = temp->next;
        }
    }
}
void cms::count()
{
    cms *temp = start;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << "\nTotal number of donors: " << cnt << endl;
}

void cms::swapdata(cms *a, cms *b)
{
    cms *temp;
    temp->id = a->id;
    temp->donorName = a->donorName;
    temp->amount = a->amount;
    temp->phone = a->phone;
    temp->city = a->city;

    a->id = b->id;
    a->donorName = b->donorName;
    a->amount = b->amount;
    a->phone = b->phone;
    a->city = b->city;

    b->id = temp->id;
    b->donorName = temp->donorName;
    b->amount = temp->amount;
    b->phone = temp->phone;
    b->city = temp->city;
}

void cms::sort()
{
    cms *i, *j;
    for (i = start; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->id > j->id)
            {
                swapdata(i, j);
            }
        }
    }
    cout << "\nData sorted by donor ID." << endl;
}
int main()
{
    cms *ptr;
    int ch;
    char ch1;
    do
    {
        cout << "\n\nWhat do you want to do?: \n1.Accept data\n2.Display data\n3.Search donor\n4.Update\n5.Delete\n6.Count number of donors\n7.Sort\n8.Exit\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ptr->accept();
            break;
        case 2:
            ptr->display();
            break;
        case 3:
            ptr->search();
            break;
        case 4:
            ptr->update();
            break;
        case 5:
            ptr->Delete();
            break;
        case 6:
            ptr->count();
            break;
        case 7:
            ptr->sort();
            break;
        case 8:
            exit(0);
        default:
            cout << "\nInvalid choice.";
        }
        cout << "\nDo you want to continue?(y/n): ";
        cin >> ch1;
    } while (ch1 == 'y'||ch1=='Y');
    return 0;
}
