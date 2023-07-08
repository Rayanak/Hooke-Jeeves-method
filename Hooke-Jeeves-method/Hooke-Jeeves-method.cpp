#include <iostream>
#include <cmath>

// Функция, для которой ищем минимум
double objectiveFunction(const double x[2]) {
    // Пример: квадратичная функция f(x) = x^2 + y^2
    double result = pow(x[0], 2) + pow(x[1], 2);
    return result;
}

// Функция для изменения значений массива по шагу
void takeStep(double x[2], const double step[2], double stepSize) {
    for (int i = 0; i < 2; i++) {
        x[i] += stepSize * step[i];
    }
}

// Метод Хука-Дживса для поиска минимума функции
void hookeJeeves(const double startPoint[2], const double initialStep[2], double stepSize, double tolerance, double result[2]) {
    double x[2];
    double step[2];
    double value, newValue;

    for (int i = 0; i < 2; i++) {
        x[i] = startPoint[i];
        step[i] = initialStep[i];
    }

    value = objectiveFunction(x);

    while (stepSize > tolerance) {
        double nextX[2];
        for (int i = 0; i < 2; i++) {
            nextX[i] = x[i];
        }
        takeStep(nextX, step, stepSize);
        newValue = objectiveFunction(nextX);

        if (newValue < value) {
            for (int i = 0; i < 2; i++) {
                x[i] = nextX[i];
            }
            value = newValue;
        }
        else {
            stepSize /= 2;
            for (int i = 0; i < 2; i++) {
                step[i] /= 2;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        result[i] = x[i];
    }
}

int main() {
    double startPoint1[2] = { 0.0, 0.0 };
    double initialStep1[2] = { 0.1, 0.1 };
    double stepSize1 = 1.0;
    double tolerance1 = 0.01;
    double result1[2];

    hookeJeeves(startPoint1, initialStep1, stepSize1, tolerance1, result1);
    std::cout << "Минимум найден в точке (x, y): (" << result1[0] << ", " << result1[1] << ")" << std::endl;
    std::cout << "Значение функции в минимуме: " << objectiveFunction(result1) << std::endl;

    double startPoint2[2] = { 2.0, -1.0 };
    double initialStep2[2] = { 0.05, 0.05 };
    double stepSize2 = 0.5;
    double tolerance2 = 0.001;
    double result2[2];

    hookeJeeves(startPoint2, initialStep2, stepSize2, tolerance2, result2);
    std::cout << "Минимум найден в точке (x, y): (" << result2[0] << ", " << result2[1] << ")" << std::endl;
    std::cout << "Значение функции в минимуме: " << objectiveFunction(result2) << std::endl;

    return 0;
}
