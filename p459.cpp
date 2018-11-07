//p459.c

#include<iostream>
#include<list>
using namespace std;


int stack[50];
int topSt = -1;

// Graph class represents a undirected graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    int count = 0;
    void DFSVisit(int s, bool visited[]);  // A recursive function used by DFS
    int arrTra[20] = {0};
    int top = -1;
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    void DFSInit(int s); // DFS traversal of the vertices reachable from s
    void print();
    
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w’s list
}

void Graph::DFSVisit(int s, bool visited[])
{
    // Mark the current node as visited and print it
    visited[s] = true;
    arrTra[++top] = s;
    
    // Recurse for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!visited[*i]){
            count++;
            DFSVisit(*i, visited);
        }
    }
}

// DFS traversal of the vertices reachable from v
void Graph::DFSInit(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // DFSVisit( s, visited);
    // //cout << "count " << count << endl;
    // stack[++topSt] = count;
    for (int i = 1 ; i < V;i++){
        if (visited[i] == false){
            count = 0;
            DFSVisit( i, visited);
            stack[++topSt] = count;
        }
    }
}


void Graph::print(){
    for (int i = 0; i < V;i++){
        cout << "NOde " << i << endl;
        for (auto const& x : adj[i]){
            cout << "-> " << x;
        }
        cout << endl;
    }
}


int main()
{
     int n,m;

    int numCase;
    char lenght;
    int max = 0;
    char sp;
    cin >> numCase;
    cout << endl;
    cin >> lenght;
    Graph g((int)(lenght - 'A')+1); 
    string pair;
    while (getline(cin,pair) && !pair.empty()){
        //if (pair.empty()) break;
        g.addEdge((int)(pair[0] - 'A' + 1),(int)((char)pair[1] - 'A') + 1);
    }
    g.DFSInit(1);
    //cout << "top " << topSt << endl;
    for (int i = 0 ; i <= topSt;i++){
        cout << "Count : " << stack[i] << endl;
    }
    for (int i = 0 ; i <= topSt;i++){
        if (max < stack[i]){
            max = stack[i];
        }
    }
    cout << max;
    return 0;
}


