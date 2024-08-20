#include<iostream>
#include<vector>
using namespace std;
void printsudoku(int sudoku[][9])
{
    cout<<"+------+------+------+"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j%3==0)cout<<"|";
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"|"<<endl;
        if((i+1)%3==0){
            cout<<"+------+------+------+"<<endl;
        }
    }
}
bool issafe(int sudoku[9][9] ,int row, int col, int digit)
{
    //vertical
    for(int i=0; i<=8;i++)
    {
        if(sudoku[i][col] == digit)
        {
            return false;
        }

    }
    //horizontal
    for(int j=0;j<=8; j++)
    {
        if(sudoku[row][j] == digit)
        {
            return false;
        }
    }
    //3*3 grid 
    int startrow = (row/3)*3;
    int startcol = (col/3)*3;
    for(int i = startrow;i<=startrow+2;i++)
    {
        for(int j=startcol;j<=startcol+2;j++)
        {
            if(sudoku[i][j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(int sudoku[9][9],int row, int col)
{
    if(row == 9)
    {
        //sudoku
        printsudoku(sudoku);
        return true;
    }
    int nextrow = row;
    int nextcol = col+1;
    
    if(col+1==9)
    {
        nextrow = row+1;
        nextcol = 0; 
    }
    if(sudoku[row][col]!=0)
    {
        return sudokusolver(sudoku, nextrow ,nextcol);
    }
    for(int digit=1;digit<=9;digit++)
    {
        if(issafe(sudoku, row, col, digit))
        {
            sudoku[row][col] = digit;    
            if(sudokusolver(sudoku,nextrow,nextcol))
            {
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    return false;
}
int main(){
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0 ,0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};  
    cout<<"SUDOKU PUZZLE"<<endl;
    printsudoku(sudoku);  
    cout<<"\nSOLVED SUDOKU PUZZLE:"<<endl; 
    sudokusolver(sudoku,0,0);
    return 0;
}