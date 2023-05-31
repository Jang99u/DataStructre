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

class CheckStronglyConnected
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
    CheckStronglyConnected()
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
    void CheckConnected(int n)
    {
        DepthFirstSearch(n);
        bool IsConnected = true;
        for(int i = 0; i < GRAPH_SIZE; i++)
        {
            if(label[i] != NONE && visited[i] == false) IsConnected = false;
        }
        if(IsConnected == true) cout << label[n] << " is connected" << endl;
        else cout << label[n] << " is disconnected" << endl;
    }
};

int main()
{
    CheckStronglyConnected G1;
    
    G1.InsertVertex(0, 'S'); G1.InsertVertex(1, 'A'); G1.InsertVertex(2, 'B');
    G1.InsertVertex(3, 'C'); G1.InsertVertex(4, 'D'); G1.InsertVertex(5, 'E');

    G1.InsertEdge(0, 1); G1.InsertEdge(0, 2); G1.InsertEdge(0, 3);
    G1.InsertEdge(1, 2); G1.InsertEdge(2, 3); G1.InsertEdge(3, 2);
    G1.InsertEdge(0, 4); G1.InsertEdge(3, 5); G1.InsertEdge(4, 2);
    G1.InsertEdge(1, 5);

    G1.CheckConnected(0);
    G1.CheckConnected(4);
}