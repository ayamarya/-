#include "BigInt.h"

// ����������� �� ������
BigInt::BigInt(const string& num) {
    size = num.size();
    memset(digits, 0, sizeof(digits));
    for (int i = 0; i < size; i++) {
        digits[i] = num[size - i - 1] - '0';
    }
}

// ����������� �� �����
BigInt::BigInt(int num) {
    memset(digits, 0, sizeof(digits));
    size = 0;
    while (num) {
        digits[size++] = num % 10;
        num /= 10;
    }
    if (size == 0) {
        size = 1;
        digits[0] = 0;
    }
}

// �������� ���� ������� �����
BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result;
    result.size = max(size, other.size);
    int carry = 0;

    for (int i = 0; i < result.size || carry; i++) {
        if (i == result.size) result.size++;
        result.digits[i] = carry + digits[i] + (i < other.size ? other.digits[i] : 0);
        carry = result.digits[i] / 10;
        result.digits[i] %= 10;
    }

    return result;
}

// ��������� ���� ������� �����
BigInt BigInt::operator-(const BigInt& other) const {
    BigInt result;
    result.size = size;
    int borrow = 0;

    for (int i = 0; i < size; i++) {
        result.digits[i] = digits[i] - borrow - (i < other.size ? other.digits[i] : 0);
        if (result.digits[i] < 0) {
            result.digits[i] += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }

    return result;
}

// ��������� ���� ������� �����
BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.size = size + other.size;
    memset(result.digits, 0, sizeof(result.digits));

    for (int i = 0; i < size; i++) {
        int carry = 0;
        for (int j = 0; j < other.size || carry; j++) {
            long long curr = result.digits[i + j] +
                digits[i] * 1LL * (j < other.size ? other.digits[j] : 0) + carry;
            result.digits[i + j] = curr % 10;
            carry = curr / 10;
        }
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }

    return result;
}

// ������� �� ��������� �����
BigInt BigInt::operator/(int divisor) const {
    BigInt result;
    result.size = size;
    memset(result.digits, 0, sizeof(result.digits));

    long long curr = 0;
    for (int i = size - 1; i >= 0; i--) {
        curr = curr * 10 + digits[i];
        result.digits[i] = curr / divisor;
        curr %= divisor;
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }

    return result;
}

// ������� �� ������� �� ��������� �����
int BigInt::operator%(int divisor) const {
    long long curr = 0;
    for (int i = size - 1; i >= 0; i--) {
        curr = (curr * 10 + digits[i]) % divisor;
    }
    return curr;
}

// ������� �� ������� �� ������ ������� �����
BigInt BigInt::operator%(const BigInt& other) const {
    BigInt dividend = *this;
    while (dividend >= other) {
        dividend = dividend - other;
    }
    return dividend;
}

// ������� �� ������ ������� �����
BigInt BigInt::operator/(const BigInt& other) const {
    BigInt result, current;
    result.size = size;

    for (int i = size - 1; i >= 0; i--) {
        current = current * 10 + digits[i];
        int x = 0, l = 0, r = 9;

        while (l <= r) {
            int m = (l + r) / 2;
            if (other * BigInt(m) <= current) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        result.digits[i] = x;
        current = current - other * BigInt(x);
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

// ��������� ���� ������� �����
bool BigInt::operator<(const BigInt& other) const {
    if (size != other.size) return size < other.size;
    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] != other.digits[i]) return digits[i] < other.digits[i];
    }
    return false;
}

bool BigInt::operator==(const BigInt& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool BigInt::operator<=(const BigInt& other) const {
    return *this < other || *this == other;
}

bool BigInt::operator>=(const BigInt& other) const {
    return !(*this < other);
}

// ����� �������� �����
ostream& operator<<(ostream& out, const BigInt& num) {
    for (int i = num.size - 1; i >= 0; i--) {
        out << num.digits[i];
    }
    return out;
}

// ��� ���� ������� �����
BigInt gcd(BigInt a, BigInt b) {
    while (!(b == BigInt(0))) {
        BigInt temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ��� ���� ������� �����
BigInt lcm(const BigInt& a, const BigInt& b) {
    return (a * b) / gcd(a, b);
}

// �������� ������������ �����
bool isValidInput(const string& input) {
    if (input.length() < 11) return false; // ������ 10^11
    for (char c : input) {
        if (!isdigit(c)) return false; // �� �������� ������
    }
    return true;
}