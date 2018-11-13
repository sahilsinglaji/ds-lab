#include<iostream>
using namespace std;
struct node
{
	node *next;
	int data;
};
class stack
{
	node *start;
	public:
		stack()
		{
			start=NULL;
		}
		void push(int n)
		{
			node *new_node=new node;
			new_node->data=n;
			new_node->next=NULL;
			if(start==NULL)
			{
				start=new_node;
			}
			else 
			{
				new_node->next=start;
				start=new_node;
			}
		}
		void pop()
		{
			node *p;
			p=start;
			start=p->next;
			p->next=NULL;
			delete(p);
		}
		void display()
		{
			cout<<"The no. on top of the stack is "<<start->data<<endl;
		}
};
int main()
{
	stack a;
	int n,num;
	char ch;
	do{
		cout<<"enter the case"<<endl;
	cin>>n;
	switch(n)
		{
			case 1:
				int i;
				cout<<"enter the no. of values to be pushed"<<endl;
				cin>>i;
				for(int j=1;j<=i;j++)
				{
					cin>>num;
				a.push(num);}
				break;
			case 2:
				a.pop();
				break;
			case 3:
				a.display();
				break;
		}
		cout<<"press 'y' to continue"<<endl;
		cin>>ch;
}while(ch!='n');
}

