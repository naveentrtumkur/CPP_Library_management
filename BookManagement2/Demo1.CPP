#include<iostream>
using namespace std;

class c1
{
public:
	void display()
	{  cout<<"class c1"<<endl;  }
	 class c2
	{
		 static void display()
		{  cout<<"class c2"<<endl;  }
	};

};

int main()
{	c1::c2 c;
	c.display();
	return 0;
}
