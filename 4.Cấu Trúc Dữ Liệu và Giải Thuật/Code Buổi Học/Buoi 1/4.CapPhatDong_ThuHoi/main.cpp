#include <iostream>
using namespace std;
typedef int* pInt;
int main()
{
    int* p = new int(369); // đây là cấp phát động
    cout << "Dia chi p da cap phat = " << p <<endl;
    //*p = 369;
    cout << "Gia tri tai vung nho = "  << *p << endl;
    delete p;
    cout << "Dia chi p da cap phat sau khi thu hoi = " << p <<endl;
    p = NULL; // thu hồi xong thì gán bằng NULL
    cout << "Dia chi p da cap phat sau khi thu hoi va gan NULL = " << p <<endl;
    cout << "Gia tri sau khi thu hoi = " << *p << endl;
}
