#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int info;
    string name;
    Node* next;
};
class LinkList
{
private:
    Node* list;
public:
    LinkList()
    {
        list = NULL;
    }
    void InsertAtEnd(int element, string n)
    {
        Node* newNode = new Node;
        newNode->info = element;
        newNode->name = n;
        newNode->next = NULL;
       if (list == NULL)
        {
            list = newNode;
            return;
        }
        Node* temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void DeleteAtEnd()
    {
        if (list == NULL)
        {
            cout << "There is no node in the list" << endl;
            return;
        }
        if (list->next == NULL)
        {
            delete list;
            list = NULL;
            return;
        }
        Node* temp = list;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void InsertAtStart(int element, string n)
    {
        Node* newNode = new Node;
        newNode->info = element;
        newNode->name = n;
        newNode->next = list;
        list = newNode;
    }
    void DeleteAtStart()
    {
        if (list == NULL)
        {
            cout << "There is no node in the list" << endl;
            return;
        }
        Node* temp = list;
        list = list->next;
        delete temp;
    }
    void InsertAtMiddle(int element, string n, int position)
    {
        if (position == 1)
        {
            InsertAtStart(element, n);
            return;
        }
        Node* newNode = new Node;
        newNode->info = element;
        newNode->name = n;
        Node* temp = list;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position is out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void DeleteAtMiddle(int position)
    {
        if (list == NULL)
        {
            cout << "There is no node in the list" << endl;
            return;
        }
        if (position == 1)
        {
            DeleteAtStart();
            return;
        }
        Node* temp = list;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position is out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    void Display()
    {
        if (list == NULL)
        {
            cout << "There is no node in the list" << endl;
            return;
        }
        Node* temp = list;
        while (temp != NULL)
        {
            cout << "ID: " << temp->info << " Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
    void searchByID(int id)
    {
        Node* temp = list;
        while (temp != NULL)
        {
            if (temp->info == id)
            {
                cout << "Found: ID: " << temp->info << " Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "ID not found" << endl;
    }
    void searchByName(string name)
    {
        Node* temp = list;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "Found: ID: " << temp->info << " Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Name not found" << endl;
    }
    void DisplaySortedByID()
    {
        if (list == NULL)
        {
            cout << "There is no node in the list" << endl;
            return;
        }
        Node* current = list;
        while (current != NULL)
        {
            Node* temp = current->next;
            while (temp != NULL)
            {
                if (current->info > temp->info)
                {
                    int id = current->info;
                    string name = current->name;
                    current->info = temp->info;
                    current->name = temp->name;
                    temp->info = id;
                    temp->name = name;
                }
                temp = temp->next;
            }
            current = current->next;
        }
        Display();
    }
};
int main()
{
    LinkList list;
    int id;
    string name;
    int choice;
    do
    {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Insert at start" << endl;
        cout << "2. Delete at start" << endl;
        cout << "3. Insert at middle" << endl;
        cout << "4. Delete at middle" << endl;
        cout << "5. Insert at end" << endl;
        cout << "6. Delete at end" << endl;
        cout << "7. Search by ID or Name" << endl;
        cout << "8. Display All" << endl;
        cout << "9. Display Sorted by ID" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            list.InsertAtStart(id, name);
            break;
        }
        case 2:
        {
            list.DeleteAtStart();
            break;
        }
        case 3:
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            int position;
            cout << "Enter position to insert: ";
            cin >> position;
            list.InsertAtMiddle(id, name, position);
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            list.DeleteAtMiddle(position);
            break;
        }
        case 5:
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            list.InsertAtEnd(id, name);
            break;
        }
        case 6:
        {
            list.DeleteAtEnd();
            break;
        }
        case 7:
        {
            int searchChoice;
            cout << "Search by:" << endl;
            cout << "1. ID" << endl;
            cout << "2. Name" << endl;
            cout << "Enter your choice: ";
            cin >> searchChoice;
            if (searchChoice == 1)
            {
                cout << "Enter ID to search: ";
                cin >> id;
                list.searchByID(id);
            }
            else if (searchChoice == 2)
            {
                cout << "Enter Name to search: ";
                cin >> name;
                list.searchByName(name);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 8:
        {
            list.Display();
            break;
        }
        case 9:
        {
            list.DisplaySortedByID();
            break;
        }
        case 10:
        {
            cout << "Exiting" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } 
    while (choice != 10);
    return 0;
}