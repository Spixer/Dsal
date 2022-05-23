#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
public:
    int adjacencyMatrix[10][10],
        visited[10],
        size,
        vertices,
        edges;

    Graph()
    {
        size = 10;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }

        for (int i = 0; i < size; i++)
        {
            visited[i] = 0;
        }
    }

    void displayMatrix()
    {
        cout << "The Adjacency Matrix:\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void TakeGraph()
    {
        cout << "Enter Number of vertices\n";
        int vertices;
        cin >> vertices;
        this->vertices = vertices;

        cout << "Enter Number of Edges\n";
        int edges;
        cin >> edges;
        this->edges = edges;

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter the nodes connected by " << (i + 1) << " th edge\n";
            int first, second;
            cin >> first >> second;

            adjacencyMatrix[first][second] = 1;
            adjacencyMatrix[second][first] = 1;
        }
    }

    void DFS(int vertex)
    {
        visited[vertex] = 1;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                if (adjacencyMatrix[i][vertex])
                    DFS(i);
            }
        }
    }

    void stackDFS(int vertex)
    {
        stack<int> nodes;
        nodes.push(vertex);
        cout << vertex << " ";

        visited[vertex] = 1;
        while (!nodes.empty())
        {
            int top = nodes.top();
            nodes.pop();
            if (!visited[top])
            {
                cout << top << " ";
                visited[top] = 1;
            }

            for (int i = vertices - 1; i >= 0; i--)
            {
                if (!visited[i] && adjacencyMatrix[i][top])
                {
                    nodes.push(i);
                }
            }
        }
        cout << endl;
    }

    void BFS(int vertex)
    {
        queue<int> remaining;
        remaining.push(vertex);
        visited[vertex] = 1;

        while (!remaining.empty())
        {
            int front = remaining.front();
            remaining.pop();

            cout << front << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && adjacencyMatrix[i][front])
                {
                    remaining.push(i);
                    visited[i] = 1;
                }
            }
        }
        clearVisited();
    }

    void clearVisited()
    {
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
    }
};

int main()
{
    cout << "\nBFS and DFS traversals: \n";

    Graph g;
    g.TakeGraph();
    g.displayMatrix();
    char ch;
    int root;
    do
    {
        cout << "Enter the starting vertex from where you want to see the DFS using stack.\n";
        cin >> root;
        g.stackDFS(root);
        cout << "\n";
        g.clearVisited();
        cout << "Enter the starting vertex from where you want to see the DFS using recursion.\n";
        cin >> root;
        g.DFS(root);
        cout << "\n";
        g.clearVisited();
        cout << "Enter the starting vertex from where you want to see the BFS.\n";
        cin >> root;
        g.BFS(root);
        cout << "Do you want to continue??\n";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "THANK YOU";
}

// 5 5 0 1 0 2 0 4 2 3 3 4 4 4