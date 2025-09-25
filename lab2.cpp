#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Triangle
{
protected:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    // Проверка сущ треугольника
    bool exists() const
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Периметр
    double perimeter() const
    {
        return a + b + c;
    }

    // площадь
    double area() const
    {
        if (!exists())
            return 0;
        double p = perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual void printInfo() const
    {
        cout << "Treugol'nik so storonami: " << a << ", " << b << ", " << c << endl;
        cout << "Perimetr: " << perimeter() << endl;
        cout << "Ploshchad': " << area() << endl;
        cout << "-----------------------------" << endl;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}

    void printInfo() const override
    {
        cout << "Ravnostoronniy treugol'nik so storonoy: " << a << endl;
        cout << "Perimetr: " << perimeter() << endl;
        cout << "Ploshchad': " << area() << endl;
        cout << "-----------------------------" << endl;
    }
};

// генерация случ числа в диапазоне 
double randomDouble(double min, double max)
{
    return min + (rand() % static_cast<int>((max - min) * 100 + 1)) / 100.0;
}

int main()
{
    srand(time(0));
    int K, L;
    cout << "Vvedite kolichestvo obychnyh treugol'nikov (K): ";
    cin >> K;
    cout << "Vvedite kolichestvo ravnostoronnih treugol'nikov (L): ";
    cin >> L;
    // массив указателей на треугольники
    Triangle **triangles = new Triangle *[K + L];
    for (int i = 0; i < K; i++)
    {
        double a, b, c;
        do
        {
            a = randomDouble(1.0, 10.0);
            b = randomDouble(1.0, 10.0);
            c = randomDouble(1.0, 10.0);
        } while (!(a + b > c && a + c > b && b + c > a));

        triangles[i] = new Triangle(a, b, c);
    }
    for (int i = 0; i < L; i++)
    {
        double side = randomDouble(1.0, 10.0);
        triangles[K + i] = new EquilateralTriangle(side);
    }
    cout << "\n=== Vse treugol'niki ===" << endl;
    for (int i = 0; i < K + L; i++)
    {
        cout << "Figura " << i + 1 << ":" << endl;
        triangles[i]->printInfo();
    }
    double sumArea = 0;
    for (int i = 0; i < K; i++)
    {
        sumArea += triangles[i]->area();
    }
    double avgArea = (K > 0) ? sumArea / K : 0;
    cout << "Srednyaya ploshchad' " << K << " treugol'nikov: " << avgArea << endl;
    double maxArea = 0;
    int maxIndex = -1;

    for (int i = K; i < K + L; i++)
    {
        double currentArea = triangles[i]->area();
        if (currentArea > maxArea)
        {
            maxArea = currentArea;
            maxIndex = i;
        }
    }
    if (maxIndex != -1)
    {
        cout << "\nNaibol'shiy ravnostoronniy treugol'nik:" << endl;
        triangles[maxIndex]->printInfo();
    }
    else
    {
        cout << "\nRavnostoronnih treugol'nikov ne naideno." << endl;
    }
    return 0;
}