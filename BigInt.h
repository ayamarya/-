#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

// Константа для максимального количества цифр
const int MAX_DIGITS = 10000;

class BigInt {
public:
    int digits[MAX_DIGITS];
    int size;

    // Конструкторы
    BigInt(const string& num);
    BigInt(int num = 0);

    // Операторы
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

    // Вывод большого числа
    friend ostream& operator<<(ostream& out, const BigInt& num);
};

// НОД двух больших чисел
BigInt gcd(BigInt a, BigInt b);

// НОК двух больших чисел
BigInt lcm(const BigInt& a, const BigInt& b);

// Проверка корректности ввода
bool isValidInput(const string& input);

#endif // BIGINT_H
  