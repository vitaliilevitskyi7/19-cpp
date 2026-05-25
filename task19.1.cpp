#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n;
    std::cout << "Введіть кількість покупців n: ";
    std::cin >> n;

    if (n <= 0) return 1;

    std::vector<double> t(n); // Час обслуговування
    std::cout << "Введіть час обслуговування для кожного покупця (через пробіл):\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    std::vector<double> c(n); // Час перебування в черзі
    double current_time = 0;

    for (int i = 0; i < n; ++i) {
        // Покупець i приходить у момент часу i (оскільки кожен наступний через 1 хв)
        double arrival_time = i;
        
        // Якщо продавець звільнився раніше, ніж прийшов покупець
        if (current_time < arrival_time) {
            current_time = arrival_time;
        }
        
        // Час закінчення обслуговування
        current_time += t[i];
        
        // Загальний час перебування в черзі (разом з обслуговуванням)
        c[i] = current_time - arrival_time;
    }

    std::cout << "\nЧас перебування кожного покупця в черзі c_i:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Покупець " << i + 1 << ": " << c[i] << " хв\n";
    }

    // Пошук покупця з мінімальним часом обслуговування
    auto min_t_it = std::min_element(t.begin(), t.end());
    int min_t_buyer = std::distance(t.begin(), min_t_it) + 1;

    // Пошук покупця з максимальним часом у черзі
    auto max_c_it = std::max_element(c.begin(), c.end());
    int max_c_buyer = std::distance(c.begin(), max_c_it) + 1;

    std::cout << "\nНомер покупця з найменшим часом обслуговування: " << min_t_buyer << "\n";
    std::cout << "Номер покупця, який провів у черзі найбільше часу: " << max_c_buyer << "\n";

    return 0;
}
