// Вариант 2 (Мобильное устройство)

#include <iostream>
#include <string>

using namespace std;

class MB_Y {
private:
    string model;
    string soed;
    string opsys;

public:

    MB_Y(string m, string so, string os) {

        model = m;
        soed = so;
        opsys = os;
    }

    void outputTo() {
        cout << "Model ystroiystva: " << model << endl;
        cout << "Tip soedinenia: " << soed << endl;
        cout << "Operacionnaya sistema: " << opsys << endl;
        cout << "-----------------------" << endl;
    }

    string get_model() {
        return model;
    }

    void set_model(string m) {
        model = m;
    }

    string get_soed() {
        return soed;
    }

    void set_soed(string so) {
        soed = so;
    }

    string get_opsys() {
        return opsys;
    }

    void set_opsys(string os) {
        opsys = os;
    }
};

int main() {

    MB_Y Telefon1("HUAWEI", "wi-fi", "Android");
    MB_Y *Telefon2 = new MB_Y("Iphone 15", "wi-fi", "Apple");

    Telefon2->outputTo();
    Telefon1.outputTo();


    cout << "Informacia o mobilnih ystroiystvah: " << endl;

    Telefon1.outputTo();
    Telefon2->outputTo();

    return 0;
}