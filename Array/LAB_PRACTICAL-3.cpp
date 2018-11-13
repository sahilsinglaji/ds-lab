#include<iostream>
using namespace std;
class array{
	public:
		void b_sort(int arr[],int n);
		void b_search(int arr[],int n);
};
void array::b_sort(int arr[],int n){
	int i=0,j=0,temp=0;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
		if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}
	cout<<"Array after sorting:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
void array::b_search(int arr[],int n){
	int mid,beg,end,pos,i=0,val=0,flag=0;
    cout<<"\nvalue to be searched";
    cin>>val;
	beg=0;
    end=n-1;
    for(i=beg;i<=end;i++){
        mid=(beg+end)/2;
        if (arr[mid]==val){
            pos=mid;
            flag=1;
        }
		else if(arr[mid]<val)
            beg=mid+1;
        else
            end=mid-1;
            }
    if(flag==1)
	cout<<"Element found at "<<pos+1<<"position";
    else
    cout<<"The number is not found in the array";
}
int main(){
	int arr[50];
	int n;
	int i;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	array a;
	a.b_sort(arr,n);
	a.b_search(arr,n);
	return 0;
}
