#include "lib.hpp"



using namespace std;


int Func::addUzel(){
    int k = 0;
    if(first_input == true ){
        cout << "Сколько узлов ты хочешь создать?\n"
        ":";
        if(get_num(k)<0){
            cout << "Error";
            return -1;
        }
        if( k > SZ ){
            cout << " Количество узлов превосходит разрешённое";
            return -2;
        }
        first_input = false;
        for (int i = 0; i < k ; i++){
            cout << "Enter X:";
             get_num(Arr[i].x);
            
            
            cout << "Enter Y:";
            get_num(Arr[i].y);
            
            cout << "\n";
            size_coor++;
        }
    }
    
    if (first_input == false and k == 0){
    
        if (size_coor < SZ) {
        cout << "Enter X:";
        get_num(Arr[size_coor].x);
        
        cout << "Enter Y:";
        get_num(Arr[size_coor].y);
        
        cout << "\n";
        size_coor++;
    }
    else{
        cout<< "Количество узлов максимально";
    }
    
    }
    return 0;
}

//Пузырьковая сортировка
void Func::sortBubl() {
    int last = size_coor; bool ok;
    do {
        last = last - 1;
        ok = true;
        for (int i = 0; i < last; i++) {
            if (Arr[i].x > Arr[i + 1].x) {
                int x = Arr[i].x;
                int y = Arr[i].y;
                Arr[i].x = Arr[i + 1].x;
                Arr[i].y = Arr[i + 1].y;
                Arr[i + 1].x = x;
                Arr[i + 1].y = y;
                ok = false;
            }
        }
    } while (!ok);
}

double Func::maximum(){
    double max = Arr[0].x;
    for (int i = 0; i < size_coor; i++)
    {
        if (Arr[i].x > max )
           max = Arr[i].x;
    }
    return max;
    
}

double Func::minimum(){
    int min = Arr[0].x;
    for (int i = 0; i < size_coor; i++)
    {
        if (Arr[i].x < min )
            min = Arr[i].x ;
    }
    return min;
}

void Func::typeF()
{
    sortBubl();
    int ub = 0;
    int vozr = 0;
    int post = 0;
    for (size_t i = 0; i < size_coor - 1; i++)
    {
        if (Arr[i + 1].y > Arr[i].y)
            vozr++;
        else if (Arr[i + 1].y < Arr[i].y)
            ub++;
        else
            post++;
    }
    if (ub > 0 and vozr > 0)
        cout << "f  = variable(?)" << endl;
    else if (ub > 0 and vozr == 0 and post == 0)
        cout << "f  = decreases(-)" << endl;
    else if (vozr > 0 and ub == 0 and post == 0)
        cout << "f = increases(+)" << endl;
    else if (post > 0 and ub == 0 and vozr == 0)
        cout << "f = constant(=)" << endl;
    
}


double Func::calculateF( double xO)
{
    sortBubl();
    double max = Arr[0].x;
    int indexMax = 0;  // индекс
    for (int i = 0; i < size_coor; i++)
    {
        if (Arr[i].x <= max && xO <= Arr[i].x) {
            max = Arr[i].x;
            indexMax = i; }
    }
    // вычисление ближайшего меньшего и его индекса

    int min = Arr[size_coor-1].x;
    int indexMin = 0;
    for (int i = 0; i < size_coor; i++)
    {
        if (Arr[i].x >= min && xO >= Arr[i].x ) {
            min = Arr[i].x ;
            indexMin = i; };
    }
    return (double(max - xO) / (max - min)) * Arr[indexMin].y + (double(xO - min) / (max - min)) * Arr[indexMax].y;

}

ostream & Func::printFunc(ostream &buf) const
{   int size = size_coor;
    for ( int i = 0; i < size && i < SZ; i++){
        buf
        <<"f("<< Arr[i].x << ") = " << Arr[i].y << endl;
        
    }
    return buf;
}






