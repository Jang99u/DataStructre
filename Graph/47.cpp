#include <iostream>
#include <cstdlib>
#define GRAPH_SIZE 20
using namespace std;
const char NONE = '.';

void Error(string s)
{
    cout << s;
    exit(-1);
}

class Graph
{
protected:

    char label[GRAPH_SIZE];
    int degree[GRAPH_SIZE];
    bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
    int GraphSize;

    void CheckIndex(int n)
    {
        if(n < 0 || n >= GRAPH_SIZE) Error("Error Pos!");
    }

public:

    Graph()
    {
        GraphSize = 0;
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            label[i] = NONE;
            degree[i] = 0;
            for(int j = 0; j < GRAPH_SIZE; j++)
            {
                adjacent[i][j] = false;
            }
        }
    }

    void InsertVertex(int n, char c)
    {
        CheckIndex(n);
        if (label[n] != NONE) Error("Error Pos!");
        label[n] = c;
        GraphSize++;
    }

    void InsertEdge(int n, int m)
    {
        CheckIndex(n); CheckIndex(m);
        adjacent[n][m] = adjacent[m][n] = true;
        degree[n]++; degree[m]++;
    }

    void DeleteVertex(int n)
    {
        CheckIndex(n);
        if (label[n] == NONE) Error("Error Pos!");
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if(adjacent[n][i] || adjacent[i][n])
            {
                cout << "Delete Edge First" << endl;
                return;
            }
        }
        label[n] = NONE;
        GraphSize--;
    }

    void DeleteEdge(int n, int m)
    {
        CheckIndex(n); CheckIndex(m);
        adjacent[n][m] = adjacent[m][n] = false;
        degree[n]--; degree[n]++;
    }

    void PrintDegree()
    {
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if(label[i] == NONE) continue;
            cout << label[i] << " # of degree = " << degree[i] << endl;
        }
        cout << endl;
    }
};

int main()
{
    Graph G1;

    G1.InsertVertex(0, 'S');
    G1.InsertVertex(1, 'A');
    G1.InsertVertex(2, 'B');
    G1.InsertVertex(3, 'C');

    G1.InsertEdge(0, 1);
    G1.InsertEdge(0, 2);
    G1.InsertEdge(0, 3);
    G1.InsertEdge(1, 2);

    G1.PrintDegree();

    return 0;
}