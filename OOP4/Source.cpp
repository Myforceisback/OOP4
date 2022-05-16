#pragma once
#include<iostream>
#include<Windows.h>
#include<vector>
#include<algorithm>
using namespace std;
template <class T> class Set
{
private:
    int n;
    T num, delNum;
    vector<T> SetVector;

public:
    class NORMALNO_POIMAL {};
    class YAZs {};
    class bI {};
    Set() {};
    Set(int amount) {
        cout << "Enter number of elemnts (around 1 or 20): " << endl;
        cin >> amount;
        if (amount < 1 || amount > 20)  throw NORMALNO_POIMAL();
        else {
            cout << "Enter the elements : " << endl;

            for (int i = 0; i < amount; i++) {
                cin >> num;
                if (find(SetVector.begin(), SetVector.end(), num) == SetVector.end())
                    SetVector.push_back(num);
            }
            sort(SetVector.begin(), SetVector.end());
        }
    };
    BOOL operator -(T delNum) {
        if (SetVector.begin() == SetVector.end()) throw bI();
        else {
            SetVector.erase(remove(SetVector.begin(), SetVector.end(), delNum), SetVector.end());
            return true;
        }
    }
    void PrintSet() {
        cout << endl;

        for (int i = 0; i < SetVector.size(); i++) {
            cout << SetVector[i] << endl;
        }
    };
    BOOL operator >(Set<T> B) {
        return includes(SetVector.begin(), SetVector.end(), B.SetVector.begin(), B.SetVector.end());
    }
    BOOL operator !=(Set<T> right) {
        if (right.SetVector.size() != SetVector.size())
            return true;
        for (int i = 0; i < SetVector.size(); i++) {
            if (right.SetVector[i] != SetVector[i]) return true;
        }
        return false;
    }
    ~Set() {
        SetVector.clear();
    };
    BOOL operator +(T num) {
        if (SetVector.size() + 1 > 20) throw YAZs();
        else {
            if (find(SetVector.begin(), SetVector.end(), num) == SetVector.end())
                SetVector.push_back(num);
            else return false;
            sort(SetVector.begin(), SetVector.end());
            return true;
        }
    }
};

int main() {
    try {
        setlocale(LC_ALL, "rus");
        int num;
        Set<int>TSet(1);
        int delNum;
        TSet.PrintSet();
        system("pause");
        cout << "Enter element to delete:" << endl;
        cin >> delNum;
        Set<int>PODSet;
        PODSet - delNum;
        TSet.PrintSet();

        cout << endl << "Set 2 is multiplicity for Set 1: ";
        if (TSet > PODSet)
            cout << "YES" << endl;
        else cout << "NO" << endl;
        cout << "Set 1 and Set 2 are not equal: ";
        if (TSet != PODSet)
            cout << "YES";
        else cout << "NO";
        cout << endl;
        cin >> num;
        TSet + num;
        cout << endl;
        TSet.PrintSet();
        system("pause");
    }
    catch (Set<int>::NORMALNO_POIMAL) {
        cout << "ZDOROVENNI ILI MALENKI";
    }
    catch (Set<int>::bI) {
        cout << "NETY SETA";
    }
    catch (Set<int>::YAZs) {
        cout << "NO YAAAAZZZZ";
    }
    return 0;
}
