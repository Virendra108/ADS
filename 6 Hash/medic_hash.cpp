#include<iostream>
#include<iomanip>
using namespace std;
int key[30],c[30],n ,m;
int i;
class medicine
{
    public:
    int medicine_number;
    float price;
    string medicine_name,company_name;
    int expiry_year;
    void declare();
    void htable();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void medicine :: declare()
{   
    cout<<"Enter total number of medicine numbers : ";
    cin>>n;
    cout<<"Enter Medicine Numbers :  "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].medicine_number=-1;
        c[i]=0;
    }
}
void medicine :: htable()
{
    cout<<endl<<setw(15)<<left<<"Medicine Number";
    cout<<setw(10)<<left<<"Price ";
    cout<<setw(15)<<left<<"Medicine Name ";
    cout<<setw(20)<<left<<"Company Name ";
    cout<<setw(20)<<left<<"Expiry Year ";
    cout<<setw(20)<<left<<"Chain"<<endl;
    for(i=0;i<10;i++)
    {
        cout<<setw(15)<<left<<h[i].medicine_number;
        cout<<setw(10)<<left<<h[i].price;
        cout<<setw(15)<<left<<h[i].medicine_name;
        cout<<setw(20)<<left<<h[i].company_name;
        cout<<setw(20)<<left<<h[i].expiry_year;
        cout<<setw(20)<<left<<c[i]<<endl;
    }
}
void medicine :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].medicine_number==-1)
            {
                h[no].medicine_number=key[i];
                cout<<"\nEnter data for medicine number "<<key[i]<<'\n';
                cout<<"Medicine Name : ";
                cin>>h[no].medicine_name;
                cout<<"Company Name : ";
                cin>>h[no].company_name;
                cout<<"Price : ";
                cin>>h[no].price;
                cout<<"Expiry Year : ";
                cin>>h[no].expiry_year;
                cout<<"\n\n";
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
            }
        }while(no<10);
    }

}
void medicine :: search()
{
    int no,pos,med_no,found=0;
    cout<<"Enter Medicine Number you want to search : ";
    cin>>med_no;
    for(i=0;i<n;i++)
    {
        no=med_no%10;
        pos=no;
        do{
            if(h[no].medicine_number==med_no)
            {
                found=1;
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
            }
        }while(no<10);
    }
    if(found==1)
    {
        cout<<endl<<setw(15)<<left<<"Medicine Number";
        cout<<setw(10)<<left<<"Price ";
        cout<<setw(15)<<left<<"Medicine Name ";
        cout<<setw(20)<<left<<"Company Name ";
        cout<<setw(20)<<left<<"Expiry Year ";
        cout<<setw(20)<<left<<"Chain"<<endl;
        cout<<setw(15)<<left<<h[i].medicine_number;
        cout<<setw(10)<<left<<h[i].price;
        cout<<setw(15)<<left<<h[i].medicine_name;
        cout<<setw(20)<<left<<h[i].company_name;
        cout<<setw(20)<<left<<h[i].expiry_year;
        cout<<setw(20)<<left<<c[i]<<endl;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void medicine :: update()
{
    int no,pos,med_no,found=0;
    cout<<"Enter Medicine Number you want to update : ";
    cin>>med_no;
    for(i=0;i<n;i++)
    {
        no=med_no%10;
        pos=no;
        do{
            if(h[no].medicine_number==med_no)
            {
                found=1;
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                if(no>10)
                {
                    no=0;
                }
            }
        }while(no<10);
    }
    if(found==1)
    {
        cout<<"Medicine Name : ";
        cin>>h[no].medicine_name;
        cout<<"Company Name : ";
        cin>>h[no].company_name;
        cout<<"Price : ";
        cin>>h[no].price;
        cout<<"Expiry Year : ";
        cin>>h[no].expiry_year;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void medicine::Delete() {
    int no, pos, med_no, found = 0, it = -1;
    int m=10;
    cout << "Enter Medicine Number you want to delete: ";
    cin >> med_no;

    for (int i = 0; i < n; i++) {
        no = med_no % 10;
        pos = no;
        
        do {
            if (h[no].medicine_number == med_no) {
                found = 1;
                break;

            } 
            else {
                no++;
                c[pos] = no;
            }
        } while (no <10);
    }
    
    if(found==1)
    {
        h[no].medicine_number=-1;
        h[no].price=0;
        h[no].medicine_name="";
        h[no].company_name="";
        h[no].expiry_year=0;
    }
    if (found == 0) {
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    medicine m;
     
    do
    {
        cout<<"\n..........MEDICINE MANAGEMENT SYSTEM..........";
        cout<<"\n1.DECLARE HASH TABLE\n2.ADD RECORD\n3.DISPLAY RECORD\n4.SEARCH\n5.DELETE\n6.UPDATE\n7.EXIT";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                m.declare();
                break;
            case 2:
                m.accept();
                break;
            case 3:
                m.htable();
                break;
            case 4:
                m.search();
                break;
            case 5:
                m.Delete();
                break;
            case 6:
                m.update();
                break;
            case 7:
                cout<<"Thanks for visiting......!!";
                break;
            default:
                cout<<"Wrong choice";
        }
    } while (ch!=7);
    return 0;
}
