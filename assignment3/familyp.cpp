
#include<iostream>
#include<string>
#include<iomanip>
#define max 20 
using namespace std ;
int count,count1,count2 ;
class family
{
      int age,ger ;
      string name, gen ;
      family *lchild, *rchild ;
      public :
            void accept() ;
            void insert(family *root, family *next) ;
            void display(family *root);
            void leaf(family *root);
            void countGen() ;
}*root, *st[max];
void family :: accept()
{
     
     family *next ;
     char choice;
     root = new family ;
     cout<<"Enter details of the family member: \n" ;
     cout<<"Enter the generation number :" ;
     cin>>root->ger ;
     cout<<"Enter name of the family member :" ;
     cin>>root->name ;
     cout<<"Enter age :" ;
     cin>>root->age ;
     cout<<"Enter gender: " ;
     cin>>root->gen ;
     cout<<endl;
     root->lchild =root->rchild = NULL ;
     count++ ;
     count1 = count2 = count ;
     do
     {
           cout<<"\nDo you want to add more family information (y/n):" ;
            cin >> choice ;
           if(choice == 'y'||choice=='Y')
          {
                next = new family ;
                cout << "\nEnter details of the family member -->\n";
                cout << "\nEnter generation number :";
                cin >> next->ger;
                cout << "\nEnter name of the family member :";
                cin >> next->name;
                cout << "\nEnter age: ";
                cin >> next->age;
                cout << "\nEnter gender: ";
                cin >> next->gen;
                next->lchild = next->rchild = 0;
                insert(root, next);
          }
          
     }while(choice == 'y'||choice=='Y') ;
}
void family :: insert(family *root, family *next)
{
    char chr ;
    cout<<"\nDo you want to insert to the right or to the left of member \""<<root->name<<"\"\t(L/R): " ;
    cin>>chr ;
    if(chr == 'l' || chr == 'L')
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
    else if(chr == 'r' || chr == 'R')
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
void family :: display(family *root)
{   cout<<endl;
    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
    cout<<setw(15)<<left <<"generation";
    cout<<setw(20)<<left <<"Name";
    cout<<setw(15)<<left <<"Age";
    cout<<setw(10)<<left <<"Gender";
    cout<<endl;
      int top = -1 ;
      family *temp ;
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
                   cout<<setw(15)<<left <<temp->ger;
                  cout<<setw(20)<<left <<temp->name;
                  cout<<setw(15)<<left <<temp->age;
                  cout<<setw(10)<<left <<temp->gen<<endl;
                  //cout<<"\n"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void family :: leaf(family *root)
{
    cout<<setw(15)<<left <<"generation";
    cout<<setw(20)<<left <<"Name";
    cout<<setw(15)<<left <<"Age";
    cout<<setw(10)<<left <<"Gender";
    cout<<endl;
      int top = -1 ;
      family *temp ;
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
                  cout<<setw(15)<<left <<temp->ger;
                  cout<<setw(20)<<left <<temp->name;
                  cout<<setw(15)<<left <<temp->age;
                  cout<<setw(10)<<left <<temp->gen<<endl;
                  }
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void family :: countGen()
{
   if(count1 >= count2)
   {
      cout <<"\nHeight of family tree is :"<<count1;
   }
   else
   {
       cout<<"\nHeight of Family tree is :"<<count2 ; 
   }
}
int main()
{
    family f ;
    int choice ;
    char ch;
    do
    {
         cout<<"\n ------------------ MENU ----------------\n" ;
         cout<<"\n1.Accept" ;
         cout<<"\n2.Display" ;
         cout<<"\n3.Display Leaf Node" ;
         cout<<"\n4.Count Generations" ;
         cout<<"\n5.Exit" ;
         cout<<"\nEnter your choice :" ;
         cin>>choice ;
         cout<<endl<<endl;
         switch(choice)
         {
              case 1 :
                    f.accept() ;
                    break ;
              case 2 :
                    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    f.display(root) ;
                    break ;
              case 3 :
                    //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    f.leaf(root);
                    break ;
              case 4 :
                    f.countGen() ;
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
