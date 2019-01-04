#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
using namespace std;
ifstream file("input.txt");
struct nhanvien{
	int manv, hsluong, hschucvu;
	int luong, luongcb;
	char hoten[20];
	char chucvu[20];
};
nhanvien a[30];
int n;
void nhap(){
	if(file.fail()){
		cout<<"khong tim thay file!"<<endl;
	}
	else {
		cout<<"nhap file thanh cong!"<<endl;
		file>>n;
		for(int i=0; i<n;i++){
			file>>a[i].manv;
			file>>a[i].hsluong;
			file>>a[i].hschucvu;
			file>>a[i].luong;
			file>>a[i].luongcb;
			file>>a[i].hoten;
			file>>a[i].chucvu;
		}
	}
}
void xuat(){
	for(int i=0; i<n;i++){
		cout<<"ma so nhan vien : "<<a[i].manv<<endl;
		cout<<"ho ten nhan vien: "<<a[i].hoten<<endl;
		cout<<"he so luong: "<<a[i].hsluong<<endl;
		cout<<"he so chuc vu: "<<a[i].hschucvu<<endl;
		cout<<"chuc vu: "<<a[i].chucvu<<endl;
	}
}
void tienluong(){
	for(int i=0; i<n;i++){
		a[i].luongcb=2000000;
		a[i].luong=a[i].luongcb*(a[i].hsluong+a[i].hschucvu);
		cout<<"so tien luong la: " <<a[i].luong<<endl;
	}
}
void sapxepluongtangdan(){
	cout<<"luong sau khi sap xep la: "<<endl;
	for(int i=0; i<n;i++){
		for(int j=i+1; j<n; j++){
			if(a[i].luong>a[j].luong){
				swap(a[i].luong,a[j].luong);
			}
		}
	}
	for(int i=0; i<n;i++){
		cout<<a[i].luong<<endl;
	}
}
void timkiem(){
	tienluong();
	int x;
	cout<<"nhap ma nhan vien can tim: ";
	cin>>x;
	for(int i=0; i<n; i++){
		if(a[i].manv==x){
			cout<<"thong tin nhan vien can tim la: "<<endl;
			cout<<"ma so nhan vien : "<<a[i].manv<<endl;
			cout<<"ho ten nhan vien: "<<a[i].hoten<<endl;
			cout<<"he so luong: "<<a[i].hsluong<<endl;
			cout<<"he so chuc vu: "<<a[i].hschucvu<<endl;
			cout<<"chuc vu: "<<a[i].chucvu<<endl;
			cout<<"tien luong: "<<a[i].luong<<endl;
		}
	}
}
void xoanhanvien(){
	int maso;
	cout<<"nhap ma so nhan vien can xoa: ";
	cin>>maso;
	for(int i=0; i<n; i++){
		if(a[i].manv==maso){
			a[i]=a[i+1];
		}
		n--;
	}
	cout<<"xoa thanh cong\n"<<endl;
}
int main(){
	nhap();
	xuat();
	timkiem();
	xoanhanvien();
	return 0;
}

