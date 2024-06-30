#include <iostream>
using namespace std;
typedef int* pInt;
int main()
{
    int a[100] = {1,3,6,9,5};
    cout << a << endl;
    cout << &a[0] << endl;
    int* b = new int[10]; //cấp phát động cho mảng b
}
