
//menu driven program
#include<iostream>
#include <string.h>
using namespace std;
//class Book;
class Book
{
	char *BookTitle;
	int BookCost;
	int BookStock;
public:
    Book(char *title,double cost,int stock):BookTitle(new char[strlen(title)+1]),BookCost(cost),BookStock(stock)
	{
		strcpy(BookTitle,title);
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
class BookStore
{
    static char *BookStoreName;
    Book *b[3]={NULL,NULL,NULL};
    public:

     void AddBook(int &BookCount,int MaxCount)
	{
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
						b[i]=new Book(title,cost,stock);
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
		if(BookCount==0)
			cout<<"Catalog is empty"<<endl;
		else
		{
			for(int i=0;i<MaxCount;i++)
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
    BookStore bs;
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

	/*for(int i=0;i<BookCount;i++)
	{
		if(b[i]!=NULL)
			delete b[i];

}*/
return 0;
}


