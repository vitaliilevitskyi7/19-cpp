#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    int n, m;
    std::cout << "Введіть розміри матриці n та m (менші за 100): ";
    std::cin >> n >> m;

    if (n <= 0 || m <= 0 || n >= 100 || m >= 100) return 1;

    // Матриця як вектор списків за умовою
    std::vector<std::list<int>> matrix(n);

    std::cout << "Введіть елементи матриці за рядками:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val; std::cin >> val;
            matrix[i].push_back(val);
        }
    }

    // Сортуємо вектор списків за допомогою лямбда-функції.
    // Порівнюємо максимальні елементи в кожному списку для спадного порядку.
    std::sort(matrix.begin(), matrix.end(), [](const std::list<int>& a, const std::list<int>& b) {
        int max_a = *std::max_element(a.begin(), a.end());
        int max_b = *std::max_element(b.begin(), b.end());
        return max_a > max_b; // Спадний порядок
    });

    std::cout << "\nРезультат після перестановки рядків за спаданням їх максимумів:\n";
    for (int i = 0; i < n; ++i) {
        int current_max = *std::max_element(matrix[i].begin(), matrix[i].end());
        std::cout << "[Max: " << current_max << "] -> \t";
        for (int val : matrix[i]) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
