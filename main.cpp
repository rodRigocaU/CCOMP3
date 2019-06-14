#include <iostream>
#include <stdlib.h>
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




template<class T>
void cocktail(T *p, T siz, bool (*np)(int * , int *))
{
    int *startr;
    int *startl;
    int *en;
    int *enl;
    int aux = 0;
    bool sorted = true;
    int vuel;
    if(false)
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
    }
    else if(true)
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

                if(/**(startr) < *(startr + 1)*/(*np)((startr),(startr + 1)) )
                {
                    sorted = true;
                    swaper((startr),(startr + 1));
                    startr++;
                }
                else if(!(*np)((startr),(startr + 1)) /**(startr) > *(startr + 1) */&& startr != en)
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
                if((*np)((startl-1),(startl))/**(startl) > *(startl - 1)*/)
                {
                    sorted = true;
                    swaper((startl), (startl - 1));
                    startl--;
                }
                else if(!(*np)((startl-1),(startl))/**(startl) < *(startl - 1)*/ && startl != enl)
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
    cocktail<int>(a,siz,ptsr);
    printArray(a,siz);
    return 0;
}
