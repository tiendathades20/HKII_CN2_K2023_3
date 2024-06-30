#include <iostream>
using namespace std;
typedef int* pInt;
int main()
{
    int* p1; // con trỏ chưa khơi tạo
    int *p2; // con trỏ NULL
    int n = 36;
    int* p3 = &n; // con trỏ p3 chứa địa chỉ của n
    cout << "x = " << *p3;
}
