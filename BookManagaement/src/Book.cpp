#include <iostream>
#include <string.h>
using namespace std;
class Book
{
  char bookTitle[25];
  int bookCost;
  int bookStock;
   public:
      void setBook(){
      cin >> bookTitle;
      cin >> bookCost;
      cin >> bookStock;
      }
      void displayBook(){
      cout << bookTitle << endl;
      cout << bookCost << endl;;
      cout << bookStock << endl;
      }
      int searchBook(char *p,int count){
      if(strcmp(p,bookTitle)==0)
      {
          if(count>bookStock)
          {
              cout << "Books are there,but shortage of books " << endl;
              cout << "Details are : Book Name=" << bookTitle << ",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              return 1;
          }

          else
          {
              cout << "Books are there & sufficient qty available... " << endl;
              cout << "Details are : Book Name=" << bookTitle <<",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              return 1;
          }

          }
          else
          return 0;
          }

};
int main()
{
    int count;
    char p[25];
    Book b1,b2,b3;
    cout << "Enter Book1 details:";
    b1.setBook();
    b1.displayBook();
    cout << " Enter Book2 details:";
    b2.setBook();
    b2.displayBook();
    cout << "Enter Book3 details:";
    b3.setBook();
    b3.displayBook();

    cout << "Search---Enter the Name of Book and Quantity:";
    cin >> p;
    cin >> count;
    if(b1.searchBook(p,count))
    {
        cout << "Inside First Object Search";
    }
    else if(b2.searchBook(p,count))
    {
        cout << "Inside Second Object search";
    }
    else if(b3.searchBook(p,count))
    {
        cout << "Book :" << *p << " is unavailable....";
    }
    else
     cout << "Book is unavailable...." << endl;

    cout << "End of the program....";
    return 0;

    }

