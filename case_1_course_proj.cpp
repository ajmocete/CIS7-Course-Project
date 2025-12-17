#include <iostream>
#include <string>

using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
    int val, cost;
    Node* next;
};

// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

struct Cities {
    int val;
    std::string city;
    std::string cym;
};

class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;

        // point new node to current head
        newNode->next = head;

        return newNode;
    }

    int N;  // number of nodes in the graph

public:

    // An array of pointers to Node to represent
    // adjacency list
     Node **head;

    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);

            // point head pointer to new node
            head[src] = newNode;

            // Uncomment below lines for undirected graph

            
            newNode = getAdjListNode(src, weight, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
            
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }
};

// print all neighboring vertices of given vertex
void printVectorList(Node* ptr, int i)
{
    //array of cities
    std::string cities[4] = {"Riverside", "Moreno Valley", "Perris", "Hemet" };
    while (ptr != nullptr)
    {
        cout << "(" << cities[i] << ", " << cities[ptr->val]
            << ", " << ptr->cost << ") ";

        ptr = ptr->next;
    }

    cout << endl;
}

// Graph Implementation in C++ without using STL
int main()
{
    //array of city information
    Cities cities[] =
    {
        {0, "Riverside", "A"},
        {1, "Moreno Valley", "B"},
        {2, "Perris", "C"},
        {3, "Hemet", "D"}
    };
    
    // array of graph edges as per diagram.
    Edge edges[] =
    {
        // (x, y, w) -> edge from x to y having weight w
        // 0: Riverside, 1: Moreno Valley, 2:Perris, 3:Hemet
        { 0, 1, 16}, {0, 2, 24}, {0, 3, 33},
        { 1, 2, 18}, {1, 3, 26}, {2, 3, 30}
    };

    // Number of vertices in the graph
    int N = 4;

    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    // construct graph
    Graph graph(edges, n, N);

    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of vertex i
        cout << "Edges of Vertex " << cities[i].cym << ": " << cities[i].city << endl; 
        printVectorList(graph.head[i], i);

        cout << "Weighted Matrix:" << endl;
        printWeightingMatrix(graph.head[i],i);
    }
    
    return 0;
}