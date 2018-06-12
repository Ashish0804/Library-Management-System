#include "Details.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include "Book.h"
#include "Details.h"
using namespace std;

Details::Details()
{
    //ctor
}

Details::~Details()
{
    //dtor
}

Details::ISSUE()
            {
			 system("cls");
			 cout<<"\n Issue ID: ";
			 cin>>Issue_id;
			 cout<<"\n Class: ";
			 cin>>Class;
			 cout<<"\n Book name: ";
			 cin>>book_name;
			 cout<<"\n Roll number: ";
			 cin>>rollno;
			 cout<<"\n Name of the student: ";
             cin>>name;
			 cout<<"\n Issue Date: ";
			 cout<<"\n             day: ";
			 cin>>issue_day;
			 cout<<"\n             month: ";
			 cin>>issue_month;
			 cout<<"\n             year: ";
			 cin>>issue_year;
		     cout<<"\n\n BOOK ISSUED, RETURN AFTER 20 DAYS. FINE = 2 RUPEES PER DAY.";
			}

Details::giveid()
      		{
			 return Issue_id;
		    }

Details::RETURN()
            {
			 cout<<"\n Return Date: ";
			 cout<<"\n             day: ";
			 cin>>return_day;
	     	 cout<<"\n             month: ";
			 cin>>return_month;
			 cout<<"\n             year: ";
			 cin>>return_year;
            }

Details::DisplayRecord()
			{
	         cout<<"\n\n\n Issue ID: "<<Issue_id;
	         cout<<"\n Class: "<<Class;
	         cout<<"\n Roll number: "<<rollno;
	         cout<<"\n Name: "<<name;
	         cout<<"\n Book: "<<book_name;
	         cout<<"\n Issue date: "<<issue_day<<" "<<issue_month<<" "<<issue_year;
             cout<<"\n Return date: "<<return_day<<" "<<return_month<<" "<<return_year;
        	}

char* Details::givename()
		     {
			  return book_name;
		     }
