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
    bool visited[GRAPH_SIZE];
    int GraphSize;

    void CheckIndex(int n)
    {
        if(n < 0 || n >= GRAPH_SIZE) Error("Error Pos!");
    }

    void VisitVertex(int n)
    {
        visited[n] = true;
        cout << label[n] << " ";
    }

    void DepthFirstSearchRecursion(int n)
    {
        if (visited[n]) return;
        VisitVertex(n);
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if (adjacent[n][i]) DepthFirstSearchRecursion(i);
        }   
    }

    void ResetVisited()
    {
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            visited[i] = false;
        }
    }

public:

    Graph()
    {
        GraphSize = 0;
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            label[i] = NONE;
            degree[i] = 0;
            visited[i] = false;
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
        degree[n] = degree[m] = false;
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

    void PrintGraph()
    {
        for (int n = 0; n < GRAPH_SIZE; n++)
        {
            if (label[n] == false) continue;
            cout << "Vertex " << label[n] << "has neighbor ";
            for (int m = 0; m < GRAPH_SIZE; m++)
            {
                if(adjacent[n][m] == true) cout << label[m] << " ";
            }
            cout << endl;
        }
    }

    void DepthFirstSearch(int n)
    {
        ResetVisited();
        DepthFirstSearchRecursion(n);
    }
};

int main()
{

}