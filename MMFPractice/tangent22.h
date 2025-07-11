#pragma once

#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

const double pi = 3.14159265;

double f(double x, int n)
{
    double val = tan(x);
    if (n < 0 && val == 0.0)
    {
        return NAN;
    }

    return pow(val, n);
}

long double simpson(double a, double b, int n, int steps = 1000000)
{
    double h = (b - a) / steps;
    long double sum = f(a, n) + f(b, n);
    for (int i = 1; i < steps; i++)
    {
        long double x = a + i * h;
        long double val = f(x, n);
        if (i % 2 == 0)
        {
            sum += 2 * val;
        }
        else
        {
            sum += 4 * val;
        }
    }
    sum *= (h / 3.0);
    return sum;
}

bool checkPoints(double start, double end, double offset, double step)
{
    int kMin = (int)ceil((start - offset) / step);
    int kMax = (int)floor((end - offset) / step);
    for (int k = kMin; k <= kMax; k++)
    {
        double x_asym = offset + k * step;
        if (x_asym > start && x_asym < end)
        {
            return true;
        }
    }

    return false;
}

bool hasAsymptoteInside(double a, double b, int n)
{
    double start = min(a, b);
    double end = max(a, b);

    if (checkPoints(start, end, pi / 2, pi)) return true;

    if (n < 0 && checkPoints(start, end, 0.0, pi)) return true;

    return false;
}

bool isInfiniteOrNaN(double x, int n) {
    double val = f(x, n);
    return (isnan(val) || isinf(val));
}

int tangent22()
{
    setlocale(LC_ALL, "RU");
    double a{}, b{};
    int n;

    cout << "Введите нижний предел интегрирования a: ";
    cin >> a;
    cout << "Введите верхний предел интегрирования b: ";
    cin >> b;
    cout << "Введите степень n: ";
    cin >> n;

    if (a == b)
    {
        cout << "Значение интеграла от " << a << " до " << b << " (tan^(" << n << ")x) dx = 0" << endl;
        return 0;
    }

    if (isInfiniteOrNaN(a, n) || isInfiniteOrNaN(b, n))
    {
        cout << "Интеграл не сходится" << endl;
        return 0;
    }

    if (n == 0)
    {
        cout << "Значение интеграла от " << a << " до " << b << " (1) dx = " << (b - a) << endl;
        return 0;
    }

    if (hasAsymptoteInside(a, b, n))
    {
        cout << "Интеграл не сходится" << endl;
        return 0;
    }

    if (fabs(a) == fabs(b) && (n % 2 == 1))
    {
        cout << "Значение интеграла от " << a << " до " << b << " (tan^(" << n << ")x) dx = 0" << endl;
        return 0;
    }

    long double result = simpson(a, b, n);

    if (isnan(result) || isinf(result))
    {
        cout << "Интеграл не сходится" << endl;
    }
    else
    {
        cout << "Значение интеграла от " << a << " до " << b << " (tan^(" << n << ")x) dx = " << result << endl;
    }

    return 0;
}
