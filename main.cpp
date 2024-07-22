#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class CDonThuc
{
    private:
        float heso;
        int somu;
    public:
        friend istream& operator >> (istream &is , CDonThuc &a)
        {
            cout << "Nhap he so: ";
            is >> a.heso;
            cout << "Nhap so mu: ";
            is >> a.somu;
            return is;
        }

        friend ostream& operator << (ostream &os, CDonThuc &a)
        {
            os << a.heso << "x^" << a.somu;
            return os;
        }
       CDonThuc()
       {
           heso = 0;
           somu = 0;
       }

       CDonThuc(float a, int b)
       {
           heso = a;
           somu = b;
       }

      CDonThuc(const CDonThuc &a)
      {
          heso = a.heso;
          somu = a.somu;
      }

       ~CDonThuc()
       {
           return;
       }

       CDonThuc operator=(const CDonThuc &a)
       {
           heso = a.heso;
           somu = a.somu;
           return *this;
       }
       CDonThuc operator+(CDonThuc a)
       {
            CDonThuc temp;
            if (somu == a.somu)
            {
                temp.heso = heso + a.heso;
                temp.somu = somu;
                return temp;
            }
            else
                cout << "So mu cua 2 don thuc khong trung nhau.";
       }

       CDonThuc operator-(CDonThuc a)
       {
            CDonThuc temp;
            if (somu == a.somu)
            {
                temp.heso = heso - a.heso;
                temp.somu = somu;
                return temp;
            }
            else
                cout << "So mu cua 2 don thuc khong trung nhau.";
       }
       CDonThuc operator*(CDonThuc a)
       {
            CDonThuc temp;
            temp.heso = heso*a.heso;
            temp.somu = somu + a.somu;
            return temp;
       }
       CDonThuc operator/(CDonThuc a)
       {
            CDonThuc temp;
            if (a.somu == 0)
                cout << "Khong the chia do co he so bang 0.";
             else
            {
                temp.heso = heso/a.heso;
                temp.somu = somu - a.somu;
                return temp;
            }
       }
       
        int getHeSo() const { return heso; }
        int getSoMu() const { return somu; }

};

class CDaThuc
{
    private:
        vector<CDonThuc> donthucs;
    public:
        friend istream& operator >> (istream &is , CDaThuc &b)
        {
            int n;
            cout << "Nhap so luong don thuc: ";
            cin >> n;
            b.donthucs.resize(n);
            for (int i = 0 ; i < n ; i++)
            {
                cout << "Nhap don thuc thu " << i + 1 << ":\n";
                is >> b.donthucs[i];
            }
            return is;
        }

        friend ostream& operator << (ostream &os, CDaThuc &b)
        {
            for(size_t i = 0 ; i < b.donthucs.size() ; i++)
            {
                os << b.donthucs[i];
                if (i != b.donthucs.size() - 1)
                {
                    os << " + ";
                }
            }
            cout << endl;
            return os;
        }
        
        CDaThuc operator+(const CDaThuc &dt)
    {
        CDaThuc result = *this;
        for (const auto &donThuc : dt.donthucs)
        {
            bool found = false;
            for (auto &resDonThuc : result.donthucs)
            {
                if (resDonThuc.getSoMu() == donThuc.getSoMu())
                {
                    resDonThuc = resDonThuc + donThuc;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result.donthucs.push_back(donThuc);
            }
        }
        return result;
    }
             CDaThuc operator-(const CDaThuc& b) const
        {
            CDaThuc result = *this;
            for (const auto& x : b.donthucs) {
                bool found = false;
                for (auto& y : result.donthucs) {
                    if (y.getSoMu() == x.getSoMu()) {
                        y = y - x;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.donthucs.push_back(CDonThuc(-x.getHeSo(), x.getSoMu()));
                }
            }
            return result;
        }

};

int main()
{

     CDaThuc dt1, dt2;
    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;
    cout << "Nhap da thuc thu hai:\n";
    cin >> dt2;
    cout << dt1 << dt2;
    CDaThuc kq;
    kq = dt1 + dt2;
    cout << kq;
    CDaThuc kq1;
    kq1 = dt1 - dt2;
    cout << kq1;
}
