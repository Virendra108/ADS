#include<iostream>
#include<string>
#include<iomanip>
#define max 20 
using namespace std ;
int count,count1,count2 ;
class employee
{
      int salary,eid ;
      string name, address ;
      employee *lchild, *rchild ;
      public :
            void accept() ;
            void insert(employee *root, employee *next) ;
            void display(employee *root);
            void leaf(employee *root);
            void countGen() ;
}*root, *st[max];
void employee :: accept()
{
     
     employee *next ;
     char choice;
     root = new employee ;
     cout<<"Enter details of the employee: \n" ;
     cout<<"Enter the employee ID :" ;
     cin>>root->eid ;
     cout<<"Enter name of the employee :" ;
     cin>>root->name ;
     cout<<"Enter salary :" ;
     cin>>root->salary ;
     cout<<"Enter address: " ;
     cin>>root->address ;
     cout<<endl;
     root->lchild =root->rchild = NULL ;
     count++ ;
     count1 = count2 = count ;
     do
     {
           cout<<"\nDo you want to add more employee information (y/n):" ;
            cin >> choice ;
           if(choice == 'y'||choice=='Y')
          {
                next = new employee ;
                cout << "\nEnter details of the employee -->\n";
                cout << "\nEnter employee ID :";
                cin >> next->eid;
                cout << "\nEnter name of the employee :";
                cin >> next->name;
                cout << "\nEnter salary: ";
                cin >> next->salary;
                cout << "\nEnter address: ";
                cin >> next->address;
                next->lchild = next->rchild = 0;
                insert(root, next);
          }
          
     }while(choice == 'y'||choice=='Y') ;
}
void employee :: insert(employee *root, employee *next)
{
    //char chr ;
    //cout<<"\nDo you want to insert to the right or to the left of member \""<<root->name<<"\"\t(L/R): " ;
    //cin>>chr ;
    if(root->salary>next->salary)
    {
          if( root->lchild == NULL)
          {
               root->lchild = next ;
               count1++;
          }
          else
          {
              insert(root->lchild , next) ;
          }
    }
    else if(root->salary<next->salary)
    {
          if( root->rchild == NULL)
          {
               root->rchild = next ;
               count2++;
          }
          else
          {
              insert(root->rchild , next) ;
          }
    }   
}
void employee :: display(employee *root)
{   cout<<endl;
    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
    cout<<setw(15)<<left <<"Employee ID";
    cout<<setw(20)<<left <<"Name";
    cout<<setw(15)<<left <<"Salary";
    cout<<setw(10)<<left <<"Address";
    cout<<endl;
      int top = -1 ;
      employee *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
          do
          {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
              }
              if(top != -1)
              {
                  temp = st[top];
                   cout<<setw(15)<<left <<temp->eid;
                  cout<<setw(20)<<left <<temp->name;
                  cout<<setw(15)<<left <<temp->salary;
                  cout<<setw(10)<<left <<temp->address<<endl;
                  //cout<<"\n"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void employee :: leaf(employee *root)
{
    cout<<setw(15)<<left <<"Employee ID";
    cout<<setw(20)<<left <<"Name";
    cout<<setw(15)<<left <<"Salary";
    cout<<setw(10)<<left <<"Address";
    cout<<endl;
      int top = -1 ;
      employee *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
          do
          {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
              }
              if(top != -1)
              {
                  temp = st[top];
                  if(temp->lchild == NULL && temp->rchild == NULL)
                  {
                  //cout<<"\n"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  cout<<setw(15)<<left <<temp->eid;
                  cout<<setw(20)<<left <<temp->name;
                  cout<<setw(15)<<left <<temp->salary;
                  cout<<setw(10)<<left <<temp->address<<endl;
                  }
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void employee :: countGen()
{
   if(count1 >= count2)
   {
      cout <<"\nHeight of employee tree is :"<<count1;
   }
   else
   {
       cout<<"\nHeight of employee tree is :"<<count2 ; 
   }
}
int main()
{
    employee e ;
    int choice ;
    char ch;
    do
    {
         cout<<"\n ------------------ MENU ----------------\n" ;
         cout<<"\n1.Accept" ;
         cout<<"\n2.Display" ;
         cout<<"\n3.Display Leaf Node" ;
         cout<<"\n4.Count Height of the Employee tree" ;
         cout<<"\n5.Exit" ;
         cout<<"\nEnter your choice :" ;
         cin>>choice ;
         cout<<endl<<endl;
         switch(choice)
         {
              case 1 :
                    e.accept() ;
                    break ;
              case 2 :
                    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    e.display(root) ;
                    break ;
              case 3 :
                    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    e.leaf(root);
                    break ;
              case 4 :
                    e.countGen() ;
                    break ;
              case 5 :
                    exit(0) ;
                    break ;
             default  :
                    cout<<"\nWrong choice" ;
                    break ;
         }
         cout<<"\nDo you want to continue(Y/N) :" ;
         cin >> ch ;
   }while(ch == 'y'||ch=='Y');
    return 0 ;
    
}
