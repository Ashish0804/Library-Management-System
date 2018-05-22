#ifndef BOOK_H
#define BOOK_H


class Book
{
    public:
        int Add_book();
        int Display_book();
        char* givetitle();
        int getid();
        int Stock_down();
        int Stock_up();
        Book();
        virtual ~Book();

    protected:

    private:
        int  Stock;
        int  ID;
        char ISBN[12];
        char Title[30];
        char Author_name[50];
        char Publisher[50];
        int Publishing_day,Publishing_month,Publishing_year;
        int Price;
};

#endif // BOOK_H
