#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned int llus;
int NIL = -1;

struct Edge {
    int src;
    int dst;
    int weight;
};

bool compareEdgeByWeight(Edge &e1, Edge &e2)
{
    return e1.weight < e2.weight;
}

bool compareBySRC(Edge &e1, Edge &e2)
{
    return e1.src < e2.src;
}

struct Vertex {
    int key;
    int distance;
    int preceder;
    int discoveryTime;
    bool isVisited;
};        

Vertex createVertex(int key) 
{
    Vertex vertex;
    vertex.key = key;
    vertex.distance = INT32_MAX;
    vertex.discoveryTime = NIL;
    vertex.preceder = NIL;
    vertex.isVisited = false;
    return vertex;
}

Edge CreateEdge(int src, int dst, int weight) 
{
    Edge edge;
    edge.src = src;
    edge.dst = dst;
    edge.weight = weight;
    return edge;
}

class DisJointSet
{
    private : 
    int *arr;
    int size;

    public:
        DisJointSet(int size);
        int find(int a);
        bool doUnion(int a, int b);
        void printSet();
};

DisJointSet::DisJointSet(int size)
{
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }
}

/*
returns parent of a:
*/
int DisJointSet::find(int a) 
{
    int parent = arr[a];
    if (parent < 0) {
        return a;
    }
    else {
        int temp;
        while (parent > 0) {
            temp = parent;
            parent = arr[parent];
        }
        arr[a] = temp;
        return temp;
    }
}

/*
checks presence of cycle:
updates disJointSet Arr:
*/
bool DisJointSet::doUnion(int a, int b) 
{
    int parentA = find(a);
    int parentB = find(b);
    if (parentA != parentB) {
        if (arr[parentA] <= arr[parentB]) {
            arr[parentA] += arr[parentB];
            arr[parentB] = parentA;
        }
        else {
            arr[parentB] += arr[parentA];
            arr[parentA] = parentB;            
        }
        return false;
    }
    else {
        return true;
    }
}

void DisJointSet::printSet() 
{
    for (int i = 1; i < size; i++) {
        cout << "i: " << i << " " << "arr: " << arr[i] << endl;
    }
}

class Graph {
    private:
        int noOfVertices;
        vector <int> *adjancyList;
        vector<Edge> edge;
        queue<int> q2;
        stack<int> s1;    
        vector<Vertex> createVertexList();
        vector<Edge> createEdgeList();
        int getWeight(int src, int dst);

    public:    
        Graph();
        Graph(int noOfVertices);
        bool hasEdge(int src, int dsr);
        void addEdge(int src, int dst, int weight);
        void printAdjancyList();
        void printWeight();
        vector<Vertex> BFS(int src);
        vector<Vertex> DFS(int src);
        bool isCyclicDirected();
        bool isCyclicUndirected();
        bool isCycleUndirectedUsingDisJointSet();
        bool cycleDirectedUtil(int src, stack<int> &s1, int stackBoolean[]);
        bool cycleUndirectedUtil(int src, int parent, int queueBoolean[]);
        void dfsUtil(int src, vector<Vertex> &dfsVector, vector<Vertex> &vertex);
        void relax(int u, int v, int weight, vector<Vertex> &vertex);
        vector<Vertex> bellmanFordMinDis(int src);
        Graph kruskalsMethod();
        
};

int main() 
{
    int noOfVertices, edges;
    cin >> noOfVertices >> edges;
    Graph gr(noOfVertices+1);
    DisJointSet dis(noOfVertices + 1);
    for (int i = 0; i < edges; i++) {
        int u, v, weight = 0;
        cin >> u >> v >> weight;
        gr.addEdge(u, v, weight);
    }
    gr.printAdjancyList();
    cout << "adjancyList is printed\n";

    cout << "BFS:-> ";
    vector<Vertex> bfsVector = gr.BFS(1); cout << endl;

    cout << "DFS:-> ";
    vector<Vertex> dfsVector = gr.DFS(1); cout << endl;

    int temp = gr.isCyclicDirected();
    cout << "is cyclic directed: " << temp << endl;

    int temp2 = gr.isCyclicUndirected();
    cout << "is cyclic undirected: " << temp2 << endl;

    int temp3 = gr.isCycleUndirectedUsingDisJointSet();
    cout << "is cyclic undirected DisJointSet: " << temp3 << endl;
    
    cout << "Bell-mannFord: ";
    vector<Vertex> updatedMinDis = gr.bellmanFordMinDis(1);



    Graph mst = gr.kruskalsMethod();
    mst.printAdjancyList();
    
    cout << "BFS:-> ";
    vector<Vertex> bfsVector2 = mst.BFS(1); cout << endl;

    cout << "DFS:-> ";
    vector<Vertex> dfsVector2 = mst.DFS(1); cout << endl;

    int temp22 = mst.isCyclicDirected();
    cout << "is cyclic directed: " << temp22 << endl;

    int temp23 = mst.isCyclicUndirected();
    cout << "is cyclic undirected: " << temp23 << endl;

    int temp34 = mst.isCycleUndirectedUsingDisJointSet();
    cout << "is cyclic undirected DisJointSet: " << temp34 << endl;
    
    cout << "Bell-mannFord: ";
    vector<Vertex> updatedMinDis2 = mst.bellmanFordMinDis(1);
 
}

