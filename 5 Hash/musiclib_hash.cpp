#include<iostream>
#include<iomanip>
using namespace std;
int key[30],c[30],n ,m;
int i;
class music
{
    public:
    int year,sales;
    string title,artist;
    float p;
    void declare();
    void htable();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void music :: declare()
{   
    cout<<"Enter total number of keys : ";
    cin>>n;
    cout<<"Enter Keys :  "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].year=-1;
        c[i]=0;
    }
}
void music :: htable()
{
    /*cout<<"\nYear\tSales\tTitle\tArtist\tPercentage\tChain";*/
    cout<<endl<<setw(6)<<left<<"Year";
    cout<<setw(10)<<left<<"Sales ";
    cout<<setw(15)<<left<<"Title ";
    cout<<setw(15)<<left<<"Artist ";
    cout<<setw(20)<<left<<"No. of Awards won "<<endl;
    for(i=0;i<10;i++)
    {
    //cout<<"\n"<<h[i].year<<"\t"<<h[i].sales<<"\t"<<h[i].title<<"\t"<<h[i].artist<<"\t"<<h[i].p<<"\t\t"<<c[i];
    cout<<setw(6)<<left<<h[i].year;
    cout<<setw(10)<<left<<h[i].sales;
    cout<<setw(15)<<left<<h[i].title;
    cout<<setw(15)<<left<<h[i].artist;
    cout<<setw(20)<<left<<h[i].p<<endl;
    }
}
void music :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].year==-1)
            {
                h[no].year=key[i];
                cout<<"\nEnter data for year "<<key[i]<<'\n';
                cout<<"Title of song : ";
                cin>>h[no].title;
                cout<<"Artist name : ";
                cin>>h[no].artist;
                cout<<"Total sales : ";
                cin>>h[no].sales;
                cout<<"Number of awards won : ";
                cin>>h[no].p;
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
void music :: search()
{
    int no,pos,yr,found=0;
    cout<<"Enter Year of the music record you want to search : ";
    cin>>yr;
    for(i=0;i<n;i++)
    {
        no=yr%10;
        pos=no;
        do{
            if(h[no].year==yr)
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
        //cout<<"\nYear\tSales\tTitle\tArtist\tPercentage\tChain";
        cout<<endl<<setw(6)<<left<<"Year";
        cout<<setw(10)<<left<<"Sales ";
        cout<<setw(15)<<left<<"Title ";
        cout<<setw(15)<<left<<"Artist ";
        cout<<setw(20)<<left<<"No. of Awards won ";
        cout<<setw(7)<<left<<"Chain"<<endl;
        //cout<<"\n"<<h[no].year<<"\t"<<h[no].sales<<"\t"<<h[no].title<<"\t"<<h[no].artist<<"\t"<<h[no].p<<"\t\t"<<c[i];
        cout<<setw(6)<<left<<h[i].year;
        cout<<setw(10)<<left<<h[i].sales;
        cout<<setw(15)<<left<<h[i].title;
        cout<<setw(15)<<left<<h[i].artist;
        cout<<setw(20)<<left<<h[i].p;
        cout<<setw(7)<<left<<c[i]<<endl;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void music :: update()
{
    int no,pos,yr,found=0;
    cout<<"Enter Year of the music record you want to update : ";
    cin>>yr;
    for(i=0;i<n;i++)
    {
        no=yr%10;
        pos=no;
        do{
            if(h[no].year==yr)
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
                
                cout<<"Title of song : ";
                cin>>h[no].title;
                cout<<"Artist name : ";
                cin>>h[no].artist;
                cout<<"number of sales : ";
                cin>>h[no].sales;
                cout<<"Number of awards won : ";
                cin>>h[no].p;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void music::Delete() {
    int no, pos, yr, found = 0, it = -1;
    int m=10;
    cout << "Enter Year of the music record you want to delete: ";
    cin >> yr;

    for (int i = 0; i < n; i++) {
        no = yr % 10;
        pos = no;
        
        do {
            if (h[no].year == yr) {
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
   h[no].year=-1;
          h[no].sales=0;
          h[no].title="";
          h[no].artist="";
          h[no].p=0;
}
    if (found == 0) {
      
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    music s;
     
    do
    {
        cout<<"\n..........MUSIC MANAGEMENT SYSTEM..........";
        cout<<"\n1.DECLARE HASH TABLE\n2.ADD RECORD\n3.DISPLAY RECORD\n4.SEARCH\n5.DELETE\n6.UPDATE\n7.EXIT";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
         
            case 1:
            s.declare();
            break;
            case 2:
            s.accept();
            break;
            case 3:
            s.htable();
            break;
            case 4:
            s.search();
            break;
            case 5:
            s.Delete();
            break;
            case 6:
            s.update();
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
