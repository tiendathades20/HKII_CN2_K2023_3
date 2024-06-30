#include <iostream>
using namespace std;
struct ToaDo
{
  int x;
  int y;

};

void printTD(ToaDo t )
{
    printf("(%d : %d)\n" , t.x, t.y);
}

void print1TD(ToaDo* t )
{
    printf("(%d : %d)\n" , t->x, t->y);
}

void printMangTD(ToaDo* a, int* n) // do đưa vào địa chỉ nên tham số là *a, *n
{
    for(int i = 0 ; i < *n ; i++)
    {
        print1TD(a+i); // do a+i là địa chỉ nên dùng hàm có tham số là địa chỉ
    }
}

void initGiaTriMangTD(ToaDo* a, int* n)
{
    *(a+0) = {1,2};
    *(a+1) = {3,4};
    *(a+2) = {5,6};
    *n =3;
}

int main()
{
    new int[100]; //cấp phát động mảng 100 ô
    ToaDo* a = new ToaDo[100]; // cấp phát động 100 vùng nhớ kiểu tọa độ, biến a con trỏ có kiểu DL là ToaDo
    int* n = new int(0); // n là số lượng thành phần mảng
    initGiaTriMangTD(a,n);
    printMangTD(a,n);

}
