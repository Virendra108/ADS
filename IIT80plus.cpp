#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int marks;
    string name;

public:
    Student() {}
    Student(int m, string n) : marks(m), name(n) {}

    int getMarks() const { return marks; }
    string getName() const { return name; }
};

class BST {
private:
    struct Node {
        Student student;
        Node* left;
        Node* right;
    };

    Node* root;

public:
    BST() : root(nullptr) {}

    Node* insert(Node* node, const Student& student) {
        if (node == nullptr) {
            node = new Node;
            node->student = student;
            node->left = nullptr;
            node->right = nullptr;
        } else if (student.getMarks() > node->student.getMarks()) {
            node->right = insert(node->right, student);
        } else {
            node->left = insert(node->left, student);
        }
        return node;
    }

    void displaySelectedStudents(Node* node) const {
        if (node == nullptr) {
            return;
        }
        // Traverse the right subtree (marks > 80)
        displaySelectedStudents(node->right);
        // Display students with marks > 80
        if (node->student.getMarks() > 80) {
            cout << "Name: " << node->student.getName() << ", Marks: " << node->student.getMarks() << endl;
        }
        // Traverse the left subtree (marks <= 80)
        displaySelectedStudents(node->left);
    }

    void acceptStudents() {
        int numStudents;
        cout << "Enter the number of students: ";
        cin >> numStudents;

        for (int i = 0; i < numStudents; ++i) {
            string name;
            int marks;
            cout << "Enter name of student " << i + 1 << ": ";
            cin >> name;
            cout << "Enter marks of student " << i + 1 << ": ";
            cin >> marks;
            Student student(marks, name);
            root = insert(root, student);
        }
    }

    void displaySelectedStudents() const {
        cout << "Students selected for IIT college (marks > 80):" << endl;
        displaySelectedStudents(root);
    }
};

int main() {
    BST bst;
    bst.acceptStudents();
    cout << endl;
    bst.displaySelectedStudents();
    return 0;
}
