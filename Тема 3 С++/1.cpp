#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std; 


double f(double x) {
    return 1.0 / (6 + x * x);
}


double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}


double trapezoidalMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}


double simpsonMethod(double a, double b, int n) {
    if (n % 2 == 1) n++; 
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        sum += (i % 2 == 0) ? 2 * f(a + i * h) : 4 * f(a + i * h);
    }
    return sum * h / 3.0;
}

int main() {
    setlocale(LC_ALL, "ru"); 

    double a = 2.0; 
    double b = 6.0;
    int n = 1000;

    cout << setprecision(10);
    cout << "Метод прямоугольников: " << rectangleMethod(a, b, n) << endl;
    cout << "Метод трапеций: " << trapezoidalMethod(a, b, n) << endl;
    cout << "Метод Симпсона: " << simpsonMethod(a, b, n) << endl;

    return 0;
}
