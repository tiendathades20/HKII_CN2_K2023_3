#include <iostream>
using namespace std;
typedef int* pInt;
int main()
{
    char c ='F';
    int x = 10;
    double y = 1.8;

    double* p = &y;
    pInt p1 = &x;
    cout << "x = " << *(p1) << endl; //xuat ra gia tri x
    int* p2 , p3, p4; // p3, p4 là biến ko phải con trỏ
    int* p5 , *p6 = &x , p7 = &x; // p4 lỗi do p4 là biến, ko phải con trỏ
}
