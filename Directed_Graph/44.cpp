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

class DirectedGraph
{
    char label[GRAPH_SIZE];
    bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
    bool visited[GRAPH_SIZE];
    int InDegree[GRAPH_SIZE];
    int OutDegree[GRAPH_SIZE];
    int GraphSize;
    void CheckIndex(int n)
    {
        if(n < 0 || n >= GRAPH_SIZE)
        {
            Error("Error Pos!");
        }
    }
    void VisitVertex(int n)
    {
        visited[n] = true;
        cout << label[n] << " ";
    }
    void DepthFirstSearchRecursion(int n)
    {
        if(visited[n] == true) return;
        VisitVertex(n);
        {
            for(int i = 0; i < GRAPH_SIZE; i++)
            {
                if(adjacent[n][i]) DepthFirstSearchRecursion(i);
            }
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
    DirectedGraph()
    {
        GraphSize = 0;
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            label[i] = NONE;
            visited[i] = false;
            InDegree[i] = 0;
            OutDegree[i] = 0;
            for (int j = 0; j < GRAPH_SIZE; j++)
            {
                adjacent[i][j] = 0;
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
        if (adjacent[n][m] == 0) adjacent[n][m] = true;
        else Error("Error Pos!");
        OutDegree[n]++; InDegree[m]++;
    }
    void DepthFirstSearch(int n)
    {
        ResetVisited();
        DepthFirstSearchRecursion(n);
    }
};

int main()
{
    DirectedGraph G1;

    G1.InsertVertex(0, 'S'); G1.InsertVertex(1, 'A'); G1.InsertVertex(2, 'B');
    G1.InsertVertex(3, 'C'); G1.InsertVertex(4, 'D'); G1.InsertVertex(5, 'E');
    G1.InsertVertex(6, 'F');

    G1.InsertEdge(0, 1); G1.InsertEdge(0, 2); G1.InsertEdge(1, 3);
    G1.InsertEdge(1, 4); G1.InsertEdge(2, 5); G1.InsertEdge(2, 6);

    G1.DepthFirstSearch(0);
}