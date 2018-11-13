#include<iostream>
#include<string.h>
using namespace std;
int logic(char c);
int main(){
	char infix[50];
	char postfix[50];
	char stack[50];
	int st[50];
	int i=0,p=0,top=0;
	cin>>infix;
	int l=strlen(infix);
	infix[l]=')';
	infix[l+1]='\0';
	stack[++top]='(';
for(i=0;i<l+1;i++)
	{
	
		if((infix[i]>='0'&&infix[i]<='9')||(infix[i]>='A'&&infix[i]<='Z'))
		{
			postfix[p]=infix[i];
			p++;
		}
		else if(infix[i]=='(')
		{
			stack[++top]=infix[i];
		}
		else if(infix[i]==')')
		{
			char ch=stack[top--];
			while(ch!='(')
			{
				postfix[p]=ch;
				p++;
				ch=stack[top--];
			}
			top=top-1;
		}
		else{
			char ch1=stack[top--];
			while(logic(infix[i])<=logic(ch1))
			{
				postfix[p]=ch1;
				p++;
				ch1=stack[top--];
			}
			stack[++top]=ch1;
			stack[++top]=infix[i];
		}
	}
	postfix[p]='\0';
	cout<<"POSTFIC EXPRESSION: "<<postfix<<endl;
	int z=strlen(postfix);
	i=0;
	top=0;
	while(postfix[i]!='\0'){
		if(postfix[i]>='0'&&postfix[i]<='9')
		{
			st[++top]=postfix[i]-'0';
		}
		else{
		int a=st[top--];
		int b=st[top--];
		if(postfix[i]=='*')
		{
			st[++top]=a*b;
			//cout<<st[top]<<endl;
			}
			else if(postfix[i]=='+')
			{
				st[++top]=a+b;
			//	cout<<st[top]<<endl;
				}
				else if(postfix[i]=='-')
				{
				st[++top]=b-a;
				//cout<<st[top]<<endl;
				}
				
				else
				{
					st[++top]=b/a;
				//	cout<<st[top]<<endl;
				}
					
		}
		i++;
	}
	cout<<"THE VALUE OF POSTFIX:"<<st[top];
}
int logic(char c){
	if(c=='+'||c=='-')
	return 2;
	else if(c=='*'||c=='/')
	return 3;
	else
	return 1;
	
}
