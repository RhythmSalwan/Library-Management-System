#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

class book
{
    private:
    int bookid;
    char bookname[50];
    char author[50];
    int edition;
    char publisher[100];
    char isbn[25];
    int issued_to;
    friend void search_by_bookID();
    friend void add_book();
    friend void display_book();
    friend void search_by_bookID();
    friend void search_by_bookname();
    friend void search_by_author();
    friend void search_by_publisher();
    friend void issue_book();
    friend void remove_book();
    friend void return_book();
    public:
    void accept()
    {
        cout<<endl<<"Enter Book Details:"<<endl;
        cout<<endl<<"Enter Book ID->";
        cin>>bookid;
        cout<<endl<<"Enter Bookname->";
        cin>>bookname;
        cout<<endl<<"Enter Author Name->";
        cin>>author;
        cout<<endl<<"Enter Edition->";
        cin>>edition;
        cout<<endl<<"Enter Publisher->";
        cin>>publisher;
        cout<<endl<<"Enter ISBN->";
        cin>>isbn;
        issued_to=0;
    }
    void display()
    {
        cout<<setw(20)<<bookid;
        cout<<setw(30)<<bookname;
        cout<<setw(20)<<author;
        cout<<setw(20)<<edition;
        cout<<setw(20)<<publisher;
        cout<<setw(20)<<isbn;
        cout<<setw(20)<<issued_to<<endl;
    }  
};

book obj_bk;
void add_book()
{
    cout<<endl<<"Security Check:";
    int bID;
    cout<<endl<<"Enter BookID->";
    cin>>bID;
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int n=s/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(obj_bk.bookid==bID)
        {
            flag=1;
            rd.close();
        }
    }
    if(flag==1)
    {
        cout<<endl;
        cout<<setw(50)<<"Book already exists"<<endl;
    }
    else
    {
        fstream wr;
        obj_bk.accept();
        wr.open("books.txt",ios::app);
        wr.write((char*)&obj_bk,sizeof(obj_bk));
        cout<<endl;
        cout<<setw(50)<<"Book entered successfully"<<endl;
        wr.close();
    }
}

void display_book()
{
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj_bk);
    cout<<"Number of books are"<<" "<<s<<endl<<endl;
    rd.seekg(0,ios::beg);
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"BOOKID";
    cout<<setw(30)<<"BOOK NAME";
    cout<<setw(20)<<"AUTHOR NAME";
    cout<<setw(20)<<"EDITION";
    cout<<setw(20)<<"PUBLISHER";
    cout<<setw(20)<<"ISBN";
    cout<<setw(20)<<"ISSUED TO"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        obj_bk.display();
    }
    rd.close();
}

void search_by_bookID()
{
    int bID;
    cout<<endl<<"Enter the ID of the book to be searched->";
    cin>>bID;
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int n=s/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"BookID";
    cout<<setw(20)<<"Bookname";
    cout<<setw(20)<<"Author Name";
    cout<<setw(20)<<"Edition";
    cout<<setw(20)<<"Publisher";
    cout<<setw(20)<<"ISBN"<<endl<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(bID==obj_bk.bookid)
        {
            obj_bk.display();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<endl<<setw(40)<<"Book with ID"<<bID<<"does not exist in the library."<<endl;
    }
    rd.close();
}

void search_by_bookname()
{
    char bname[50];
    cout<<endl<<"Enter the name of the book to be searched->";
    cin>>bname;
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int n=s/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"BookID";
    cout<<setw(20)<<"Bookname";
    cout<<setw(20)<<"Author Name";
    cout<<setw(20)<<"Edition";
    cout<<setw(20)<<"Publisher";
    cout<<setw(20)<<"ISBN"<<endl<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(strcmp(bname,obj_bk.bookname)==0)
        {
            obj_bk.display();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<endl<<setw(40)<<"Book with name"<<bname<<"does not exist in the library."<<endl;
    }
    rd.close();
}

void search_by_author()
{
    char aname[50];
    cout<<endl<<"Enter the name of the author to be searched->";
    cin>>aname;
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int n=s/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"BookID";
    cout<<setw(20)<<"Bookname";
    cout<<setw(20)<<"Author Name";
    cout<<setw(20)<<"Edition";
    cout<<setw(20)<<"Publisher";
    cout<<setw(20)<<"ISBN"<<endl<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(strcmp(aname,obj_bk.author)==0)
        {
            obj_bk.display();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<endl<<setw(40)<<"Book with author"<<aname<<"does not exist in the library."<<endl;
    }
    rd.close();
}

