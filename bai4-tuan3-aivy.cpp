#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int minKey(int n, int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = 0; // INT_MAX = +2147483647 cái này kiểu cú pháp đặt biệt của nó ... Lấy max của giá trị INT... Có thể lấy 100 hay 1000 đều được lấy bự nhất để xét dù trọng số nó bự bao nhiêu thì cũng đảm bảo tính đúng của bài toán
    for (int v = 0; v < n; v++){
        if (mstSet[v] == false && key[v] < min){
            min = key[v];
            min_index = v;
        }
        
    }
    return min_index;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //Mở file và nhập cây khung được tổ chức theo mảng 2 chiều.
    fstream test;
    test.open("prim.txt",ios::out);
    int n; // số đỉnh của cây khung
    cout<<"Nhập số đỉnh của cây khung: ";
    cin>>n;
    int arr[n][n]; // tạo mảng 2 chiều arr[n][n] số hàng bằng số cột. Dùng để lưu khoảng cách của các đỉnh với nhau
    cout<<"Nhập số liệu của cây khung: \n";
    cin.ignore();
    
    for (int i=0;i<n;i++){
        string textKey="";
        for(int j=0;j<n;j++){
            cin>>arr[i][j]; //Nhập khoảng cách giữa các cây khung. Nếu không có thì bằng 0
            string tem=to_string(arr[i][j]);
            textKey+=tem+" ";
        }
        test<<textKey<<endl;
    }
    
    test.close();
    //
    
    int parent[n]; // Lưu đỉnh cha của đỉnh V trong cây bao trùm nhỏ nhất
    int key[n];
    bool mstSet[n];  // Đánh dấu các đỉnh đã được thêm vào tập các đỉnh đã xét
    for(int i=0;i<n;i++){
        parent[i]=-1;
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    
    
    for(int i=0;i<n;i++){
        //Tìm cây khung nhỏ nhất tại vị trí i bằng hàm MINKEY được cài đặt ở trên hàm main
        int u = minKey(n, key, mstSet); //Hàm này trả về đỉnh của cây khung nhỏ nhất
        mstSet[u]=true; // sửa vị trí của đỉnh đó bằng true để đánh dấu là nó đã được duyệt
        
        for (int j = 0; j < n; j++){
            //nếu node đó chưa được duyệt
            if (arr[u][j] !=0 && mstSet[j] == false && arr[u][j] <  key[j]){
                parent[j]  = u;
                key[j] =  arr[u][j];
            }
        }
    }
    //Xuất cây khung tìm được ở vị trí đầu tiên bắt đầu là 0. Không có nút cha nên cho nút cha là -1( cái này là cài mặt định ban đầu)
    cout<<"Bắt đầu từ \n";
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" -> "<<i<<endl;
    }
    
    return 0;
}
