#include<iostream>
#include<stdlib.h>
#include<time.h>
#define max 100
using namespace std;
//ham random ngau nhien
void nhapngaunhien(int a[], int &n,int &m)
{
	for(int i=0; i<n; i++){
			a[i]=rand()% (m-2)+1;
	}
}
//ham xuat
void xuat(int a[],int n){
	for(int i=0;i<n;i++)
	cout<<" "<<a[i];
}
int main(){
	int a[max];
	int n,m;
	cout<<"nhap m: ";
	cin>>m;
	do{
		cout<<"nhap n: ";
		cin>>n;
		if(n>m){
			cout<<"nhap lai!";
		}
	}while(n>m);
	nhapngaunhien(a,n,m);
	cout<<"so ngau nhien: ";
	xuat(a,n);
	cout<<endl;
}
