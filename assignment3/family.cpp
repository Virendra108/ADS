#include<iostream>
#include<string>
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
            void  insert(family *root, family *next) ;
            void display(family *root);
            void leaf(family *root);
            void countGen() ;
}*root, *st[max];
void family :: accept()
{
     
     family *next ;
     int choice;
     root = new family ;
     cout<<"Enter the details of family member" ;
     cout<<"\nEnter the generation no :" ;
     cin>>root->ger ;
     cout<<"\nEnter the name of family member :" ;
     cin>>root->name ;
     cout<<"\nEnter the age :" ;
     cin>>root->age ;
     cout<<"\nEnter the gender of family member :" ;
     cin>>root->gen ;
     root->lchild =root->rchild = NULL ;
     count++ ;
     count1 = count2 = count ;
     do
     {
           cout<<"\nDo you want to add more family information (1):" ;
            cin >> choice ;
           if(choice == 1)
          {
                next = new family ;
                cout<<"\nEnter the details of family member -->" ;
     		 cout<<"\nEnter the generation no :" ;
     		 cin>>next->ger ;
     		 cout<<"\nEnter the name of family member :" ;
     		 cin>>next->name ;
     		 cout<<"\nEnter the age :" ;
     		 cin>>next->age ;
     		 cout<<"\nEnter the gender of family member :" ;
     		 cin>>next->gen ;
     		 next -> lchild = next->rchild = 0 ;
     		 insert(root, next) ;
          }
          
     }while(choice == 1) ;
}
void family :: insert(family *root, family *next)
{
    char chr ;
    cout<<"\nDo you want to insert more family information :"<<root->name<<"\tL or R"<<endl ;
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
{
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
                  cout<<"\n"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void family :: leaf(family *root)
{
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
                  cout<<"\n"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
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
      cout <<"\n height is :"<<count1;
   }
   else
   {
       cout<<"\nHeight is :"<<count2 ; 
   }
}
int main()
{
    family f ;
    int ch, choice ;
    do
    {
         cout<<"\n ------------------ MENU ----------------\n" ;
         cout<<"\n1.Accept" ;
         cout<<"\n2.Display" ;
         cout<<"\n3.displayLeapNode" ;
         cout<<"\n4.CountGen" ;
         cout<<"\n5.Exit" ;
         cout<<"\nEnter the choice :" ;
         cin>>choice ;
         switch(choice)
         {
              case 1 :
                    f.accept() ;
                    break ;
              case 2 :
                    cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    f.display(root) ;
                    break ;
              case 3 :
                    cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
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
         cout<<"\nDo you want to continue(1/0) :" ;
         cin >> ch ;
   }while(ch == 1);
    return 0 ;
    
}




