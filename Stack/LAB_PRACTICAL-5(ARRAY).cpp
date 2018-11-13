#include<iostream>
using namespace std;
struct NODE{
	int info;
	NODE *link;
};
class linked_list{
	NODE *start;
	public:
		linked_list(){
			start=NULL;
		}
		void PUSH(int v)
		{
			NODE *p;
			p=new NODE();
			p->info=v;
			p->link=NULL;
			if(start==NULL)
			{
				start=p;
			}
			else
			{
				
				p->link=start;
				start=p;
			}
			
		}
		void PEEP()
		{
			NODE *q=start;
			while(q!=NULL)
			{
				cout<<q->info<<endl;
				q=q->link;
			}
	}
		void POP()
		{
			NODE *p,*q;
			p=start;
			start=p->link;
			p->link=NULL;
			delete(p);
		}
};
int main(){
	linked_list l;
	char ch;
	int n;
	cout<<"1. push"<<endl<<"2.pop"<<endl<<"3. peep"<<endl;
	do{cout<<"choose a case";
	cin>>n;
	switch(n)
	{
		case 1:
			{
			int item,v;
		cout<<"USING PUSH FUNCTION\nENTER NO OF ELEMENTS TO PUSH:\n";	
		cin>>item;
		for(int i=0;i<item;i++)
		{
			cin>>v;
		l.PUSH(v);	
		}
   break;
	}
	case 2:
	{
			cout<<"USING POP FUNCTION\n";
	l.POP();
	break;
		}	
		case 3:
			{
					cout<<"USING PEEP FUNCTION\n";
	
	           l.PEEP();
				break;
			}
			}
			cin>>ch;
	}
	while(ch=='Y');

}
