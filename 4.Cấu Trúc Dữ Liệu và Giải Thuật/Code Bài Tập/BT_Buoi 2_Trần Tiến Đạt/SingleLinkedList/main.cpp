#include <iostream>
#include <vector>
using namespace std;

// Câu 1: Xây dựng cấu trúc Node và cấu trúc danh sách liên kết đơn

struct Node
{
    float data;
    Node* pNext;
};

struct  List
{
    Node* pHead;
    Node* pTail;
};

//Câu 2: Viết hàm khởi tạo danh sách liên kết đơn và hàm khởi tạo địa chỉ node từ một số nguyên.

Node* initNode(float value)
{
   Node* p = new Node;
   if(p == NULL)
        return NULL;
   p->data = value;
   p->pNext = NULL;
   return p;
}

void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

//3. Viết hàm chèn node vào đầu danh sách.

void addHead(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

//4.Viết hàm chèn node vào cuối danh sách.

void addTail(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

//5. Viết hàm khởi tạo giá trị cho danh sách từ mảng một chiều.

void addListFromArr(List& l, float arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        addTail(l,initNode(arr[i]));
    }
}

//6. Viết hàm in giá trị danh sách đã nhập.

void   printListFor(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data <<"\t";
    }
    cout  <<"\n";
}

//7. Viết hàm in giá trị kèm địa chỉ của từng node trong danh sách.

void   printListValueAddress(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << "Gia tri la " << p->data <<", dia chi la " << p <<"\n";
    }
    cout  <<"\n";
}

//8. Viết hàm kiểm tra danh sách có rỗng hay không.

bool CheckListNull(List l)
{
    if(l.pHead == NULL)
        return true;
    else
        return false;
}

//9. Viết hàm trả về node thứ n trong danh sách.

Node* GetNode (List l, int index)
{
    int dem = 0;
    Node* a = l.pHead;
    while (a != NULL)
    {
        if(dem == index)
            return a;
        dem = dem + 1;
        a = a->pNext;
    }
    return NULL;
}

//10. Viết hàm tìm kiếm một node có giá trị X trong danh sách.

bool FindNode (List l, float x)
{
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if (a->data == x)
            return true;
    }
    return false;
}

//11. Viết hàm tìm kiếm các địa chỉ node có giá trị X trong danh sách.

Node* FindAddressNode (List l, float x)
{
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if (a->data == x)
            return a;
    }
    return NULL;
}

//Sử dụng khi có nhiều giá trị trùng nhau trong danh sách

vector<Node*> FindAddressNode1(List l, float x) {
    vector<Node*> add;

    Node* a = l.pHead;
    while (a != NULL) {
        if (a->data == x) {
            add.push_back(a); // Store the address of the node with value X
        }
        a = a->pNext;
    }

    return add;
}

//12. Viết hàm đếm số lượng các node có giá trị âm, dương.

void DemDuongAm (List l)
{
    int am = 0 , duong = 0;
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if(a->data < 0)
            am = am + 1;
        else
            duong = duong + 1;
    }
    cout << endl << "Tong so gia tri am la: " << am << endl;
    cout << "Tong so gia tri duong la: " << duong << endl;
}

//13. Viết hàm tìm node có giá trị âm lớn nhất, tìm node có giá trị lẻ nhỏ nhất trong danh sách.

void TimMaxAm (List l)
{
    Node* maxnagative = NULL;
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if(a->data < 0)
           if( (maxnagative == NULL) || (maxnagative->data < a->data ) )
           {
               maxnagative = a;
           }
    }
    if(maxnagative == NULL)
        cout << "Danh sach khong co gia tri am" << endl;
    else
        cout << "Gia tri am lon nhat trong mang la: " << maxnagative->data  <<endl;
}

void TimMinLe (List l)
{
    Node* minodd = NULL;
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if((int)(a->data) % 2 != 0)
           if( (minodd == NULL) || (minodd->data > a->data ) )
           {
               minodd = a;
           }
    }
    if(minodd == NULL)
        cout << "Danh sach khong co gia tri le" << endl;
    else
        cout << "Gia tri le nho nhat trong mang la: " << minodd->data  <<endl;
}


