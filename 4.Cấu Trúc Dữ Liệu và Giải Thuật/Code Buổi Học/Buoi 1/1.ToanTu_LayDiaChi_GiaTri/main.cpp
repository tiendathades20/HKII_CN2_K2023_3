#include <iostream>
using namespace std;
int main()
{
    char c ='F';
    int x = 10;
    float y = 1.8;
    printf("Dia chi bien chi c: %x\n", &c);
    cout << "Dia chi bien x: " << &x << "\nGia tri x = " << x << endl;
    cout << *(&y) << endl;
}
