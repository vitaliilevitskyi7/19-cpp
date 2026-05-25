#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int d, n;
    std::cout << "Введіть розмірність векторів d та їх кількість n (через пробіл): ";
    std::cin >> d >> n;

    if (d <= 0 || n <= 0) return 1;

    std::vector<double> sum_vector(d, 0.0);

    for (int i = 0; i < n; ++i) {
        std::cout << "Введіть компоненти " << i + 1 << "-го вектора (" << d << " чисел):\n";
        for (int j = 0; j < d; ++j) {
            double val;
            std::cin >> val;
            sum_vector[j] += val; // Одразу накопичуємо суму
        }
    }

    // Обчислення евклідової норми суми векторів (корінь із суми квадратів)
    double sum_of_squares = 0.0;
    for (int j = 0; j < d; ++j) {
        sum_of_squares += sum_vector[j] * sum_vector[j];
    }
    double norm = std::sqrt(sum_of_squares);

    std::cout << "\nКомпоненти сумарного вектора: ( ";
    for (double val : sum_vector) std::cout << val << " ";
    std::cout << ")\n";
    
    std::cout << "Значення норми суми векторів: " << norm << std::endl;

    return 0;
}