//14. Viết hàm cập nhật giá trị cho một node có giá trị là X bằng giá trị Y mới.

void UpdateValue (List &l, float m, float m_new)
{
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        if (a->data == m)
            a->data = m_new;
    }
    cout << "In danh sach sau khi thay doi: " ;
    printListFor(l);
}

//15. Viết hàm copy danh sách.

void CopyList(List l, List &l_copy)
{
    initList(l_copy);
    Node* a = l.pHead;
    for(Node* a = l.pHead ; a != NULL ; a = a->pNext)
    {
        addTail(l_copy,initNode(a->data));
    }
    cout << "In danh sach moi duoc copy:";
    printListFor(l_copy);
}

int main()
{
    //2. Viết hàm khởi tạo danh sách liên kết đơn và hàm khởi tạo địa chỉ node từ một số nguyên.
    //3. Viết hàm chèn node vào đầu danh sách.
    //4.Viết hàm chèn node vào cuối danh sách.

    List l;
    initList(l);
    addHead(l,initNode(5));
    addTail(l,initNode(10));

    //5. Viết hàm khởi tạo giá trị cho danh sách từ mảng một chiều.

    float arr[] = {1.1, 2.0, 3, 4, 5};
    int n = 5;
    addListFromArr(l,arr,n);

    //6. Viết hàm in giá trị danh sách đã nhập.

    printListFor(l);

    //7. Viết hàm in giá trị kèm địa chỉ của từng node trong danh sách.

    printListValueAddress(l);

    //8. Viết hàm kiểm tra danh sách có rỗng hay không.

    if (CheckListNull(l))
        printf("Danh sach rong");
    else
        printf("Danh sach khong rong");

    //9. Viết hàm trả về node thứ n trong danh sách.

    int index;
    cout << "\nVi tri Node can tim: ";
    cin >> index;
    Node* a = GetNode(l,index);
    if (a != NULL)
        cout << "Node tai vi tri index " << index <<": " << a->data <<endl;
    else
        cout << "Node tai vi tri index " << index << " khong ton tai";

    //10. Viết hàm tìm kiếm một node có giá trị X trong danh sách.

    float x;
    cout << "\nGia tri x can tim la: ";
    cin >> x;
    if (FindNode(l,x))
        cout << "Gia tri x = " << x << " tim thay trong danh sach" << endl;
    else
        cout << "Gia tri x = " << x << " khong tim thay trong danh sach" << endl;

    //11. Viết hàm tìm kiếm các địa chỉ node có giá trị X trong danh sách.

    Node* c = FindAddressNode(l,x);
    if (c != NULL)
        cout << "Gia tri x = " << x << " co dia chi la: " << c << endl;
    else
        cout << "Gia tri x = " << x << " khong tim thay trong danh sach" << endl;

     /*
    vector<Node*> d = FindAddressNode1(l, x);
    if (!d.empty()) {
        cout << "Nodes with value " << x << " found at addresses: ";
        for (Node* node : d) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No nodes with value " << x << " found.\n";
    }
    */

    //12. Viết hàm đếm số lượng các node có giá trị âm, dương.

    DemDuongAm(l);

    //13. Viết hàm tìm node có giá trị âm lớn nhất, tìm node có giá trị lẻ nhỏ nhất trong danh sách.

    TimMaxAm(l);
    TimMinLe(l);

    //14. Viết hàm cập nhật giá trị cho một node có giá trị là X bằng giá trị Y mới.

    float m,m_new;
    cout << "Gia tri trong danh sach can thay the la: ";
    cin >> m;
    cout << "Gia tri thay the la: ";
    cin >> m_new;
    if (FindNode(l,m))
        UpdateValue(l,m,m_new);
    else
        cout << "Gia tri m = " << m << " khong tim thay trong danh sach" << endl;

    //15. Viết hàm copy danh sách.

    List(l_copy);
    CopyList(l,l_copy);
}
