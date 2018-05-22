#include<string.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include "Book.h"
#include "Details.h"
using namespace std;

int c=0,c_=0,f=20;

void Write_book(Book s)
{
ofstream fout("Books.dat",ios::binary|ios::app);
fout.write((char *)&s,sizeof(s));
fout.close();
}

void displayall_book()
{
Book s;
ifstream fin("Books.dat",ios::binary);
while(!fin.eof() && fin.read((char *)&s,sizeof(s)))
     {
      s.Display_book();
     }
fin.close();
}

void display_book(int i)
{
Book s;
ifstream fin("Books.dat",ios::binary);
while(!fin.eof() && fin.read((char *)&s,sizeof(s)))
     {
      if(s.getid() == i)
        {
         s.Display_book();
        }
     }
fin.close();
}

void Update(int i)
{
Book s;
ifstream fin("Books.dat",ios::binary);
ofstream fout("temp.dat",ios::binary|ios::app);
while(!fin.eof() && fin.read((char *)&s,sizeof(s)))
     {
      if(s.getid() == i)
        {
         s.Add_book();
        }
      fout.write((char *)&s,sizeof(s));
     }
fin.close();
fout.close();
remove("Books.dat");
rename("temp.dat","Books.dat");
}

void Delete(int i)
{
Book s;
ifstream fin("Books.dat",ios::binary);
ofstream fout("temp.dat",ios::binary|ios::app);
while(!fin.eof() && fin.read((char *)&s,sizeof(s)))
     {
      if(s.getid() != i)
        {
         fout.write((char *)&s,sizeof(s));
        }
     }
fin.close();
fout.close();
remove("Books.dat");
rename("temp.dat","Books.dat");
}

void Write_record(Details d1)
{
ofstream fout("Record.dat",ios::binary|ios::app);
fout.write((char *)&d1,sizeof(d1));
fout.close();

Details d0;
ifstream fin("Record.dat",ios::binary);
while(!fin.eof() && fin.read((char *)&d0,sizeof(d0)))
     {
      Book s;
      ifstream fin1("Books.dat",ios::binary);
      ofstream fout("temp.dat",ios::binary|ios::app);
      while(!fin1.eof() && fin1.read((char *)&s,sizeof(s)))
           {
            if(strcmpi(s.givetitle(),d0.givename()) == 0)
              {
               s.Stock_down();
              }
            fout.write((char *)&s,sizeof(s));
           }
      fin1.close();
      fout.close();
      remove("Books.dat");
      rename("temp.dat","Books.dat");
     }
fin.close();
}

void Update_record(int i)
{
Details d0;
char nme[30];
ifstream fin("Record.dat",ios::binary);
ofstream fout("temp.dat",ios::binary|ios::app);
while(!fin.eof() && fin.read((char *)&d0,sizeof(d0)))
     {
      if(d0.giveid() == i)
        {
         d0.RETURN();
		 strcpy(nme,d0.givename());

        }
      fout.write((char *)&d0,sizeof(d0));
     }
fin.close();
fout.close();
remove("Record.dat");
rename("temp.dat","Record.dat");

ifstream fin2("Record.dat",ios::binary);
Book s;
ifstream fin1("Books.dat",ios::binary);
ofstream fout1("temp.dat",ios::binary|ios::app);
while(!fin1.eof() && fin1.read((char *)&s,sizeof(s)))
     {
      if(strcmpi(s.givetitle(),nme) == 0)
        {
         s.Stock_up();
        }
      fout1.write((char *)&s,sizeof(s));
	 }
fin1.close();
fout1.close();
remove("Books.dat");
rename("temp.dat","Books.dat");
fin2.close();
}

int fine(int Fine)
{
 return ((Fine-f)*2);
}

void display_record(int i)
{
Details d0;
ifstream fin("Record.dat",ios::binary);
while(!fin.eof() && fin.read((char *)&d0,sizeof(d0)))
     {
      if(d0.giveid() == i)
        {
         d0.DisplayRecord();
        }
     }
fin.close();
}

void displayall_record()
{
Details d0;
ifstream fin("Record.dat",ios::binary);
while(!fin.eof() && fin.read((char *)&d0,sizeof(d0)))
     {
      d0.DisplayRecord();
     }
fin.close();
}

int main()
{
system("cls");
int fine_day, choice;
char ch='y';
int i,n;
int id;
Book ss;
Details dd;
cout<<"                               !!!!WELCOME!!!!"<<"\n";
cout<<"\n\n\n\n";
cout<<"                           LIBRARY MANAGEMENT SYSTEM"<<"\n\n\n\n";
cout<<"                                                                  MADE BY- ASHISH"<<"\n\n\n\n\n\n";
system("pause");
system("cls");
do
{
  system("cls");
  cout<<"\n 1.Book Shelf";
  cout<<"\n 2.Issue/Return";
  cout<<"\n 3.Exit";
  cout<<"\n Enter the choice (1-3): ";
  cin>>choice;
  switch(choice)
  {
	  case 1:{
				system("cls");
		        cout<<"\n 1.Add/Insert";
				cout<<"\n 2.Update details";
				cout<<"\n 3.Delete";
				cout<<"\n 4.Search a book";
				cout<<"\n 5.Display All";
				cout<<"\n 6.Exit";
				cout<<"\n Enter the choice (1-6): ";
				cin>>choice;

				switch(choice)
					  {
					   case 1:
						        system("cls");
								ss.Add_book(); Write_book(ss); break;

						case 2:
								system("cls");
  								cout<<"\n Enter the ID of the book to be updated: ";
								cin>>id;
								Update(id);break;

						case 3:
                                system("cls");
								cout<<"\n Enter the ID of the book to be deleted: ";
								cin>>id;
								Delete(id);break;

						case 4:
                                system("cls");
								cout<<"\n Enter the ID of the book :";
								cin>>id;
								display_book(id);break;

						case 5:
						        system("cls");
								displayall_book();break;

						case 6:
                                break;

						default :
                                 break;
					   };
	  };break;

	  case 2:{
				system("cls");
				cout<<"\n 1.Issue";
				cout<<"\n 2.Return";
				cout<<"\n 3.Search by ID";
				cout<<"\n 4.Display All Records";
				cout<<"\n 5.Exit";
				cout<<"\n Enter your choice (1-5): ";
				cin>>choice;

				switch(choice)
					  {
					   case 1:
								system("cls");
								dd.ISSUE(); Write_record(dd); break;

					   case 2:
								system("cls");
								cout<<"\n Enter the Issue ID: ";
								cin>>id;
								Update_record(id);
								cout<<"\n Days after book is returned: ";
								cin>>fine_day;
								if(fine_day > 20)
									cout<<"\n The fine is: Rs."<<fine(fine_day);
								else
									cout<<"\n Thanks.";
								break;

					   case 3:
								system("cls");
								cout<<"\n Enter the Issue ID: ";
								cin>>id;
								display_record(id);break;


					   case 4:
							  system("cls");
						      displayall_record();break;

					   case 5:
                              break;

       				   default:
                               break;
					  };
	  };break;

	  case 3:
	         break;

	  default:
              break;
  };

  cout<<"\n\n\n\ Do you want to continue? ";
  cin>>ch;
} while(ch=='y'||ch=='Y');

return 0;
}
