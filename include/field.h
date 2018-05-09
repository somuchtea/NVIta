#ifndef FIELD_H
#define FIELD_H
#include "Cell.h"
using namespace std;
const int rows=10;
const int columns=10;
struct Point{
int x,y;
};
/*Point ind2point(int ind)
{
    Point A;
    A.x=ind%columns;
    A.y=ind/rows;
    return A;
}*/

static pack mu(int ind)
{
    pack s;
    s.n=0;
   bool fl1=0,fl2=0,fl3=0,fl4=0;

    if(ind-1>0&&(ind-1)%columns>0){fl1=1;s.n++;}
    if(ind+1<=columns*rows&&((ind+1)%columns!=1)){fl2=1;s.n++;}
    if(ind-columns>0){fl3=1;s.n++;}
    if(ind+columns<=rows*columns){fl4=1;s.n++;}
     s.connectedCells=new int[s.n];
    int i=0;
     if(fl1==1){s.connectedCells[i]=ind-1;i++;}
     if(fl2==1){s.connectedCells[i]=ind+1;i++;}
     if(fl3==1){s.connectedCells[i]=ind-columns;i++;}
     if(fl4==1){s.connectedCells[i]=ind+columns;i++;}
    return s;
}
class field:public Cell
{
    public:
        field(int n,pack(*f)(int));//число клеток
        void iteration();
        void getLbords();
        void check();
        void SetCBF(pack(*func)(int ind)){CallbackF=func;}
        virtual ~field();
        Cell* getcells(){return cells;}
    private:
    class Cell *cells;int N;
    pack (*CallbackF)(int ind);
};

#endif // FIELD_H
