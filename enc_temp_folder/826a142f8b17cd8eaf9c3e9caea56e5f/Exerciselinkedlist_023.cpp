#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** previous, Node** current);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() {
    Node* newnode = new Node();
    newnode->rollNumber = 1; // Menambahkan pengguna nomor 1
    newnode->name = "YOGI"; // Menambahkan nama pengguna 
    newnode->next = NULL;

    if (LAST == NULL) { // Menambahkan list ke empty
        LAST = newnode;
        newnode->next = LAST; //  referensi circular
    }
    else { //  list yang salah   tidak masuk ke empty
        Node* current = LAST->next;
        Node* previous = LAST;

        while (current != LAST && current->rollNumber < newnode->rollNumber) {
            previous = current;
            current = current->next;
        }

        if (current == LAST) { // Memasukan data baru kedalam node untuk membuat data terakhir 
            newnode->next = LAST->next;
            LAST->next = newnode;
            LAST = newnode;
        }
        else { // Memasukan data baru ke 2
            newnode->next = current;
            previous->next = newnode;
        }
    }
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
    *previous = LAST->next;
    *current = LAST->next;

    while (*current != LAST) {
        if (rollno == (*current)->rollNumber) {
            return true;
        }
        *previous = *current;
        *current = (*current)->next;
    }

    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() {
    if (listEmpty()) {
        cout << "List is empty" << endl;
        return false;
    }
    else {
        Node* current = LAST->next;
        Node* successor = LAST->next->next;

        if (current == LAST) { 
            LAST = NULL;
            delete current;
            return true;
        }

        LAST->next = successor;
        delete current;
        return true;
    }
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "Records in the list are:" << endl;
        Node* currentNode = LAST->next;
        while (currentNode != LAST) {
            cout << currentNode->rollNumber << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

int main() {
    CircularLinkedList obj;

    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all the records in the liat" << endl;
            cout << "4. exit" << endl;
            cout << "\nEnter your choice (1-5): ";

            char ch;
            cin >> ch;

            switch (ch) {
            case '1': {

            }
            case '2': {

            }
            case '3': {

            }
            case '4': {

            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}