#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n;
    std::cout << "Введіть парну кількість елементів вектора N: ";
    std::cin >> n;

    // Валідація умови на парність елементів
    if (n <= 0 || n % 2 != 0) {
        std::cout << "Помилка: Кількість елементів має бути парною та більшою за 0.\n";
        return 1;
    }

    std::vector<int> V(n);
    std::cout << "Введіть " << n << " цілих чисел для заповнення вектора:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    std::deque<int> D;
    int half = n / 2;

    // 1. Перша половина чисел збігається з порядком заповнення (додаємо в кінець)
    for (int i = 0; i < half; ++i) {
        D.push_back(V[i]);
    }

    // 2. Друга половина чисел додається у зворотному порядку (додаємо на початок)
    for (int i = half; i < n; ++i) {
        D.push_front(V[i]);
    }

    // Виведення отриманого дека на екран
    std::cout << "\nОтриманий дек D:\n";
    for (int val : D) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
