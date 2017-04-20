#include<iostream>
using namespace std;

int graph[8][8];
int my_color[8];

void getMatrix(int n) {
    cout<<"Enter the adjancy Matrix: "<<endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>graph[i][j];
}

bool previous(int old_vertex_color, int color) {

    // Return ture if previous vertex has same color
    if(my_color[old_vertex_color] == color)
        return true;
    return false;
}

void getColor(int row, int n, int color) {
    for(int col=0; col < n; col++) {

        // Found the vertex and assign color to it
        // find color for next vertex
        if(col == row) {
            my_color[row] = color;
            getColor(row + 1, n, 0);
        }

        // Choose another color if rowTH vertex is nieghbour ColTH vertex
        // and ColTh vertex is assigned with current color.
        if(graph[row][col] && previous(col, color))
            color++;
    }
}

void printColor(int n ){
    for(int i = 0; i < n; i++)
        cout<<my_color[i]<<" ";
}
int main() {
    int n;
    cout<<"Enter the Number of Vertex (max-8): ";
    cin>>n;
    getMatrix(n);
    getColor(0, n, 0);
    printColor(n);
}
