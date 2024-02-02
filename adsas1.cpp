#include<iostream>
#include <cstring>
using namespace std;
class lms{
	int book_id,price,i,n;
	char *title,*author,*pub,*isbn_no;
	public:
	void accept();
	void display();
	void search();
	void update();
	void Delete();
}b[100];

void lms::accept(){
    cout << "Enter the book_id, price, title, author, publisher, isbn number: " << endl;
    scanf("%d %d", &book_id, &price);

    title = new char[50];
    author = new char[50];
    pub = new char[50];
    isbn_no = new char[20];

    scanf("%s", title);
    scanf("%s", author);
    scanf("%s", pub);
    scanf("%s", isbn_no);
}
void lms::display(){
	cout<<"\n"<<book_id<<"\t"<<price<<"\t"<<title<<"\t"<<author<<"\t"<<pub<<"\t"<<isbn_no<<endl;
	}
void lms::search(){
	int search_id, f = 0;
    cout << "Enter book id: ";
    cin >> search_id;
    for (i = 0; i < n; i++) {
        if (search_id == b[i].book_id) {
            f = 1;
            cout << "Book id found";
            b[i].display();
            break;
        }
    }
    if (f == 0) {
        cout << "Book id not found";
    }
}
void lms::update(){
	cout << "Enter the book id you want to update: ";
    scanf("%d", &book_id);
    for (int i = 0; i < n; i++) {
        if (book_id == b[i].book_id) {
            cout << "Enter updated information: " << endl;
            cout << "Price: ";
            scanf("%d", &b[i].price);
            cout << "Title: ";
            scanf("%s", b[i].title);
            cout << "Author: ";
            scanf("%s", b[i].author);
            cout << "Publisher: ";
            scanf("%s", b[i].pub);
            break;
        }
    }
	
}
void lms::Delete(){
	
    cout << "Enter the book id to delete: ";
    scanf("%d", &book_id);
    for (int i = 0; i < n; i++) {
        if (book_id == b[i].book_id) {
            delete[] b[i].title;
            delete[] b[i].author;
            delete[] b[i].pub;
            delete[] b[i].isbn_no;

            do {
                b[i] = b[i + 1];
                i++;
            } while (i < n);
            n--;
            cout << "Book deleted successfully." << endl;
            break;
        }
    }
}
int main(){
	int choice,i,n=0;
	do{
		cout<<"\n1.accept";
		cout<<"\n2.display";
		cout<<"\n3.search";
		cout<<"\n4.update";
		cout<<"\n5.delete";
		cout<<"\n6.exit";
		cout<<"\nenter your choice: "<<endl;
		scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < 100) {
                    b[n].accept();
                    n++;
                } else {
                    cout << "Library is full. Cannot accept more books." << endl;
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    b[i].display();
                }
                break;
            case 3:
                for (int i = 0; i < n; i++) {
                    b[i].search();
                }
                break;
            case 4:
                for (int i = 0; i < n; i++) {
                    b[i].update();
                }
                break;
            case 5:
                for (int i = 0; i < n; i++) {
                    b[i].Delete();
                }
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}