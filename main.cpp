#include <iostream>
#include <exception>
#include <cmath>
using namespace std;

void check0(int);

class div0 : public exception {
public:
    virtual const char* what() const throw() {
        return "Divided by zero";
    }
};

class fail : public exception {
public:
    virtual const char* what() const throw() {
        cin.clear();
        cin.ignore(50, '\n');
        return "STUPID!! You need to input 2 integers";
    }
};

fail f;

int main() {
    int x, y;
    double d;
    int a = 1;

    do {
        try {
            cout << "Enter 2 numbers: ";
            cin >> x >> y;

            if (cin.fail()) throw f;
            if (abs(x) > 1000 || abs(y) > 1000)
                throw "Value out of range";

            check0(y);

            d = (double)x / y;
            cout << "The result is " << d << endl;

            int i;
            double* myarray;

            for (i = 0; i < 100000; i++) {
                cout << "Allocating memory .... " << i << endl;
                myarray = new double[500000000];
            }

            a = 0;

        }
        catch (bad_alloc &e) {
            cout << "std::bad_alloc" << endl;
            a = 0;
        }


        catch (exception &e) {
            cout << e.what() << endl;
        }

        catch (const char* msg) {
            cout << msg << endl;
        }

    } while (a);

    return 0;
}

void check0(int x) {
    div0 e;
    if (x == 0)
        throw e;
}