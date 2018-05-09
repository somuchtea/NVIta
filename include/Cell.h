#ifndef CELL_H
#define CELL_H
#include <iostream>
struct pack{
int n;//����� �������
int *connectedCells;
};//������ �������
class Cell
{
    public:
        Cell(pack pp,int ind);//"����",������
        Cell & operator = (const Cell &ce);
        Cell(const Cell &obj);
        Cell();
        ~Cell();
        void kill(){isAlive=0;}
        void revive(){isAlive=1;}
        int getIndex(){return index;}
        bool getState(){return isAlive;}
        int *neighboors,n;
        int lbords;
        bool isActive;
    private:
        bool isAlive;int index;

};

#endif // CELL_H
