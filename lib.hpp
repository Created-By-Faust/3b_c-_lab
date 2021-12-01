

#ifndef lib_hpp
#define lib_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>
int get_num(T& i) {

    do {
        std::cin >> i;
        int peeked = cin.peek();

        if (peeked == 10 && std::cin.good()) {
            return 0;
        } else if (std::cin.bad()) {
            return -1;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number, enter again!\n";
        }
    } while (!cin.eof());

    return 0;
}

struct uzel{
    double x;
    double y;
};

class Func
{
private:
    static const int SZ = 5;
    uzel Arr[SZ];
    int size_coor = 0;
    bool first_input = true;

public:
    Func() = default;
    Func(double X_coor, double Y_coor) //конструктор по добавлению одного узла
    {
        if (size_coor < SZ) {
            Arr[size_coor].x = X_coor;
            Arr[size_coor].y = Y_coor;
            size_coor++;
        }
    }
    
    Func(int k, uzel* U) //конструктор с инициализацией количеством узлов и значениями функции в узла
    {
        for (size_t i = 0; i < k; i++)
        {
            Arr[size_coor].x = U[i].x;
            Arr[size_coor].y = U[i].y;
        
        }
        size_coor = k;

    }
    //Пузырьковая сортировка
    void sortBubl();

    //Поиск максимального и минимального элемента
    //void maxMinFunc(Func f);
    
    double maximum();
    double minimum();
    
    void typeF();

    double calculateF( double xO);
    
    ostream & printFunc(std::ostream &buf) const;

   
    int addUzel();
    };


#endif /* lib_hpp */