Graph::Graph()
{
    this->noOfVertices = 0;
    this->adjancyList = NULL;
}

Graph::Graph(int noOfVertices)
{
    this->noOfVertices = noOfVertices;
    this->adjancyList= new vector<int>[noOfVertices]; 
}

bool Graph::hasEdge(int src, int dst) 
{
    auto it = find(adjancyList[src].begin(), adjancyList[src].end(), dst);
    if (it == adjancyList[src].end()) {
        return false;
    }
    return true;
}

void Graph::addEdge(int src, int dst, int weight)
{
    if(!hasEdge(src, dst)) {
        adjancyList[src].push_back(dst);
       // adjancyList[dst].push_back(src); 
        edge.push_back(CreateEdge(src, dst, weight));
    }
}

void Graph::printAdjancyList() 
{
    for (int i = 1; i < noOfVertices; i++) {
        cout << i << " --> ";
        for(int j : adjancyList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::printWeight()
{
        for (Edge e : edge) {
            cout << e.src << "  " << e.dst << "  " << e.weight << endl;
        }
}

vector<Vertex> Graph::createVertexList() 
{
    vector<Vertex> vertexList;
    for (int i = 0; i < noOfVertices; i++) {
        Vertex v;
        v = createVertex(i);
        vertexList.push_back(v);
    }
    return vertexList;
}

vector<Edge> Graph::createEdgeList() 
{
    vector<Edge> tempEdge;
    for(Edge e : edge) {
        tempEdge.push_back(CreateEdge(e.src, e.dst, e.weight));
    }
    return tempEdge;
}

/*
returns BFS vector:
*/
vector<Vertex> Graph::BFS(int src)
{
    vector<Vertex> vertices = createVertexList();
    vector<Vertex> bfs;
    queue<int> vertexQueue;
    vertexQueue.push(src);
    vertices[src].isVisited = true;
    vertices[src].distance = 0;
    while (!vertexQueue.empty()) {
        int u = vertexQueue.front();
        vertexQueue.pop();
        cout << u << " " ;
        for (int v : adjancyList[u]) {
            if(!vertices[v].isVisited) {
                vertices[v].isVisited = true;
                vertices[v].distance = vertices[u].distance + 1;
                vertices[v].preceder = u;
                vertexQueue.push(v);
            }
        }
        bfs.push_back(vertices[u]);
    }
    return bfs;
}

vector<Vertex> Graph::DFS(int src) 
{
    vector<Vertex> vertex = createVertexList();
    vector<Vertex> dfsVector;
    stack<int> s1;
    vertex[src].distance = 0;
    dfsUtil(src, dfsVector, vertex);
    return dfsVector;
}

void Graph::dfsUtil(int src, vector<Vertex> &dfsVector, vector<Vertex> &vertex) {
    vertex[src].isVisited = true;
    dfsVector.push_back(vertex[src]);
    cout << src << " ";
    for (int v : adjancyList[src]) {
        if (!vertex[v].isVisited){
            vertex[v].distance = vertex[src].distance + 1;
            vertex[v].preceder = src;
            dfsUtil(v, dfsVector, vertex);
        }
    }
}

bool Graph::isCyclicDirected()
{
    int temp = 0;
    for (int i = 1; i < noOfVertices; i++) {
        stack<int> s1;
        int stackBoolean[noOfVertices + 1] = {0};
        temp = cycleDirectedUtil(i, s1, stackBoolean);
        if (temp == 1) {
            break;
        }
    }
    return temp;
}

bool Graph::cycleDirectedUtil(int src, stack<int> &s1, int stackBoolean[]) {
    s1.push(src);
    stackBoolean[src]++;
    if (stackBoolean[src] > 1) {
        return true;
    }
    else {
        int result = 0;
        for (int v : adjancyList[src]) {
            int temp = 0;
            temp = cycleDirectedUtil(v, s1, stackBoolean);
            if (temp == 1) {
                result = 1;
                break;
            }
        }
        stackBoolean[s1.top()]--;
        s1.pop();
        if ( s1.empty() ){
            return false;
        }
        else {
            return result;
        } 
    } 
}

bool Graph::isCyclicUndirected()
{
    int temp = 0;
    for (int i = 1; i < noOfVertices; i++) {
        int queueBoolean[noOfVertices + 1] = {0};
        temp = cycleUndirectedUtil(i, -1, queueBoolean);
        if (temp == 1) {
            break;
        }
    }
    return temp;
}

bool Graph::cycleUndirectedUtil(int src, int parent, int queueBoolean[])
{
    queueBoolean[src]++;
    if (queueBoolean[src] > 1) {
        return true;
    }
    int result = 0;
    for (int v: adjancyList[src]) {
        int temp = 0; 
        if (v != parent) {
            temp = cycleUndirectedUtil(v, src, queueBoolean);
        }
        if (temp == 1) {
            result = 1;
            return result;
        }        
    }
    return false;
}

bool Graph::isCycleUndirectedUsingDisJointSet() 
{
    DisJointSet disSet(noOfVertices + 1);
    int temp = 0;
    for (Edge e : edge) {
        temp = disSet.doUnion(e.src, e.dst);
        if (temp == 1) {
            break;
        }
    }
    return temp;
}

/*
returns updated vertex vector:
*/
vector<Vertex> Graph::bellmanFordMinDis(int src)
{
    vector<Edge> tempEdge = createEdgeList();
    vector<Vertex> vertex = createVertexList();
    int minDisArr[noOfVertices] = {0};
    vertex[src].distance = 0;
    
    for (int i = 1; i < noOfVertices; i++) {
        for (Edge e : tempEdge) {
            relax(e.src, e.dst, e.weight, vertex);                          // updates min dis in vertex vector
        }
    }
    for (llus i = 1; i < vertex.size(); i++) {
        minDisArr[i] = vertex[i].distance;
    }
    for (Edge e : tempEdge) {                      // to check any -ve edge cycle
        relax(e.src, e.dst, e.weight, vertex);
    }
    llus check;
    for (check = 1; check < vertex.size(); check++) {
        if(minDisArr[check] != vertex[check].distance) {
            break;
        }
    }
    if (check == vertex.size()) {
        cout << "NO -ve Edge Cycle\n";
    }
    else {
        cout << "-ve Edge Cycle\n";
    }
    return vertex;
}

/*
updates min distance to every vertex:
*/
void Graph::relax(int u, int v, int weight, vector<Vertex> &vertex)
{
    if (vertex[v].distance > (weight + vertex[u].distance)) {
        vertex[v].distance = weight + vertex[u].distance;
        vertex[v].preceder = u;
    }
}

int Graph::getWeight(int src, int dst)
{
    for(Edge e : edge) {
        if(e.src == src && e.dst == dst) {
            return e.weight;
        }
    }
    cout << "edges not found\n";
    return EXIT_FAILURE;
}

Graph Graph::kruskalsMethod()
{
    vector<Edge> tempEdge = createEdgeList();
    Graph tempGraph(noOfVertices);
    DisJointSet disSet(noOfVertices + 1);
    sort(tempEdge.begin(), tempEdge.end(), compareEdgeByWeight);
    for (Edge e : tempEdge) {
        if (disSet.find(e.src) != disSet.find(e.dst)) {
            tempGraph.addEdge(e.src, e.dst, e.weight);
            disSet.doUnion(e.src, e.dst);
        }
    }
    return tempGraph;
}
/*
8
10
1 3
1 6
1 8
2 5
3 6
4 7
6 4
2 4
5 8
6 8 

9
13
1 3 1
3 2 1
2 1 2
3 6 3
3 5 4
2 4 3
4 5 4
4 8 5
5 8 2
6 7 6
7 8 1
7 9 8
8 9 4*/