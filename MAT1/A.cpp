//
//  A.cpp
//  MAT1
//
//  Created by Michalis on 15.10.2023.
//

#include "A.hpp"
#include <iostream>


using namespace std;

A::A() {
    rows = 0;
    cols = 0;
    arr = nullptr;
}
A::A(int r, int c) {
    rows = r;
    cols = c;

    arr = new int * [rows];

    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = 0;
}
A::A(const A& obj) {
    rows = obj.rows;
    cols = obj.cols;
    arr = new int* [obj.rows];

    for (int i = 0; i < obj.rows; i++)
        arr[i] = new int[obj.cols];

    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; i < obj.cols; j++)
            arr[i][j] = obj.arr[i][j];
    }
}
A::~A() {
    if (arr != nullptr) {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
}



A& A::operator=(int a) {
    int** temp = new int* [1];
    *temp = new int[1];

    temp[0][0] = a;

    arr = temp;

    return *this;
}

void A::SetArr(int** a) {
    arr = a;
}
void A::SetRow(int r) {
    rows = r;
}
void A::SetColumn(int c) {
    cols = c;
}

int** A::GetArr() const {
    return arr;
}
int A::GetRow() const  {
    return rows;
}
int A::GetColumn() const {
    return cols;
}


// Перегрузка ввода-вывода
ostream& operator<<(ostream& os, const A& obj) {
    os << **obj.GetArr();

    return os;
}
istream& operator>>(istream& is, A& obj) {
    int** temp = new int* [1];
    *temp = new int[1];

    cin >> temp[0][0];

    obj.SetArr(temp);

    return is;
}



int operator+(const A& obj, const int& number) {
    return **obj.GetArr() + number;
}
int operator+(const int& number, const A& obj) {
    return **obj.GetArr() + number;
}
int operator+(const A& obj1, const A& obj2) {
    return **obj1.GetArr() + **obj2.GetArr();
}

int operator-(const A& obj, const int& number) {
    return **obj.GetArr() - number;
}
int operator-(const int& number, const A& obj) {
    return **obj.GetArr() - number;
}
int operator-(const A& obj1, const A& obj2) {
    return **obj1.GetArr() - **obj2.GetArr();
}

int operator*(const A& obj, const int& number) {
    return **obj.GetArr() * number;
}
int operator*(const int& number, const A& obj) {
    return **obj.GetArr() * number;
}
int operator*(const A& obj1, const A& obj2) {
    return **obj1.GetArr() * **obj2.GetArr();
}

double operator/(const A& obj, const int& number) {
    return **obj.GetArr() / number;
}
double operator/(const int& number, const A& obj) {
    return **obj.GetArr() / number;
}
double operator/(const A& obj1, const A& obj2) {
    if (**obj1.GetArr() == 0 || **obj2.GetArr() == 0)
        return 0;

    return **obj1.GetArr() / **obj2.GetArr();
}

bool operator<(const A& obj1, const A& obj2) {
    return **obj1.GetArr() < **obj2.GetArr();
}
bool operator>(const A& obj1, const A& obj2) {
    return **obj1.GetArr() > **obj2.GetArr();
}
