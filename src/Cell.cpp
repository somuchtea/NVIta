#include "Cell.h"

Cell::Cell(pack p,int ind)
{
    isAlive=0;
    isActive=1;
    lbords=0;
    index=ind;
    n=p.n;
    std::cout<<"ind="<<index;
    neighboors= new int[n];
    for(int i=0;i<n;i++)
      {   neighboors[i]=p.connectedCells[i];  std::cout<<"  i="<<i<<" nei="<<neighboors[i];}

std::cout<<'\n';
}
/*Cell&  Cell::operator=(Cell ce )
{
 n=ce.n;
 for(int i=0;i<n;i++) neighboors[i]=ce.neighboors[i];
 index=ce.index;
 isActive=ce.isActive;
 isAlive=ce.isAlive;
 return *this;
}*/
Cell::Cell()
{
    isAlive=0;
}
Cell::~Cell()
{
delete neighboors;
}

