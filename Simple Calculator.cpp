#include<iostream>
using namespace std;
int main()
{
	cout<<"menu\n";
	cout<<"1.Add\n"<<"2.sub\n"<<"3.multipy\n"<<"4.division\n";
	int choice;
	cout<<"Enter your choice:";
	cin>>choice;
	int a,b,c;
	cout<<"Enter the first number:\n";
	cin>>a;
	cout<<"Enter the second number:";
	cin>>b;
	switch(choice)
	{
		case 1:
               c = a + b;
               break;
        case 2:
               c = a - b;
               break;       
        case 3:
               c = a * b;
               break;       
        case 4:
               c = a / b;
               break;
             
    }
    cout<<"Result is"<<c;
}
