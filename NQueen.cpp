#include<iostream>
#include<cmath>
using namespace std;

/*
 *     1                                  1                    n/a
 *     2                                  0                   < 0 seconds
 *     3                                  0                   < 0 seconds
 *     4                                  2                   < 0 seconds
 *     5                                 10                   < 0 seconds
 *     6                                  4                   < 0 seconds
 *     7                                 40                   < 0 seconds
 *     8                                 92                   < 0 seconds
 *     9                                352                   < 0 seconds
 *    10                                724                   < 0 seconds
 *    11                               2680                   < 0 seconds
 *    12                              14200                   < 0 seconds
 */

int Size;
int nrofSolution = 0;

void setQueen(int queens[], int row, int col) {
    for(int i=0; i < row; i ++) {
        // Backtracking conditions:
        if(queens[i] == col) return;   // check for same column
        if(abs(queens[i] - col) == (row - i)) return;  // Check for same diagonal
    }

    // Column is OK, set the queen
    queens[row] = col;

    if(row == (Size - 1)){
        nrofSolution++;   // Placed the final queen, found a solution
        for(int i = 0; i < Size; i++)
            cout<<queens[i];
        cout<<endl;
        for(int i=0; i < Size; i++) {
            for(int j = 0; j < Size; j++) {
                if(queens[i] == j)
                    cout<<"Q ";
                else
                    cout<<"- ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    else {
        // Try to fill the next rows
        for(int i = 0; i < Size; i++) {
            setQueen(queens, row+1, i);
        }
    }
}

void solve() {
    int *queens = new int[Size];

    for(int i=0; i < Size; i++) {
        setQueen(queens, 0, i);
    }
    delete [] queens;
}


int main() {

    do{
        cout<<"Enter the Board size: ";
        cin>>Size;
    }while(Size < 4 || Size > 15);
    cout<<endl;
    solve();
    cout<<"No of solution : "<<nrofSolution;
}
