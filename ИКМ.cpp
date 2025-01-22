#include "BigInt.h"

int main() {
    setlocale(LC_ALL, "Russian");
    string m, n;

    cout << "Здравствуйте! Давайте найдём НОК для двух чисел)" << endl;

    // Проверяем коректно ли введено первое число
    while (true) {
        cout << "Введите целое число (m) >= 10^11 : ";
        cin >> m;
        if (isValidInput(m) && BigInt(m) >= BigInt(100000000000LL)) {
            break; 
        }
        cout << "Ой! Ошибка! попробуйте заново ввести целое число большее или равное 10^11: " << endl;
    }

    // Проверяем коректно ли введено второе число
    while (true) {
        cout << "Введите целое число (n) >= 10^11 : ";
        cin >> n;
        if (isValidInput(n) && BigInt(n) >= BigInt(100000000000LL)) {
            break; 
        }
        cout << "Ой! Ошибка! попробуйте заново ввести целое число большее или равное 10^11:" << endl;
    }

    BigInt num1(m), num2(n);
    cout << "НОК ваших чисел: " << lcm(num1, num2) << endl;

    return 0;
}