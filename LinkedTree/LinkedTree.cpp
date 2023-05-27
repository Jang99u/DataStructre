#include <iostream>
#include <cstdlib>
#define DELETE(n) { Data d = n->data; delete n; n = NULL; return d; }
using namespace std;
typedef int Data;

void Error(string s)
{
    cout << s;
    exit(-1);
}

class Node
{
public:
    Data data;
    Node* left;
    Node* right;
    
    Node(Data d = 0, Node* l = NULL, Node* r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }

    bool IsLeaf()
    {
        return left == NULL && right == NULL;
    }
};

class BinaryTree
{
    Node* root;

    int FindPath(int pos)
    {
        int path = 1;
        for (int i = pos; i != 1; i /= 2)
        {
            path = path * 2 + i % 2;
        }

        return path;
    }

    Node* InsertPos(Node* n, int path, Data d)
    {
        if (path == 1 && n == NULL) return new Node(d);
        if (path == 0 || n == NULL) Error("Error Pos!");
        if (path % 2 == 0) n->left = InsertPos(n->left, path/2, d);
        else n->right = InsertPos(n->right, path/2, d);

        return n;
    }

    Data DeletePos(Node* n, int path)
    {
        if (n == NULL) Error("Error Pos!");
        if (path == 1 && n == root) DELETE(root);
        if (path == 2) DELETE(n->left);
        if (path == 3) DELETE(n->right);
        if (path % 2 == 0) return DeletePos(n->left, path/2);
        else return DeletePos(n->right, path/2);
    }

    Data PeekPos(Node* n, int path)
    {
        if (n == NULL) Error("Error Pos!");
        if (path == 1) return n->data;
        if (path % 2 == 0) return PeekPos(n->left, path/2);
        else return PeekPos(n->right, path/2);
    }

    int NumNode(Node* n)
    {
        if (n == NULL) return 0;
        return 1 + NumNode(n->left) + NumNode(n->right);
    }
    
    int NumLeaf(Node* n)
    {
        if (n == NULL) return 0;
        if (n->IsLeaf()) return 1;
        return NumLeaf(n->left) + NumLeaf(n->right);
    }
    
    int Height(Node* n)
    {
        if (n == NULL) return 0;
        return 1 + max(Height(n->left), Height(n->right));
    }

public:

    BinaryTree()
    {
        root = NULL;
    }

    void InsertPos(int pos, Data d)
    {
        root = InsertPos(root, FindPath(pos), d);
    }

    Data DeletePos(int pos)
    {
        return DeletePos(root, FindPath(pos));
    }

    Data PeekPos(int pos)
    {
        return PeekPos(root, FindPath(pos));
    }

    int NumNode() { return NumNode(root); }
    int NumLeaf() { return NumLeaf(root); }
    int Height() { return Height(root); }
    
    void PrintInorder(Node* n)
    {
        if(n == NULL) return;
        PrintInorder(n->left);
        cout << n->data;
        PrintInorder(n->right);
    }
};

int main()
{

}