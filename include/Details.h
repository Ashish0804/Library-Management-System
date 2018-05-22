#ifndef DETAILS_H
#define DETAILS_H


class Details
{
    public:
        Details();
        virtual ~Details();
        int ISSUE();
        int giveid();
        int RETURN();
        int DisplayRecord();
        char* givename();

    protected:

    private:
        int Issue_id;
        char Class[5];
        int rollno;
        char name[20];
        char book_name[50];
        int issue_day,issue_month,issue_year;
        int return_day,return_month,return_year;
};

#endif // DETAILS_H
