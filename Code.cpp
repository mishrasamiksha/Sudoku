#include<iostream>
#include<stdlib.h>
using namespace std;
void print(int (*Sudoku)[6])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++) cout<<Sudoku[i][j]<<"|";
        cout<<endl;
    }
}
bool CanImove(int Num, int (*Sudoku)[6],int row, int col)
{
    int rlm=0,clm=0;
    if(row>=6||col>=6) return 0;
    if(col<=2)
    {
        clm=2;
        if(row<=1) rlm=1;
        else if(row<=3) rlm=3;
        else if(row<=5) rlm=5;
    }
    else if(col>2)
    {
        clm=5;
        if(row<=1) rlm=1;
        else if(row<=3) rlm=3;
        else if(row<=5) rlm=5;
    }
    for(int i=rlm-1; i<=rlm; i++) for(int j=clm-2; j<=clm; j++) if(Sudoku[i][j]==Num) return 0;
    for(int i=0; i<6; i++) if(Sudoku[row][i]==Num) return 0;
    for(int i=0; i<6; i++) if(Sudoku[i][col]==Num) return 0;
    return 1;
}
void Ss(int (*Sudoku)[6], int row,int col)
{
    if(col>=6&&row>=5)
    {
        print(Sudoku);
        exit(1);
    }
    if(col>=6) Ss(Sudoku,row+1,0);
    else if(Sudoku[row][col]!=0) Ss(Sudoku,row,col+1);
    else
    {
        for(int j=1; j<=6; j++)
        {
            if(CanImove(j,Sudoku,row,col))
            {
                Sudoku[row][col]=j;
                Ss(Sudoku,row,col+1);
                Sudoku[row][col]=0;
            }
        }
    }
}
int main()
{
    int Sudoku[6][6]= {{0,0,3,6,0,0},
                       {0,2,0,0,0,4},
                       {5,0,0,0,6,0},
                       {0,3,0,0,0,5},
                       {3,0,0,0,1,0},
                       {0,0,1,4,0,0}};
    Ss(Sudoku,0,0);
}
