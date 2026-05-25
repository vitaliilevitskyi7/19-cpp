#include <iostream>
#include <list>
#include <cmath>
#include <numeric>

// Спрощений клас Раціональний дріб для демонстрації шаблону
class Rational {
public:
    int num; int den;
    Rational(int n = 0, int d = 1) : num(n), den(d) {
        if (den < 0) { num = -num; den = -den; }
        int g = std::gcd(std::abs(num), den);
        num /= g; den /= g;
    }
    Rational operator+(const Rational& o) const { return Rational(num * o.den + o.num * den, den * o.den); }
    Rational operator*(double scalar) const { return Rational(num * scalar, den); }
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) { os << r.num << "/" << r.den; return os; }
};

// Шаблон класу Поліном
template <typename T>
class Polynomial {
private:
    std::list<T> coefficients; // Контейнер STL

public:
    void input(int degree) {
        coefficients.clear();
        std::cout << "Введіть " << degree + 1 << " коефіцієнтів (від x^0 до x^" << degree << "):\n";
        for (int i = 0; i <= degree; ++i) {
            T val; std::cin >> val;
            coefficients.push_back(val);
        }
    }

    void print() const {
        int power = 0;
        for (const auto& coef : coefficients) {
            std::cout << "(" << coef << ")*x^" << power;
            if (++power < coefficients.size()) std::cout << " + ";
        }
        std::cout << "\n";
    }
};

// Спеціалізація для Rational, щоб спростити введення в консоль
std::istream& operator>>(std::istream& is, Rational& r) {
    is >> r.num >> r.den;
    r = Rational(r.num, r.den);
    return is;
}

int main() {
    std::cout << "--- Тест Полінома з типом double ---\n";
    Polynomial<double> p_double;
    p_double.input(2);
    std::cout << "Поліном: "; p_double.print();

    std::cout << "\n--- Тест Полінома з типом Rational (введення: чисельник знаменник) ---\n";
    Polynomial<Rational> p_rational;
    p_rational.input(1);
    std::cout << "Поліном: "; p_rational.print();

    return 0;
}
