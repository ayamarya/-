#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

// ��������� ��� ������������� ���������� ����
const int MAX_DIGITS = 10000;

class BigInt {
public:
    int digits[MAX_DIGITS];
    int size;

    // ������������
    BigInt(const string& num);
    BigInt(int num = 0);

    // ���������
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(int divisor) const;
    int operator%(int divisor) const;
    BigInt operator%(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;

    bool operator<(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    // ����� �������� �����
    friend ostream& operator<<(ostream& out, const BigInt& num);
};

// ��� ���� ������� �����
BigInt gcd(BigInt a, BigInt b);

// ��� ���� ������� �����
BigInt lcm(const BigInt& a, const BigInt& b);

// �������� ������������ �����
bool isValidInput(const string& input);

#endif // BIGINT_H
  