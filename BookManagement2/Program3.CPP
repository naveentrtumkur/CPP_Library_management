
//menu driven program
#include<iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
//class Book;
class Book
{
	char *BookTitle;
	int BookCost;
	int BookStock;
	//static int discount;
public:
    Book(char *title,double cost,int stock):BookTitle(new char[strlen(title)+1]),BookCost(cost),BookStock(stock)
	{
		strcpy(BookTitle,title);
	}

    void display()
    {
        cout << "Inside base class";
        cout << BookTitle << BookCost << BookStock << endl;
    }
	int getBookStock()
	{
	    return BookStock;
	}
	void updateBookStock(int stock)
	{
	    BookStock = BookStock + stock;

	}
	char* getBookTitle()
	{
	    return BookTitle;
	}
	int getBookCost()
	{
	    return BookCost;
	}
	/*~Book()
	{
		if(BookTitle != NULL)
		delete [] BookTitle;
	}*/
};
class TechnicalBook : public Book
{
    const int discount=5;
public:
    TechnicalBook(char *title,double cost,int stock):Book(title,cost,stock){}
    void display()
    {
        cout << "Inside derived class";
    }


};

class ManagementBook : public Book
{
     const int discount=10;
public:
    ManagementBook(char *title,double cost,int stock): Book(title,cost,stock){}
    void display()
    {
        cout << "Inside derived class";
    }
};
class BookStore
{
    static char *BookStoreName;
    Book *b[3]={NULL,NULL,NULL};
    public:

     void AddBook(int &BookCount,int MaxCount)
	{
	    int flag=0;
	    cout << "Do you want to Add 1.Technical Book  2.Management Book ...?" << endl;
	    cout << "Enter you Choice:";
	    cin >> flag;
		char title[25];
		double cost;
		int stock;
		int status=false;

        if(BookCount==MaxCount)
			cout<<"No more books can be added"<<endl;
		else
		{

			cout<<"enter the title"<<endl;
			cin>>title;
			//Check for availability of the book
			int pos=-1;
			for(int i=0;i<BookCount;i++)
			{
				if(b[i]!=NULL)
				{
					if(strcmp(b[i]->getBookTitle(),title)==0)
					{
						status=true;
						pos=i;
						break;
					}
				}
			}
            if(status)
			{
				cout<<"book by the title "<<title<<" exists -> existing stock is updated"<<endl;
				cout<<"enter the stock "<<endl;
				cin>>stock;
				int updatedstock = b[pos]->getBookStock()+stock;
				b[pos]->updateBookStock(updatedstock);
			}
			else
			{
				cout<<"book by the title "<<title<< " does not exists -> adding a book to the catalog"<<endl;
				cout<<"enter the cost and stock "<<endl;
				cin>>cost;
				cin>>stock;
				for(int i=0;i<MaxCount;i++)
				{
					if(b[i]==NULL)
					{
					    if(flag==1)
						b[i]=new TechnicalBook(title,cost,stock);
						else
                        b[i]=new ManagementBook(title,cost,stock);
						status=true;
						BookCount++;
						break;
					}
				}

			}

		}

	}
     void DispBook(int &BookCount,int MaxCount)
	{
	    int choice=0;
		if(BookCount==0)
			cout<<"Catalog is empty"<<endl;
		else
		{
		    cout << "1.Display all the Books 2.Display only Technical Books 3.Dsiplay only Management Books" << endl;
		    cout << "Enter your choice:";
		    cin >> choice;
		    cout << endl << typeid(*b[0]).name() << endl;
			for(int i=0;i<MaxCount;i++)
			{
			    if(choice==1)
                {
				if(b[i]!=NULL)
				{
					cout<<"BookstoreName:"<<BookStoreName<<endl;
					cout<<"Title:"<<b[i]->getBookTitle()<<endl;
					cout<<"Cost:"<<b[i]->getBookCost()<<endl;
					cout<<"Stock:"<<b[i]->getBookStock()<<endl;
					cout<<"-----------------------------------"<<endl;
				}
			}
			if(choice ==2)
            {
                if(typeid(*b[i])== typeid(TechnicalBook))
                   {
               if(b[i]!=NULL)
				{
					cout<<"BookstoreName:"<<BookStoreName<<endl;
					cout<<"Title:"<<b[i]->getBookTitle()<<endl;
					cout<<"Cost:"<<b[i]->getBookCost()<<endl;
					cout<<"Stock:"<<b[i]->getBookStock()<<endl;
					cout<<"-----------------------------------"<<endl;
				}
            }
            }
            if(choice ==3)
            {
                if((typeid(*b[i]))== (typeid(ManagementBook)))
                   {
               if(b[i]!=NULL)
				{
					cout<<"BookstoreName:"<<BookStoreName<<endl;
					cout<<"Title:"<<b[i]->getBookTitle()<<endl;
					cout<<"Cost:"<<b[i]->getBookCost()<<endl;
					cout<<"Stock:"<<b[i]->getBookStock()<<endl;
					cout<<"-----------------------------------"<<endl;
				}
            }
            }
			}
		}
	}
        void SearchBook(int &BookCount,int MaxCount)
	{
		char title[25];
		int stock;

		if(BookCount==0)
			cout<<"Catalog is empty"<<endl;
		else
		{
			cout<<"enter the required title and stock"<<endl;
			cin>>title>>stock;

			char ch;
			bool status=false;
			for(int i=0;i<MaxCount;i++)
			{
				if(b[i]!=NULL)
				{
					if(strcmp(b[i]->getBookTitle(),title)==0)
					{
						status=true;
						if(stock<=(b[i]->getBookStock()))
						{
							cout<<"Book available with sufficient stock"<<endl;
							cout<<"Billing Cost:"<<(b[i]->getBookCost()*stock)<<endl;
							cout<<"enter y to purchase"<<endl;
							cin>>ch;
							if(ch=='y')
							{
								b[i]->updateBookStock(-stock);
								if((b[i]->getBookStock())==0)
								{
									delete b[i];
									b[i]=NULL;
									BookCount--;
								}
							}

						}
						else
							cout<<"Book available but stock is insufficient"<<endl;
					}
				}
			}
			if(status==false)
				cout<<"book not available"<<endl;
		}

	}

};


char* BookStore::BookStoreName="SAPNA";

int main()
{

    Book *t ;
    t = new TechnicalBook("C",100,10);
    cout << typeid(t).name();
    /*BookStore bs;
	int BookCount=0,choice;
	int MaxCount=3;

	do
	{
		cout<<"1:addBook 2:dispBook 3:searchBook"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:

			bs.AddBook(BookCount,MaxCount);
			break;

		case 2:
			bs.DispBook(BookCount,MaxCount);
			break;

		case 3:
			bs.SearchBook(BookCount,MaxCount);
			break;

		default:
			cout<<"invalid choice"<<endl;
			break;
		}
		cout<<"enter 1 to continue"<<endl;
		cin>>choice;
	}while(choice==1);
       */
	/*for(int i=0;i<BookCount;i++)
	{
		if(b[i]!=NULL)
			delete b[i];

}*/
return 0;
}