void search_by_publisher()
{
    char pname[50];
    cout<<endl<<"Enter the name of the publisher to be searched->";
    cin>>pname;
    fstream rd;
    rd.open("books.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int n=s/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"BookID";
    cout<<setw(20)<<"Bookname";
    cout<<setw(20)<<"Author Name";
    cout<<setw(20)<<"Edition";
    cout<<setw(20)<<"Publisher";
    cout<<setw(20)<<"ISBN"<<endl<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(strcmp(pname,obj_bk.publisher)==0)
        {
            obj_bk.display();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<endl<<setw(40)<<"Book with publisher"<<pname<<"does not exist in the library."<<endl;
    }
    rd.close();
}

void remove_book()
{
    fstream wr,rd;
    rd.open("books.txt",ios::in);
    wr.open("temp.txt",ios::out);
    int id;
    cout<<endl<<"Enter Book ID";
    cin>>id;
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1;i<=s;i++);
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(obj_bk.bookid==id)
        {
            cout<<endl<<setw(50)<<"Book removed successfully";
            flag=1;
        }
        else
        {
            wr.write((char*)&obj_bk,sizeof(obj_bk));
        }
    }
    if(flag==0)
    {
        cout<<endl;
        cout<<setw(50)<<"Book with ID"<<id<<"does not exist in the library.";
    }
    wr.close();
    rd.close();
    remove("books.txt");
    rename("temp.txt","books.txt");
    cout<<endl<<"File Updated";
}

void issue_book()
{
    fstream rd,wr;
    rd.open("books.txt",ios::in);
    wr.open("temp.txt",ios::out);
    int id;
    cout<<endl<<"Book ID->";
    cin>>id;
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(obj_bk.bookid=id)
        {
            if(obj_bk.issued_to=0)
            {
                int member_id;
                cout<<endl<<"Enter Membership ID";
                cin>>member_id;
                obj_bk.issued_to=member_id;
                wr.write((char*)&obj_bk,sizeof(obj_bk));
                cout<<endl<<setw(60)<<"Book with ID->"<<id<<"issued to member with ID->"<<member_id<<"successfully";
            }
            else
            {
                cout<<endl;
                cout<<setw(50)<<"Bookd with ID->"<<id<<"is not available";
                wr.write((char*)&obj_bk,sizeof(obj_bk));
            }
        }
        else
        {
            wr.write((char*)&obj_bk,sizeof(obj_bk));
        }
    }
    wr.close();
    rd.close();
    remove("books.text");
    rename("temp.txt","books.txt");
}

void return_book()
{
    fstream rd,wr;
    rd.open("books.txt",ios::in);
    wr.open("temp.txt",ios::out);
    int id,member_id;
    cout<<endl<<"Enter ID of the Book to be returned->";
    cin>>id;
    cout<<endl<<"Enter Membership ID->";
    cin>>member_id;
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj_bk);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj_bk,sizeof(obj_bk));
        if(obj_bk.bookid==id && obj_bk.issued_to==member_id)
        {
            if(obj_bk.issued_to!=0)
            {
                flag=1;
                obj_bk.issued_to=0;
                wr.write((char*)&obj_bk,sizeof(obj_bk));
                cout<<endl;
                cout<<endl<<setw(60)<<"Book with ID"<<id<<"returned successfully";    
            }
            else
            {
                wr.write((char*)&obj_bk,sizeof(obj_bk));
            }
        }
        else
        {
            wr.write((char*)&obj_bk,sizeof(obj_bk));
        }
    }
    if(flag!=1)
    {
        cout<<endl;
        cout<<setw(60)<<"Book with ID->"<<id<<"already returned.";
    }
    wr.close();
    rd.close();
    remove("books.txt");
    rename("temp.txt","books.txt");
}

int main()
{
    cout<<setw(50)<<"**********************************";
    cout<<endl<<setw(47)<<"WELCOME TO LIBRARY MANAGEMENT";
    cout<<endl<<setw(50)<<"**********************************";
    int e=1;
    while(e==1)
    {
        int choice;
        cout<<endl<<"Press 1 to add a book"<<endl;
        cout<<endl<<"Press 2 to view all books"<<endl;
        cout<<endl<<"Press 3 to search book by BookID"<<endl;
        cout<<endl<<"Press 4 to search book by Bookname"<<endl;
        cout<<endl<<"Press 5 to search book by Author"<<endl;
        cout<<endl<<"Press 6 to search book by Publisher"<<endl;
        cout<<endl<<"Press 7 to delete a book"<<endl;
        cout<<endl<<"Press 8 to issue a book"<<endl;
        cout<<endl<<"Press 9 to return a book"<<endl;
        cout<<endl<<"Press 0 to exit"<<endl;
        cout<<endl<<"Enter Choice->";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                add_book();
                break;
            }   
            case 2:
            {
                display_book();
                break;
            }
            case 3:
            {
                search_by_bookID();
                break;
            }
            case 4:
            {
                search_by_bookname();
                break;
            }
            case 5:
            {
                search_by_author();
                break;
            }
            case 6:
            {
                search_by_publisher();
                break;
            }
            case 7:
            {
                remove_book();
                break;
            }
            case 8:
            {
                issue_book();
                break;
            }
            case 9:
            {
                return_book();
                break;
            }
            case 0:
            {
                e=0;
            }
        }
    }
}