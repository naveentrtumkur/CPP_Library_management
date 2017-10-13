#include <iostream>
#include <string.h>
using namespace std;
class Book
{
  char bookTitle[25];
  int bookCost;
  int bookStock;
  static char *bookStoreName;
   public:
       Book():strcpy(bookTitle,"BOOK")
       {
          bookCost = 100;
          bookstock = 5;

        /*cin >> bookTitle;
        cin >> bookCost;
        cin >> bookStock;*/
       }
        Book(char *p,int cost,int stock)
        {
           strcpy(bookTitle,p);
           bookCost = cost;
           bookStock = stock;
        }
      void displayBook(){
      cout << bookTitle << endl;
      cout << bookCost << endl;;
      cout << bookStock << endl;
      }
      int searchBook(char *p,int count){
        int flag1=0;
         if(strcmp(p,bookTitle)==0)
          {
            flag1=1;
           if(count>bookStock)
          {
              cout << "Books are there,but shortage of books " << endl;
              cout << "Details are : Book Name=" << bookTitle << ",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              //return 1;
          }

          else
          {
              cout << "Books are there & sufficient qty available... " << endl;
              cout << "Details are : Book Name=" << bookTitle <<",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              //return 1;
          }

          }
          return flag1;
          }

};

Book::bookStoreName="Sapna";

int main()
{
    int cost,stock,ch,i=0,flag=0;
    char p[25];
    Book *b[3]={new Book(),new Book(),new Book()};
    for(; ;)
    {
        cout << "Choices: 1. Add a Book to catalog 2. Display a book 3.Search for a book 4. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
         case 1: cout << "Adding a Book to Catalogue" << endl;
                cout << "Enter the details of Book---" << endl;
                cout << "Enter the Book Name:";
                cin >> p;
                cout << "Enter the Book cost:";
                cin >> cost;
                cout << "Enter the Book Stock:";
                cin >> stock;
                //i++;
                break;

           case 2: cout << "Displaying the details.."<< endl;
                   for(i=0;i<3;i++)
                   {
                    cout << "Name: " << b[i]->bookTitle;
                    cout << "Cost:" << b[i]->bookCost;
                    cout << "Quantity:" << b[i]->bookStock << endl;

                   }
                    break;

            case 3: cout << "Enter the Details to be searched, Book Name=";
                    cin >> p;
                    //  cout << "Enter the Book Cost:";
                   // cin >> cost ;
                    cout << "Enter the Book stock: ";
                    cin >> stock;
                    for(int i=0;i<3;i++)
                    {
                        if(p[i]->searchBook(p,stock))
                        {

                        flag=1;

                        }
                    }
                    if(!flag)
                        cout << "Search was unsuccessful..." << endl;
                    break;

               default : cout << "End of the program...."
                         exit(0);

                        return 0;

    }

