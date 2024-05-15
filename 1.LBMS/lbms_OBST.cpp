#include <iostream>
#include <string>
#include <iomanip>
#define max 20
using namespace std;

class Book {
    string name, author;
    double price;
    Book *lchild, *rchild;

public:
    void accept();
    void insert(Book *root, Book *next);
    void display(Book *root);
    void update(Book *root, const string &name);
    Book* deleteBook(Book *root, const string &name);
    void maxPrice(Book *root);
} *root, *st[max];

void Book::accept() {
    Book *next;
    char choice;
    root = new Book;
    cout << "Enter details of the book:\n";
    cout << "Enter the book name: ";
    cin.ignore();
    getline(cin, root->name);
    cout << "Enter author of the book: ";
    getline(cin, root->author);
    cout << "Enter price: ";
    cin >> root->price;
    root->lchild = root->rchild = NULL;

    do {
        cout << "\nDo you want to add more book information (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            next = new Book;
            cout << "\nEnter details of the book:\n";
            cout << "Enter the book name: ";
            cin.ignore();
            getline(cin, next->name);
            cout << "Enter author of the book: ";
            getline(cin, next->author);
            cout << "Enter price: ";
            cin >> next->price;
            next->lchild = next->rchild = NULL;
            insert(root, next);
        }
    } while (choice == 'y' || choice == 'Y');
}

void Book::insert(Book *root, Book *next) {
    if (root->price > next->price) {
        if (root->lchild == NULL) {
            root->lchild = next;
        } else {
            insert(root->lchild, next);
        }
    } else if (root->price < next->price) {
        if (root->rchild == NULL) {
            root->rchild = next;
        } else {
            insert(root->rchild, next);
        }
    }
}

void Book::display(Book *root) {
    cout << endl;
    cout << setw(20) << left << "Book Name";
    cout << setw(20) << left << "Author";
    cout << setw(10) << left << "Price";
    cout << endl;

    int top = -1;
    Book *temp;
    temp = root;

    if (temp != NULL) {
        do {
            while (temp != NULL) {
                top++;
                st[top] = temp;
                temp = temp->lchild;
            }
            if (top != -1) {
                temp = st[top];
                cout << setw(20) << left << temp->name;
                cout << setw(20) << left << temp->author;
                cout << setw(10) << left << temp->price;
                cout << endl;
                temp = temp->rchild;
            }
            top--;
        } while (temp != NULL || top != -1);
    }
}

void Book::update(Book *root, const string &name) {
    if (root == NULL) {
        cout << "Book not found.\n";
        return;
    }

    if (root->name == name) {
        cout << "Enter new details of the book:\n";
        cout << "Enter the book name: ";
        cin.ignore();
        getline(cin, root->name);
        cout << "Enter author of the book: ";
        getline(cin, root->author);
        cout << "Enter price: ";
        cin >> root->price;
        cout << "Book details updated successfully.\n";
    } else if (root->name > name) {
        update(root->lchild, name);
    } else {
        update(root->rchild, name);
    }
}

Book* Book::deleteBook(Book *root, const string &name) {
    if (root == NULL) {
        cout << "Book not found.\n";
        return root;
    }

    if (name < root->name) {
        root->lchild = deleteBook(root->lchild, name);
    } else if (name > root->name) {
        root->rchild = deleteBook(root->rchild, name);
    } else {
        // Node with only one child or no child
        if (root->lchild == NULL) {
            Book *temp = root->rchild;
            delete root;
            return temp;
        } else if (root->rchild == NULL) {
            Book *temp = root->lchild;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Book *temp = root->rchild;
        while (temp && temp->lchild != NULL)
            temp = temp->lchild;

        // Copy the inorder successor's content to this node
        root->name = temp->name;
        root->author = temp->author;
        root->price = temp->price;

        // Delete the inorder successor
        root->rchild = deleteBook(root->rchild, temp->name);
    }
    return root;
}

void Book::maxPrice(Book *root) {
    cout << endl;
    cout << setw(20) << left << "Book Name";
    cout << setw(20) << left << "Author";
    cout << setw(10) << left << "Price";
    cout << endl;

    int top = -1;
    Book *temp;
    temp = root;

    if (temp != NULL) {
        while (temp != NULL) {
            top++;
            st[top] = temp;
            temp = temp->rchild;
        }
        if (top != -1) {
            temp = st[top];
            cout << "Book with maximum price is:\n";
            cout << setw(20) << left << temp->name;
            cout << setw(20) << left << temp->author;
            cout << setw(10) << left << temp->price;
            cout << endl;
        }
    }
}

int main() {
    Book b;
    int choice;
    char ch;
    string name;
    do {
        cout << "\n ------------------ MENU ----------------\n";
        cout << "1. Accept\n";
        cout << "2. Display\n";
        cout << "3. Update Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Display book with maximum price\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.accept();
                break;
            case 2:
                b.display(root);
                break;
            case 3:
                cout << "Enter the name of the book to update: ";
                cin.ignore();
                getline(cin, name);
                b.update(root, name);
                break;
            case 4:
                cout << "Enter the name of the book to delete: ";
                cin.ignore();
                getline(cin, name);
                root = b.deleteBook(root, name);
                break;
            case 5:
                b.maxPrice(root);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "\nWrong choice";
                break;
        }
        cout << "\nDo you want to continue (Y/N): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
