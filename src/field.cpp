#include "field.h"
#include <iostream>
using namespace std;
field::field(int n,pack (*fu)(int))
{
    SetCBF(fu);
    N=n;
    cells=new Cell[N];
    for(int i=0;i<N;i++)
        cells[i]=Cell(CallbackF(i),i); //оператор присваивания?
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
        {cells[i].lbords+=cells[cells[i].neighboors[j]].getState();}
        /*std::cout<<cells[cells[i].neighboors[j]].getState()<<"  "<<cells[i].neighboors[j]<<"    ";}
        std::cout<<'\n';
        std::cout<<"ind="<<cells[i].getIndex()<<",lbords="<<cells[i].lbords<<",n="<<cells[i].n<<'\n';
*/
}}
void field::check()
{
    ;
}
void field::iteration()
{
    int lisst[N]{0};
    for(int i=0;i<N;i++)
    {
       // if(cells[i].isActive)
            {
                if(cells[i].getState())
                    {
                        if(cells[i].lbords>=2&&cells[i].lbords<=3)
                           {
                               ;
                           } //{cells[i].isActive=0;}
                        else{lisst[i]=1;}//kill
                    }
                else{   if(cells[i].lbords==3)
                            lisst[i]=2;//revive
                    }
            }
        //else{
                if(cells[i].lbords==0)lisst[i]=1;//else cells[i].isActive=1;}
    }
    for(int i=0;i<N;i++)
        if(lisst[i])lisst[i]==1?cells[i].kill():cells[i].revive();
}





