#include "field.h"
#include <iostream>
using namespace std;
field::field(int n,pack (*fu)(int))
{
    SetCBF(fu);
    N=n;
    cells=new Cell[N];
    for(int i=0;i<N;i++)
        cells[i]=Cell(CallbackF(i+1),i+1); //оператор присваивания?
        /*for(int i=0;i<N;i++)
           {
               cout<<"ind="<<cells[i].getIndex();
               for(int j=0;j<cells[i].n;j++)
                cout<<" "<<cells[i].neighboors[j];
                cout<<'\n';
           }*/
}

field::~field()
{
    delete cells;
}
void field::getLbords()
{
    for(int i=0;i<N;i++)
    {

        cells[i].lbords=0;
        for(int j=0;j<cells[i].n;j++)
        {cells[i].lbords+=cells[cells[i].neighboors[j]].getState();
        std::cout<<cells[cells[i].neighboors[j]].getState()<<"  "<<cells[i].neighboors[j]<<"    ";}
        std::cout<<'\n';
        std::cout<<"ind="<<cells[i].getIndex()<<",lbords="<<cells[i].lbords<<",n="<<cells[i].n<<'\n';

}}
void field::check()
{
    ;
}
void field::iteration()
{
    for(int i=0;i<N;i++)
    {
        if(cells[i].isActive)
            {
                if(cells[i].getState())
                    {
                        if(cells[i].lbords>=1)
                            {cells[i].isActive=0;}
                        else{cells[i].kill();}
                    }
                else{   if(cells[i].lbords>=2)
                            cells[i].revive();
                    }
            }
        else{if(cells[i].lbords==0)cells[i].kill();else cells[i].isActive=1;}
    }
}





