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
    void DeleteVertex(int n)
    {
        CheckIndex(n);
        if(label[n] == NONE) Error("Error Pos!");
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if(adjacent[n][i] || adjacent[i][n])
            {
                cout << "Delete Edge First!" << endl;
                return;
            }
        }
        label[n] = NONE;
        GraphSize--;
    }    
    void InsertEdge(int n, int m)
    {
        CheckIndex(n); CheckIndex(m);
        if (adjacent[n][m] == 0) adjacent[n][m] = true;
        else Error("Error Pos!");
        OutDegree[n]++; InDegree[m]++;
    }
    void DeleteEdge(int n, int m)
    {
        CheckIndex(n); CheckIndex(m);
        if (adjacent[n][m] == false) Error("Error Pos!");
        else adjacent[n][m] = false;
        OutDegree[n]--; InDegree[m]--;
    }
    void PrintGraph()
    {
        for(int i = 0; i < GRAPH_SIZE; i++)
        {
            if(label[i] == NONE) continue;
            else
            {
                cout << label[i] << " connected with ";
                for(int j = 0; j < GRAPH_SIZE; j++)
                {
                    if(adjacent[i][j] == false) continue;
                    else cout << label[j] << " ";
                }
                cout << endl;
            }
        }
    }
    void DepthFirstSearch(int n)
    {
        ResetVisited();
        DepthFirstSearchRecursion(n);
    }
    void TopologicalSort(int n)
    {
        VisitVertex(n);
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if(adjacent[n][i] && --InDegree[i] == 0) TopologicalSort(i);
        }
    }
};

int main()
{
    
}