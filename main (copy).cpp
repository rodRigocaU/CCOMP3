#include <iostream>
#include <stdlib.h>
#include "string.h"
using namespace std;

//template<class U>
typedef bool(*pb)(int *, int *, bool);


void swaper(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

bool compro(int a, int b)
{
    return a > b;
}


bool compare1(int *a, int *b)
{
    return *a > *b;
}
bool compare2(int *a, int *b)
{

    return *b > *a;

}

template <class T>
class functore
{
    public:
    /*T *A;
    T *B;
    functore(T *a, T *b)
    {
        A = a;
        B = b;
    }*/
    bool operator()(/*string name*/bool (*ns)(T* , T* ), T *A, T *B)
    {
        /*if(name == "ascendente")
        {
            return *A > *B;
        }
        else if(name == "descendente")
        {
            return *A < *B;
        }*/
        return (*ns)(A,B);
        
    }
    bool compare3(T *, T *);
    bool compare4(T *, T*);
};

template <class T>
bool functore<T>::compare3(T *a, T *b)
{
    return *a > *b;
}
template <class T>
bool functore<T>::compare4(T *a , T *b)
{
    return *b > *a;
}


template<class T>
void cocktail(T *p, T siz , bool (*np)(int * , int *))
{
    int *startr;
    int *startl;
    int *en;
    int *enl;
    int aux = 0;
    bool sorted = true;
    int vuel;
    functore<T> c;
    ///G<T> c; 
    /*if(false)
    {
        startr = p;
        en =  p + (siz - 1);
        enl = p;
        vuel = 1;
         cout << *startr << '\n';
         cout << *en << '\n';
        cout << *enl << '\n';
        cout << " ENTRE " << '\n';
        cout << *p << '\n';
        while(sorted)
        {
            cout << "ok "<< '\n';
            sorted = false;
            if(vuel == 1)
            {
                if(*(startr) > *(startr + 1))
                {
                    sorted = true;
                    swaper((startr),(startr + 1));
                    startr++;
                }
                if(startr == en)
                {
                    vuel = 2;
                    en--;
                    startl = en;
                }
            }
            else
            {
                if(*(startl) < *(startl - 1))
                {
                    sorted = true;
                    swaper((startl), (startl - 1));
                    startl--;
                }
                if(startl == enl)
                {
                    vuel = 1;
                    enl++;
                    startr = enl;
                }
            }
        }
    }*/
    
    
    if(true)
    {
        startr = p;
        cout << *startr << '\n';
        en =  p + (siz - 1);
        cout << *en << '\n';
        enl = p;
        cout << *enl << '\n';
        vuel = 1;
        cout << " ENTRE " << '\n';
        cout << *p << '\n';
        while(sorted)
        {
            cout << "ok "<< '\n';
            sorted = false;
            if(vuel == 1)
            {

                if(/**(startr) < *(startr + 1) (*np)((startr),(startr + 1))*/ c(np,(startr),(startr + 1)) )
                {
                    sorted = true;
                    swaper((startr),(startr + 1));
                    startr++;
                }
                else if( !c(np,(startr),(startr + 1))/*!(*np)((startr),(startr + 1))  (startr) > *(startr + 1) */&& startr != en)
                {
                    sorted = true;
                    startr++;
                }
                if(startr == en)
                {
                    vuel = 2;
                    en--;
                    startl = en;
                }
            }
            else
            {
                if(c(np,(startl - 1),(startl)) /*(*np)((startl-1),(startl)) (startl) > *(startl - 1)*/)
                {
                    sorted = true;
                    swaper((startl), (startl - 1));
                    startl--;
                }
                else if(! c(np,(startl-1),(startl))/*(*np)((startl-1),(startl))/**(startl) < *(startl - 1)*/ && startl != enl)
                {
                    sorted = true;
                    startl--;
                }
                if(startl == enl)
                {
                    vuel = 1;
                    enl++;
                    startr = enl;
                }
            }
        }
    }

}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
}



int main()
{
    system("COLOR 0A");
    int a[] = {9,2,3,1,6,5,7,8,4};
    int siz = sizeof(a)/sizeof(a[0]);
    bool (*ptsr)(int *, int *) = compare1;
    ///functore<int> abs;
    cocktail<int>(a,siz,ptsr);
    printArray(a,siz);
    int *z; int *b;
    int a1 = 6;
    int b1 = 5;
    z = &a1;
    b = &b1;
    functore<int> hols;///Puedo con parametros o no para la construccion
    cout << hols.compare3(z,b) << '\n';
    cout << hols.compare4(z,b) << '\n';
    cout << hols(/*"descendente"*/ptsr,z,b) << '\n';
    return 0;

}