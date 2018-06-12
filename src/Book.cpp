#include "Book.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
using namespace std;
Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}

Book::Add_book()
            {
              system("cls");
			  cout<<"\n ID: ";
			  cin>>ID;
			  cout<<"\n Title: ";
			  gets(Title);		  
			  cout<<"\n Price: ";
			  cin>>Price;
			  cout<<"\n ISBN: ";
			  cin>>ISBN;
			  cout<<"\n Stock: ";
			  cin>>Stock;
			  cout<<"\n Author's name: ";
			  cin>>Author_name;
			  cout<<"\n Publisher's name: ";
			  cin>>Publisher;
			  cout<<"\n Publishing Date: ";
			  cout<<"\n                  day: ";
	          cin>>Publishing_day;
			  cout<<"\n                  month: ";
		      cin>>Publishing_month;
			  cout<<"\n                  year: ";
			  cin>>Publishing_year;
			  

            }

Book::Display_book()
             {
              cout<<"\n\n ID: "<<ID;
			  cout<<"\n Title: "<<Title;
			  cout<<"\n ISBN: "<<ISBN;
              cout<<"\n Author's name: "<< Author_name;
			  cout<<"\n Publisher: "<<Publisher;
			  cout<<"\n Publishing date:  "<<Publishing_day<<"/"<< Publishing_month<<"/"<<Publishing_year;
			  cout<<"\n Stock: "<<Stock;
			  cout<<"\n Price: "<<Price;
             }

char* Book::givetitle()
	     	 {
			  return Title;
		     }

Book::getid()
      		{
			 return ID;
		    }

Book::Stock_down()
		    {
			 Stock--;
		    }

Book::Stock_up()
		    {
			 Stock++;
		    }

