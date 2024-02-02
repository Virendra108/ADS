#include<iostream>
using namespace std;
class lms{
	int book_id,price,i,n;
	char *title,*auther,*pub,*isbn_no;
	public:
	void accept();
	void display();
	void search();
	void update();
	void Delete();
}b[100];

void lms::accept(){
	cout<<"enter the book_id,price,title,author,pub,isbn number :"<<endl;
	cin>>book_id>>price>>title>>auther>>pub>>isbn_no>>;
}
void lms::display(){
	cout<<"\n"<<book_id<<"\t"<<price<<"\t"<<title<<"\t"<<auther<<"\t"<<pub<<"\t"<<isbn_no<<endl;
	}
void lms::search(){
	int f=0;
	cout<<"enter book id: ";
	cin>>book_id;
	for(i=0;i<n;i++){
		if(book_id==b[i].book_id){
			f=1;
			cout<<"book id found";
			b[i].display();
			break;
		}
	}
	if(f==0){
		cout<<"book id not found";
	}
}
void lms::update(){
	cout<<"Enter the book id which you want to update: ";
	cin>>book_id;
	if(book_id==b[i].book_id){
		cout<<"enter book info which you want to update:";
		cout<<"book id";
		cin>>b[i].price;
		cout<<"title";
		cin>>b[i].auther;
		cout<<"publsher";
		cin>>b[i].pub;
	}
}
void lms::Delete(){
	cout<<"Enter the book id :";
	cin>>book_id;
	for(i=0;i<n;i++){
		if(book_id==b[i].book_id){
			do{
				b[i]=b[i+1];
				i+1;
			}
			while(i<n);
			n--;
			break;
		}
	}
}
int main(){
	int choice;
	do{
		cout<<"\n1.accept";
		cout<<"\n2.display";
		cout<<"\n3.search";
		cout<<"\n4.update";
		cout<<"\n5.delete";
		cout<<"\n6.exit";
		cout<<"\nenter your choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
			for(i=0;i<n;i++){
				b[i].accept();
			}
			case 2:
			for(i=0;i<n;i++){
				b[i].display();
			}
			case 3:
			for(i=0;i<n;i++){
				b[i].search();
			}
			case 4:
			for(i=0;i<n;i++){
				b[i].update();
			}
			case 5:
			for(i=0;i<n;i++){
				b[i].delete();
			}
			case 6:
			exit;
			default:
		}while(choice!=6);
		}
