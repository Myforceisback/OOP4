#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

class Arr {
private:
    int* a;
    int n;
    void Create() {
        a = new int[n];
    }

public:
    Arr() : n(5) { Create(); }
    Arr(int size) : n(size) { Create(); };
    ~Arr() { delete[] a; }

    void set() {
        cout << "Write elements:\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void output() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }


    Arr operator + (const Arr& other) {
        int sum_n;
        sum_n = this->n + other.n;
        Arr temp(sum_n);
        for (int i = 0; i < sum_n; i++) {
            temp.a[i] = 0;
        }
        for (int i = 0; i < this->n; i++) {
            temp.a[i] += this->a[i];
        }
        for (int i = this->n; i < sum_n; i++) {
            temp.a[i] += other.a[i];
        }
        return temp;
    }

    bool operator == (const Arr& other) {

        int tmp = 0;

        if (this->n == other.n) {
            for (int i = 0; i < n; i++) {
                if (this->a[i] == other.a[i]) {
                    tmp += 1;
                }
            }
            if (tmp == n) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }

    }
};

int main()
{
    int n; cout << "Size Plenty0: "; cin >> n;
    Arr plenty0(n);
    plenty0.set();
    plenty0.output();
    //Zadanie 1


    int nn; cout << "Size Plenty1: "; cin >> nn;
    Arr plenty1(nn);
    plenty1.set();
    plenty1.output();
    
    //Zadanie 2
    int sum_n;
    Arr plentysum = plenty0 + plenty1;
    plentysum.output();

    //Zadanie 3
    bool res = plenty0 == plenty1;
    if (res == 1) {
        cout << "Two Plantys are EQUAL" << endl;
    }
    else {
        cout << "Two Plantys are NOT EQUAL" << endl;
    }
    system("pause");
    return 0;
}