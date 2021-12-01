//
//  g_num.cpp
//  laba 3 ++
//
//

#include "g_num.hpp"
using namespace std;



int dialog(){
    int  res;
    Func p;

    while (true) {
        cout
            << "1. создание узла(-ов)\n"
            << "2. вывод узлов\n"
            << "3. добавление узла\n"
            << "4. тип функции n\n"
            << "5. вычисление в х0\n"
            << "6. максимум  минимум функции\n"
            << "7. выход\n"
            << endl;
        get_num(res);
        switch (res) {
            case 1:
                                
                if (p.addUzel() < 0) break;
                p.printFunc(cout);

                break;
            case 2:
                p.printFunc(cout);
                break;
            case 3:
                p.addUzel();
                break;
            case 4:
                p.typeF();
                break;
            case 5:
                int x0;
                cout << "Enter x0:";
                get_num(x0);
                cout << "f ("<< x0 << ") = " << p.calculateF(x0) << "\n";
                break;
            case 6:
                cout << "maximum: "<< p.maximum() << endl;
                cout << "minimum: "<< p.minimum() << endl;
                break;
            case 7:
                return 0;

        }
    }
}
