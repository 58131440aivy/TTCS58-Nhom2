#include <iostream>
#include <string.h>
using namespace std;
int stringToNum(char c){
    return c - '0';
}
int numToString(int n){
    return (char)(n + 48);
}
void chuanHoa(string &a, string &b){
    int l1 = a.length();
    int l2 = b.length();
    if(l1 > l2){
        b.insert(0,l1-l2,'0');
    }
    else {
        a.insert(0,l2-l1,'0');
    }
}
void swapPointer( string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
//tinh tong 2 so
string tong(string a, string b)
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
    int temp = 0;
    for (int i=l-1; i>=0; i--)   // duyet va cong
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
        s.insert(0,1,numToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}

//hieu 2 so
string hieu(string a, string b)
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
    int temp = 0;
    for (int i=l-1; i>=0; i--)
    {
        temp = stringToNum(a[i]) - stringToNum(b[i]) - temp;    // tinh hieu tung doi mot
        s.insert(0,1,numToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}//Nhan 2 so nhan(a,b)

string nhanNho(char a, string b)
{
    string s = "";
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)
    {
        temp = stringToNum(a) * stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
    
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}

string nhan(string a, string b)     // nhan 2 so lon
{
    string s = "";
    int l = a.length();
    string s1[l];
    for (int i=l-1; i>=0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
    {
        s1[i] = nhanNho(a[i], b);   // nhan tung so cua a voi b
        s1[i].insert(s1[i].length(), l-i-1, '0');
        s = sum(s, s1[i]);  // cong don theo cach cong so lon
    }
    return s;
}
//menu nhap
void menu(){
    string a, b, s;
    cout<<"Nhap a va b: "<<endl;
    getline(cin, a);
    getline(cin, b);
    int chon;
    do {
        cout << "-------------MENU-------------------";
        cout << "\n1.---tinh tong a + b: ----------";
        cout << "\n2.---tinh hieu a - b: ---------";
        cout << "\n3.---tinh nha a*b: --------";
        cout << "\n------------------------------------\n";
        cout << "Nhap lua chon:"; cin >> chon;
    } while( chon < 0 || chon > 3);
    
    if (chon == 1)
    {
        s = sum(a,b);
        cout<<"\nTong cua a va b : "<<s<<endl;
    }
    else if(chon == 2)
    {
        s = sign(a,b);
        cout<<"\nHieu cua a va b : "<<s<<endl;
    }
    else if(chon==3)
    {
        s = nhan(a,b);
        cout<<"\nTich cua a va b : "<<s<<endl;
    }
}
int main(){
    string a, b, s;
    cout<<"Nhap a va b"<<endl;
    getline(cin, a);
    getline(cin, b);
    s = tong(a,b);
    cout<<"Tong cua a va b : "<<s<<endl;
    s = hieu(a,b);
    cout<<"Hieu cua a va b : "<<s<<endl;
    s = nhan(a,b);
    cout<<"Tich cua a va b : "<<s<<endl;
    menu();
    return 0;
}
