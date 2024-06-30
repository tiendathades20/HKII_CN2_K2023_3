#include <iostream>
using namespace std;
struct ToaDo
{
  int x; //hoanh do
  int y; //tung do
};

void printTD(ToaDo t ) // ToaDo la một kiểu dữ liệu
{
    printf("(%d : %d)\n" , t.x, t.y);
}

void print1TD(ToaDo* t )
{
    printf("(%d : %d)\n" , t->x, t->y);
}

int main()
{
    ToaDo a  = { 1 , 5 }; // a la bien cau truc, truyền 1 cho x và 5 cho truyền y
    cout << a.x << ":" << a.y << endl; // xuat gia tri x bang a.x
    printTD(a);
    print1TD(&a);
    ToaDo* p1 = &a; //tạo ra con trỏ có KDL là tọa độ, con trỏ p1 trỏ tới địa chỉ của a
    ToaDo* p2 = new ToaDo({3,6}) ; // ToaDo là KDL mà ta định nghĩa ra
    print1TD(p2); // đưa vào địa chỉ
    printTD(*p2); // đưa vào giá trị
    cout << p2 -> x << endl;
    cout << (*p2).x << endl;
}
