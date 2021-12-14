#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //check for column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }
    //check for the left digonal
    int x=i;int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        x--; y--;
    }
    //check for the right diagonal
    x=i; y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
            return false;
        x--; y++;
    }
    //now the position is safe bcoz we have checked for both the diagonals and columns
    return true;
}

bool solveNQueen(int board[][10], int i, int n, int &count)
{
    if(i==n)
    {   //we have placed n queens successfully in n rows(0...n-1)
        //print the board
        ++count;
        cout<<"solution "<<count<<": "<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    cout<<" Q ";
                else
                {
                    cout<<" _ ";
                }
            }
            cout<<endl; 
        }
        cout<<endl<<endl;
        return false;
    }
    //recusive case
    //try to place the Queen in the current row and call on the remaining part which will be solved by the recursion
    for(int j=0; j<n; j++)
    {
        //we cant place the queen blindly 
        //we will have to check whether the position is safe or not
        if(isSafe(board, i, j, n))
        {   //place the Queen-assuming i,j is teh right position
            board[i][j]=1;
            bool nextQueenRakhPay = solveNQueen(board, i+1, n, count);
            if(nextQueenRakhPay)
                return true;
            board[i][j]=0;//if we we are getting false from the next part of the bord then we will have to change the pos of the queen placed in the current row
        }    
    }return false;//this means that we have tried for all the positions in the current row but can find the right pos due to the queens placed above  
}

int main()
{
    cout<<"enter the number of squares:  ";
    int n;
    cin>>n;
    cout<<endl;
    int board[10][10]={0};
    int count = 0;
    solveNQueen(board, 0, n, count);
    cout<<endl<<"the total number of posiible solutions are = "<<count<<endl<<endl<<endl;
    return 0;
}

