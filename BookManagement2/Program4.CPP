#include <iostream>
#include <string.h>
using namespace std;
class objectNumber
{
    static int count1;
    public:
    static int getnext()
    {
       return count1++;
    }
    static int getcount()
    {
        return count1;
    }

};
int objectNumber::count1=0;
class Book
{
  char bookTitle[25];
  int bookCost;
  int bookStock;
  static char* bookStoreName;
   public:
       Book()
       {
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
        void setBookDetails(char *p,int cost,int stock)
        {
            if(objectNumber::getcount()==0)
            {
                cout << "Book Catalogue is empty,Adding for first time.....Please Enter the details" << endl;
            }

           if(objectNumber::getcount() < 3)
           {
           strcpy(bookTitle,p);
           bookCost = cost;
           bookStock = stock;
           }

        }
      void displayBook(){

           cout << bookTitle << endl;
           cout << bookCost << endl;;
           cout << bookStock << endl;
           cout << Book::bookStoreName << endl;
          }

         bool bookExist(char *p)
         {
             if(strcmp(p,bookTitle)==0)
             {
                 return true;
             }
             else
                return false;
         }
         void addbookDetails(char *p,int cost,int stock)
         {
             bookStock = bookStock + stock;
         }
         void updatebookStock(int stock)
         {
             bookStock = bookStock - stock;
         }
         char* getbookTitle()
         {
             return bookTitle;
         }
         int getbookStock()
         {
             return bookStock;
         }
         int getbookCost()
         {
             return bookCost;
         }
      int searchBook(char *p,int count){

        int flag1=0;
         if(strcmp(p,bookTitle)==0)
          {
            flag1=1;
           if(count>bookStock)
          {
              cout << "Books are there,but shortage of books " << endl;
              //cout << "Details are : Book Name=" << bookTitle << ",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              //return 1;
          }

          else
          {
              cout << "Books are there & sufficient qty available... " << endl;
              //cout << "Details are : Book Name=" << bookTitle <<",Book Cost=" << bookCost << ",Book stock=" << bookStock << "Total Cost=" << bookCost*count << endl;
              //return 1;
          }

          }
          return flag1;
          }

};

char* Book::bookStoreName="Sapna";

int main()
{
    int cost,stock,ch,i=0,flag=0,flag2=0,loc=0;
    bool avail=false;
    char p[25],choice;
    Book *b[3];
    //={new Book(),new Book(),new Book()};
    for(; ;)
    {
        cout << "Choices: 1. Add a Book to catalog 2. Display a book 3.Search for a book 4. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
         case 1:
                 flag2=0;
                cout << "Adding a Book to Catalogue" << endl;
                cout << "Enter the details of Book---" << endl;
                 for(int i=0;i<objectNumber::getcount();i++)
                 {
                if(b[i]==NULL)
                    {
                        flag2=1;
                         break;
                    }
                 }
                 if((flag2==0)&& (objectNumber::getcount()>2) )
                 {
                     cout << "Max Limit of the Book Catalogue reached.Cannot add  extra books" <<endl;
                     break;
                 }
                cout << "Enter the Book Name:";
                cin >> p;

                 if(flag2)
                  {
                    cout << "Enter the Book cost:";
                    cin >> cost;
                    cout << "Enter the Book Stock:";
                    cin >> stock;
                    b[i]=new Book();
                    b[i]->setBookDetails(p,cost,stock);

                    //i++;
                    break;
                  }
                for(int i=0;i<objectNumber::getcount();i++)
                {
                 if(b[i]->bookExist(p))
                  {
                   avail = true;
                   loc = i;
                   break;
                  }

                  }


                if(avail)
                {
                cout << "Book Already Exists....Do u want add additional copies..???  Enter y(yes) or n(no)" <<endl ;
                cin >> choice;
                if(choice=='y')
                {
                    cout << "Enter the Book Stock:";
                    cin >> stock;
                    b[loc]->addbookDetails(p,cost,stock);
                    b[loc]->displayBook();
                }
                else
                {
                    break;
                }
                }
                else
                {

                    b[objectNumber::getcount()]=new Book();

                    cout << "Enter the Book cost:";
                    cin >> cost;
                    cout << "Enter the Book Stock:";
                    cin >> stock;
                    b[objectNumber::getcount()]->setBookDetails(p,cost,stock);
                     objectNumber::getnext();


                }
                    //i++;
                    break;

           case 2:   flag2=0;
                    if(objectNumber::getcount()==0)
                    {
                     cout << "   /* Exception */ Sorryyyy there are no Books to be displayed...  " <<endl;
                     break;
                      }
                        for(int i=0;i<objectNumber::getcount();i++)
                        {
                        if(b[i]!=NULL)
                         {
                        flag2=1;
                         break;
                          }
                         }
                      if(flag2==0)
                      {
                          cout << "  /* Exception */ Sorryyyy there are no Books to be displayed...  " << endl;
                      }


                      if(objectNumber::getcount()!=0){
                   cout << "Displaying the details.."<< endl;
                   //for(i=0;i<3;i++)
                   //{

                    for(int i=0;i<objectNumber::getcount() ;i++)
                    {
                        if( b[i]!=NULL)
                        {

                     b[i]->displayBook();
                    }
                   //}
                   }
                      }
                    break;

            case 3: if(objectNumber::getcount() ==0)
                      {
                       cout << " /* Exception */ There are no Books to be Searched...Please Add books... " << endl;
                        break;
                       }
                     else{
                    cout << "Enter the Details to be searched, Book Name=";
                    cin >> p;
                    //  cout << "Enter the Book Cost:";
                   // cin >> cost ;
                    cout << "Enter the Book stock: ";
                    cin >> stock;
                    for(i=0;i<3;i++)
                    {
                        if(b[i]!=NULL)
                        {

                        if(b[i]->searchBook(p,stock))
                        {

                        flag=1;
                        break;
                        }
                        }
                    }
                     if(flag)
                     {

                         cout << "Details of Object found:....";
                         cout << " Book Name:" << b[i]->getbookTitle() << ", Book Qty:" << b[i]->getbookStock();
                         cout << " ,Total cost=" << b[i]->getbookCost() * stock << endl;
                         cout << "Do you wish to continue the purchase..??? Input y(yes) or n(no): ";
                         cin >> choice ;
                         if(choice=='y')
                         {
                             if(b[i]->getbookStock() == stock)
                             {
                                 b[i]->updatebookStock(stock);
                                 cout << "Deleting the Book:" << i << endl;
                                 delete b[i];
                                 b[i]=NULL;
                             }
                             else
                             {
                                 b[i]->updatebookStock(stock);
                                //b[i]->getbookStock() = b[i]->getbookStock() - stock;

                             }
                         }

                     }
                    if(!flag)
                        cout << "Search was unsuccessful....." << endl;
                     }
                    break;

               default : cout << "End of the program....";
                         return 0;

                        return 0;
        }

}
}


