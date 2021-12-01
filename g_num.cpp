//
//  g_num.cpp
//  laba 3 ++
//
//

#include "g_num.hpp"
using namespace std;

int createUzels(Func &p){
    int k;
    cout << "Сколько узлов ты хочешь создать?\n"
    ":";
    if(get_num(k)<0){
        cout << "Error";
        return -1;
    }
    if( k > p.getSZ() ){
        cout << " Количество узлов превосходит разрешённое";
        return -2;
    }
    for (int i = 0; i < k ; i++){
        cin >> p;
    }
    return 0;
}

int addUzel(Func &p){
    uzel a;
    cout << "Enter X:";
    get_num(a.x);
    
    cout << "Enter Y:";
    get_num(a.y);
    
    p += a;
    
    return 0;
}

int dialog(){
    int  res;
    Func p;

    while (true) {
        cout
            << "1. создание узла(-ов)\n"
            << "2. добавление узла\n"
            << "3. вывод узлов\n"
            << "4. тип функции n\n"
            << "5. вычисление в х0\n"
            << "6. максимум  минимум функции\n"
            << "7. выход\n"
            << endl;
        get_num(res);
        
        switch (res) {
            case 1:
                createUzels(p);
                break;
            case 2:
                addUzel(p);
                break;
            case 3:
                cout << p;
                break;
            
                break;
            case 4:
                p.typeF();
                break;
            case 5:
                int x0;
                cout << "Enter x0:";
                get_num(x0);
                cout << "f ("<< x0 << ") = " << p(x0) << "\n";
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
