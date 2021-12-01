#include "lib.hpp"



using namespace std;

istream & operator>> (istream & in, Func & uz)
{
    if (uz.size_coor >= uz.SZ)
        return in;
    
    cout << "Enter X:";
    in >> uz.Arr[uz.size_coor].x;
    
    cout << "Enter Y:";
    in >> uz.Arr[uz.size_coor].y;
    
    cout << "\n";
    uz.size_coor++;
    
    return in;
}

Func& Func::operator+= (const uzel & uz)
{
    if (size_coor >= SZ)
        return *this;
    Arr[size_coor] = uz;
    size_coor++;
    return *this;
}

//Пузырьковая сортировка
void Func::sortBubl()
{
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

double Func::maximum()
{
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


double Func::operator() ( double xO)
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

Func::operator bool() const{
    return size_coor > 0;
}
ostream & operator<<(ostream &buf, const Func & uz)
{   int size = uz.size_coor;
    for ( int i = 0; i < size && i < uz.SZ; i++){
        buf
        <<"f("<< uz.Arr[i].x << ") = " << uz.Arr[i].y << endl;
        
    }
    return buf;
}
