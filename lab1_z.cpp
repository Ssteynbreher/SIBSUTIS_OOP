// вариант 19

#include <iostream>
#include <string>

using namespace std;

class Paralelogram {
private:
    double side_a;
    double side_b;
    double corner_f;

public:

    //Конструктор по умолчанию
    Paralelogram() : side_a(1.0), side_b(1.0), corner_f(90.0) {}

    //Конструктор с параметрами
    Paralelogram(double a, double b, double f){

        side_a = a;
        side_b = b;
        corner_f = f;
    }

    bool Square() {
        return (side_a == side_b) && (corner_f == 90.0);
    }

    bool Rectangle() {
        return (corner_f == 90.0) && (side_a != side_b);
    }

    void outputTo() {
        cout << "Storona a: " << side_a << endl;
        cout << "Storona b: " << side_b << endl;
        cout << "Ygol megdy storonami: " << corner_f << endl;

        if (Square()) {
            cout << "Kvadrat" << endl;
        } else if (Rectangle()) {
            cout << "Pryamoygolnik" << endl;
        } else {
            cout << "Prosto parallelogramm" << endl;
        }
    }

    double get_side_a() {
        return side_a;
    }
    void set_side_a(double a) {
        side_a = a;
    }
    double get_side_b() {
        return side_b;
    }
    void set_side_b(double b) {
        side_b = b;
    }
    double get_corner_f() {
        return corner_f;
    }
    void set_corner_f(double f) {
        corner_f = f;
    }
};

int main() {
    int N;
    cout << "Vvedite kolichestvo parallelogrammov: ";
    cin >> N;

    Paralelogram **parallelograms = new Paralelogram *[N];

    int k1 = 0;
    int k2 = 0;
    for (int i = 0; i < N; i++) {
        double a, b, f;
        cout << "\nParallelogram " << i + 1 << endl;
        cout << "Vvedite storony a: ";
        cin >> a;
        cout << "Vvedite storony b: ";
        cin >> b;
        cout << "Vvedite ygol megdy storonami: ";
        cin >> f;

        parallelograms[i] = new Paralelogram(a, b, f);
        if (parallelograms[i]->Square()) {
            k1++;
        } else if (parallelograms[i]->Rectangle()) {
            k2++;
        }

        cout << "\nInformasia o parallelogramah" << endl;
        for (int i = 0; i < N; i++) {
            cout << "Parallelogram " << i + 1 << ": ";
            parallelograms[i]->outputTo();

            if (parallelograms[i]->Square()) {
                cout << "  Kvadrat" << endl;
            } else if (parallelograms[i]->Rectangle()) {
                cout << " Pryamoygolnik" << endl;
            } else {
                cout << "  Prosto parallelogram" << endl;
            }
        }



//        cout << "\n" << endl;
//        cout << "Количество квадратов (k1): " << k1 << endl;
//        cout << "Количество прямоугольников (k2): " << k2 << endl;
//        cout << "Количество других параллелограммов: " << N - k1 - k2 << endl;

//        // Освобождаем память
//        for (int i = 0; i < N; i++) {
//            delete parallelograms[i];
//        }
//        delete[] parallelograms;

        return 0;
    }
}