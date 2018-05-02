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
/*Cell& Cell::operator=(const Cell &ce )
{
 Cell OBJ(ce);
 OBJ.n=ce.n;
 for(int i=0;i<n;i++) OBJ.neighboors[i]=ce.neighboors[i];
 OBJ.index=ce.index;
 OBJ.isActive=ce.isActive;
 OBJ.isAlive=ce.isAlive;
 return OBJ;
}
Cell::Cell(const Cell &obj)
{
    n=obj.n;
    neighboors=new int[n];
    for(int i=0;i<n;i++)neighboors[i]=obj.neighboors[i];
    index=obj.index;
    isActive=obj.isActive;
    isAlive=obj.isAlive;
}*/
Cell::Cell()
{
    isAlive=0;
}
Cell::~Cell()
{
delete neighboors;
}

