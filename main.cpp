#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <locale>
using namespace std;

// Зчитування рівно трьох чисел з одного рядка.
// Повертає false при неправильному введенні або завершенні потоку.
bool readThreeDouble(double& a, double& b, double& c) {
    string line, extra;
    cout << "Введіть три числа через пробіл (десятковий роздільник - крапка): ";
    if (!getline(cin, line)) return false;
    istringstream input(line);
    input.imbue(locale::classic());
    if (!(input >> a >> b >> c) || (input >> extra) ||
        !isfinite(a) || !isfinite(b) || !isfinite(c)) {
        cout << "Помилка: потрібно ввести рівно три коректні числа.\n";
        return false;
    }
    return true;
}

// Зчитування рівно трьох цілих чисел.
void taskIf5() {
    cout << "\n--- If5: кількість додатних і від'ємних ---\n";
    string line, extra;
    long long a, b, c;
    cout << "Введіть три цілі числа через пробіл: ";
    if (!getline(cin, line)) return;
    istringstream input(line);
    if (!(input >> a >> b >> c) || (input >> extra)) {
        cout << "Помилка: потрібно ввести рівно три цілі числа.\n";
        return;
    }
    int positive = 0, negative = 0;
    if (a > 0) ++positive;
    else if (a < 0) ++negative;
    if (b > 0) ++positive;
    else if (b < 0) ++negative;
    if (c > 0) ++positive;
    else if (c < 0) ++negative;
    // Нуль не є ані додатним, ані від'ємним.
    cout << "Додатних: " << positive << "; від'ємних: " << negative << "\n";
}

// If15: сума двох найбільших із трьох чисел.
void taskIf15() {
    cout << "\n--- If15: сума двох найбільших ---\n";
    double a, b, c;
    if (!readThreeDouble(a, b, c)) return;
    // Вибираємо два найбільші числа без віднімання суми трьох,
    // щоб не отримувати зайвого переповнення проміжної суми.
    double first, second;
    if (a <= b && a <= c) { first = b; second = c; }
    else if (b <= a && b <= c) { first = a; second = c; }
    else { first = a; second = b; }
    double sum = first + second;
    if (!isfinite(sum)) {
        cout << "Помилка: результат завеликий для типу double.\n";
        return;
    }
    cout << "Сума двох найбільших: " << sum << "\n";
}

// If20: найближча до A точка на числовій осі.
void taskIf20() {
    cout << "\n--- If20: найближча до A точка ---\n";
    double a, b, c;
    if (!readThreeDouble(a, b, c)) return;
    double ab = fabs(a - b);
    double ac = fabs(a - c);
    if (!isfinite(ab) || !isfinite(ac)) {
        cout << "Помилка: відстань завелика для типу double.\n";
        return;
    }
    if (ab < ac) cout << "Найближча точка: B; відстань: " << ab << "\n";
    else if (ac < ab) cout << "Найближча точка: C; відстань: " << ac << "\n";
    else cout << "Точки B і C рівновіддалені від A; відстань: " << ab << "\n";
}

int main() {
    cout.imbue(locale::classic());
    cout << setprecision(12);
    string line, extra;
    int choice;
    while (true) {
        cout << "\n=== Лабораторна робота №3 ===\n"
             << "1 - If15 (сума двох найбільших)\n"
             << "2 - If5 (кількість додатних і від'ємних)\n"
             << "3 - If20 (найближча точка до A)\n"
             << "0 - Вихід\nВаш вибір: ";
        if (!getline(cin, line)) break;
        istringstream input(line);
        if (!(input >> choice) || (input >> extra)) {
            cout << "Помилка: введіть один цілий номер пункту меню.\n";
            continue;
        }
        // Оператор вибору запускає відповідну процедуру.
        switch (choice) {
            case 1: taskIf15(); break;
            case 2: taskIf5(); break;
            case 3: taskIf20(); break;
            case 0: cout << "Завершення роботи.\n"; return 0;
            default: cout << "Помилка: такого пункту меню немає.\n";
        }
    }
    return 0;
}
