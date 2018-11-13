#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class queue
{
	node *rear,*front;
	node *start;
	public:
		queue()
		{
			start=NULL;
		}
		void ins(int item)
		{
			node *ptr;
			ptr=start;
			node *new_node=new node;
			new_node->data=item;
			new_node->next=NULL;
			if(start==NULL)
			{
				start=new_node;
				new_node->next=start;
			}
			else 
			{
				while(ptr->next!=start)
				{
					ptr=ptr->next;
				}
				new_node->next=start;
				ptr->next=new_node;
			}
		}
		void del()
		{
			node *p,*q;
			p=start;
			q=start->next;
			while(q->next!=start)
			{q=q->next;
			}
			start=start->next;
			q->next=start;
			p->next=NULL;
			delete(p);
		}
		void display()
		{
			node *d;
			d=start;
			cout<<d->data<<endl;
			d=d->next;
			while(d!=start)
			{
				cout<<d->data<<endl;
				d=d->next;
			}
		}
};
int main()
{char ch; 
 queue a;
do{
	int n;
	cout<<"enter the case";
	cin>>n;
	switch(n)
		{
			case 1:
				for(int i=0;i<5;i++)
				{int item;
				cout<<"enter the val";
				cin>>item;
				a.ins(item);
				}
				break;
			case 2:
				a.del();
				break;
			case 3:
				a.display();
				break;
		}
		cout<<"enter y to continue";
		cin>>ch;
}while(ch!='n');
}