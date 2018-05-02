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
        for(int i=0;i<N;i++)
           {
               cout<<"ind="<<cells[i].getIndex();
               for(int j=0;j<cells[i].n;j++)
                cout<<" "<<cells[i].neighboors[j];
                cout<<'\n';
           }
}

field::~field()
{
    delete cells;
}
void field::getLbords()
{
    std::cout<<"ind="<<cells[0].getIndex()<<" "<<cells[0].neighboors[0]<<" "<<cells[0].neighboors[1];
    std::cout<<"ind="<<cells[1].getIndex()<<" "<<cells[1].neighboors[0]<<" "<<cells[1].neighboors[1]<<" "<<cells[1].neighboors[2];
    /*
    for(int i=0;i<N;i++)
    {
    //ss
       // cells[i].lbords=0;
        for(int j=0;j<cells[i].n;j++)
      //  {cells[i].lbords+=cells[cells[i].neighboors[j]].getState();
        std::cout<<cells[cells[i].neighboors[j]-1].getState()<<"  "<<cells[i].neighboors[j]-1<<"    ";//}
        std::cout<<'\n';
        std::cout<<"ind="<<cells[i].getIndex()<<",lbords="<<cells[i].lbords<<",n="<<cells[i].n<<'\n';
    }*/
}
void field::check()
{
    ;
}
void field::iteration()
{
    for(int i=1;i<N;i++)
    {
        if(cells[i].isActive)
            {
                if(cells[i].getState())
                    {
                        if(cells[i].lbords>=2)
                            {cells[i].isActive=0;}
                        else{cells[i].kill();}
                    }
                else{   if(cells[i].lbords>=3)
                            cells[i].revive();
                    }
            }
        else{cells[i].isActive=1;}
    }
}





