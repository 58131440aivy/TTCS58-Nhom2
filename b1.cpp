#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define max 100
//nhap ma tran ngau nhien
void nhapmatranngaunhien(int a[][100], int &n,int &m){
	do{
		cout<<"nhap so dong n: ";
		cin>>n;
		cout<<"nhap so cot m bang so cot n: ";
		cin>>m;
		if((n<3)&&(m<3)|| (n>100)&&(m>100))
			cout<<"\n nhap lai n va m !";
		}while( (n<3)&&(m>3) || (n>100)&&(m>100));
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j]=rand()%51;
		}
	}
}
//xuat ma tran
void xuatmatran(int a[][100],int n,int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n"<<endl;
	}
}
//xoa dong
void xoadong(int a[][100],int &n,int m){
	int dong;
	cout<<"nhap dong can xoa: ";
	cin>>dong;
	for(int i=dong; i<n-1 ; i++){
		for(int j=0; j<m; j++){
			a[i][j]=a[i+1][j];
		}
	}
	n--;
	xuatmatran(a,n,m);
}
//xoa cot
void xoacot(int a[][100],int n, int &m){
	int cot;
	cout<<"nhap cot can xoa: ";
	cin>>cot;
	for(int i=0;i<n;i++){
		for(int j=cot;j<m-1;j++){
			a[i][j]=a[i][j+1];
		}
	}
	m--;
	xuatmatran(a,n,m);
}
//kiem tra doi xung
void ktdoixung(int a[][100],int n, int m){
	int dem=0;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<m; j++){
			int c=a[i][j]-a[j][i];
			if(c==0)
				dem++;
		}
	}
	int d=n*(n-1)/2;	//so phan tu dang xet
	if(dem==d)	cout<<"doi xung!\n";	//neu dem bang so phan tu dang xet thi co nghia la cac phan tu bang nhau
	else	cout<<"khong doi xung!\n";
}
bool kiemtrasohoanghau(int a[][100], int vtdong, int vtcot, int n, int m)
{
	int x = a[vtdong][vtcot];
	//ktra dong
	for (int i = 0; i <m; i++)
	{
		if (a[vtdong][i] > x)
			return false;
	}
	//ktra cot
	for (int j = 0; j < m; j++)
	{
		if (a[j][vtcot] > x)
			return false;
	}

	//ktra duong cheo thu nhat
	int vtdong1 = vtdong + 1;
	int vtcot1 = vtcot + 1;
	while (vtcot1 + 1 < n && vtdong1 < vtdong)
	{
		if (a[vtcot1][vtdong1] >x)
			return false;
		vtcot1++;
		vtdong1++;
	}
	vtdong1 = vtdong - 1;
	vtcot1 = vtcot - 1;
	while (vtcot1 - 1 >= 0 && vtdong1 >= 0)
	{
		if (a[vtcot1][vtdong1] >x)
			return false;
		vtcot1--;
		vtdong1--;
	}

	// duong cheo thu 2
	vtdong1 = vtdong + 1;
	vtcot1 = vtcot - 1;
	while (vtcot1 - 1 >= 0 && vtdong1 < n)
	{
		if (a[vtcot1][vtdong1] >x)
			return false;
		vtdong1++;
		vtcot1--;
	}
	vtdong1 = vtdong - 1;
	vtcot1 = vtcot + 1;

	while (vtdong1 - 1 >= 0 && vtcot1 < m)
	{
		if (a[vtcot1][vtdong1] >x)
			return false;
		vtdong1--;
		vtcot1++;
	}
	return true;
}
int sohoanghau(int a[][100],int n, int m){
	int dem=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x=a[i][j];
			if(kiemtrasohoanghau(a,i,j,n,m)){
				dem++;
			}
		}
	}cout<<"so luong hau: "<<dem<<endl;
}
int main(){
	int a[100][100];
	int n,m;
	nhapmatranngaunhien(a,n,m);
	cout<<"ma tran la: "<<endl;
	xuatmatran(a,n,m);
	xoadong(a,n,m);
	xoacot(a,n,m);
	ktdoixung(a,n,m);
	sohoanghau(a,n,m);
}
