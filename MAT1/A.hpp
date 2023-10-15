//
//  A.hpp
//  MAT1
//
//  Created by Michalis on 15.10.2023.
//

//#ifndef A_hpp
//#define A_hpp
//
//#include <stdio.h>

#pragma once
#include <iostream>

using namespace std;

class A {
    int** arr;
    int rows;
    int cols;
public:
    A();
    A(int, int);
    A(const A&);
    ~A();
    
    A& operator=(int a);

 
    void SetArr(int**);
    void SetRow(int);
    void SetColumn(int);


    int** GetArr() const;
    int GetRow() const;
    int GetColumn() const;
};


ostream& operator<<(ostream&, const A&);
istream& operator>>(istream&, A&);



int operator+(const A&, const int&); // Перегрузка +
int operator+(const int&, const A&);
int operator+(const A&, const A&);

int operator-(const A&, const int&); // Перегрузка -
int operator-(const int&, const A&);
int operator-(const A&, const A&);

int operator*(const A&, const int&); // Перегрузка *
int operator*(const int&, const A&);
int operator*(const A&, const A&);

double operator/(const A&, const int&); // Перегрузка /
double operator/(const int&, const A&);
double operator/(const A&, const A&);



bool operator<(const A&, const A&);
bool operator>(const A&, const A&);
