#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <stack>

using namespace std;

struct Node {
  int name;
  vector<Node*> neighbors;
  bool visited;
  Node(int name) {
    this->name=name;
  }
};

class Queue
{
    public:
    int front, rear, size;
    unsigned capacity;
    Node* array;
};


class Graph
{
  public:
    vector<Node> BFTRecLinkedList(const Graph graph);
    vector<Node> BFTIterLinkedList(const Graph graph);
    void addNode(const int nodeVal);
    void addDirectedEdge(struct Node *first, struct Node *second);
    void removeUndirectedEdge(struct Node *first, struct Node *second);
    vector<Node*> getAllNodes();
    void printGraph(vector<Node*> graphList);
    
    
    Graph* createRandomUnweightedGraphIter(int n)
    {
    
        Graph *randGraph;
        
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, (n*n*n));
        int r, i;
        for (i = 0; i < n; i++)
            randGraph->addNode(dist(mt));
        
        vector<Node*> nodes = randGraph->getAllNodes();
        
        for (i = 0; i < nodes.size(); i++){
            for (int j = 0; j < nodes.size(); j++){
                if (nodes[i]->name == nodes[j]->name)
                    continue;
                else{
                    r = rand() % 15 + 1;
                    randGraph->addDirectedEdge(nodes[i], nodes[j]);
                }
            }
        }
    }
    
    Graph* createLinkedList(int n)
    {
        Graph *linkedGraph;
        
        vector<Node*> bunchNodes;

        // go through one and its increment and add an undirected edge
        for (int i=0;i<n;i++)
        {
            linkedGraph->addNode(i);
            linkedGraph->addNode(i+1);
            
            bunchNodes=linkedGraph->getAllNodes();
            
            linkedGraph->addDirectedEdge(bunchNodes[i], bunchNodes[i+1]);
        }
        
        return linkedGraph;
    }
    
};

class GraphSearch: public Graph
{
    vector<Node> DFSresultRec;
    vector<Node> BFSresultRec;
    
    vector<Node> DFSRec(struct Node *start, struct Node *end)
    {

        // does a DFS search and return between the start and end node
        
        //if v is not visited:
        //                mark v as visited
        //                "process" v
        //                for each vertex vi that has an edge from v:
        //                    if vi is not visited:
        //                        DFSRec()
        
        
        vector<Node*> vertices = start->neighbors;
        
        
        for (int i; i<sizeof(vertices) ; i++)
        {
            if (vertices[i]!=end)
            {
            vertices[i]->visited = true;
            DFSresultRec.push_back(*vertices[i]);
            vector<Node*> viNodes = vertices[i]->neighbors;
            for (int i=0;i<sizeof(viNodes);i++)
            {
                if (viNodes[i]->visited==false)
                    DFSRec(viNodes[i], viNodes[sizeof(viNodes)-1]);
            }
            }
        }
        return DFSresultRec;
    }

    vector<Node> DFSIter(struct Node *start, struct Node *end)
    {
        // does an iterative DFS search and returns in the array
        
        
        
        /*Algorithm*/
        
//        def dfs(G):
//        let S be a stack
//        for each vertex v in G:
//            if v is not visited:
//                mark v as visited and add it to S
//                while S is not empty:
//                    cur = S.pop()
//                    “process cur”
//                    for each vertex vi that has an edge from cur:
//                        if vi is not visited:
//                            mark vi as visited and add it to S
        
        
        
        vector<Node*> vertices = start->neighbors;
        vector<Node> result;
        stack<Node*> S;
        
        for (int i;i<sizeof(vertices);i++)
        {
            if (vertices[i]->visited==false)
            {
                vertices[i]->visited=true;
                S.push(vertices[i]);
                while (!S.empty() && end!=vertices[i])
                {
                    Node cur = *(S.top());
                    //again not sure what process means... maybe add to array?
                    result.push_back(cur);
                    vector<Node*> viNodes = vertices[i]->neighbors;
                    for (int i=0;i<sizeof(viNodes);i++)
                    {
                        if (viNodes[i]->visited==false)
                        {
                            viNodes[i]->visited=true;
                            S.push(viNodes[i]);
                        }
                    }
                }
            }
        }
        
        return result;
    }

    public: vector<Node*> BFTRec(Graph* graph)
    {
        // does a recursive BFT search
        
//                    if v is not visited:
//                        mark v as visited and add it to Q
//                        while Q is not empty:
//                            cur = Q.dequeue()
//                            “process cur”
//                            for each vertex vi that has an edge from cur:
//                                if vi is not visited:
//                                    mark vi as visited and add it to Q
        vector<Node*> v, pass;
        
        vector<Node*> nodes = graph->getAllNodes();
        
        for (int i=0;i<nodes.size();i++)
        {
            if(!nodes[i]->visited){
                nodes[i]->visited = true;
                v.push_back(nodes[i]);
                BFTHelper(v, pass);
            }
                
                
        }
        
        return pass;
            
    }
    
    public: void BFTHelper(vector<Node*> &vec, vector<Node*> &p)
    {
        
        Node *n;
        
        if (vec.empty())
            return;
        
        n = vec.front();
        vec.erase(vec.begin());
        p.push_back(n);
        for (int i = 0; i < n->neighbors.size(); i++){
            if (!n->neighbors[i]->visited){
                n->neighbors[i]->visited = true;
                vec.push_back(n->neighbors[i]);
            }
        }
        BFTHelper(vec, p);
        
        
    }
        
        
        
    
    public: vector<Node> BFTIter(Graph* graph)
    {
        
        // does an iterative BFT search
        
        //        let Q be a queue
        //        for each vertex v in G:
        //            if v is not visited:
        //                mark v as visited and add it to Q
        //                while Q is not empty:
        //                    cur = Q.dequeue()
        //                    “process cur”
        //                    for each vertex vi that has an edge from cur:
        //                        if vi is not visited:
        //                            mark vi as visited and add it to Q

        vector<Node> result;
        
         Queue* Q = new Queue();
         Q->capacity=100;
            Q->front = Q->size = 0;
            Q->rear = Q->capacity - 1;
            Q->array = *new Node*[(Q->capacity * sizeof(Node*))];

            vector<Node*> G = graph->getAllNodes();
            for (int i=0;i<sizeof(G);i++)
            {
                if (G[i]->visited==false)
                {
                    G[i]->visited=true;
                    Q->rear = (Q->rear + 1) % Q->capacity;
                    Q->array[Q->rear] = *G[i];
                    Q->size = Q->size + 1;
                    while (Q->size!=0)
                    {
                        Node cur = Q->array[Q->front];
                        Q->front = (Q->front + 1) % Q->capacity;
                        Q->size = Q->size - 1;
                        result.push_back(cur);
                        vector<Node*> viNodes = cur.neighbors;
                         for (int i=0;i<sizeof(viNodes);i++)
                         {
                             if(viNodes[i]->visited==false)
                             {
                                 viNodes[i]->visited=true;
                                 Q->rear = (Q->rear + 1) % Q->capacity;
                                 Q->array[Q->rear] = *viNodes[i];
                                 Q->size = Q->size + 1;
                             }
                         }
                    }
                }
            }
        return result;

    }



};

vector<int> adj[50];
vector<Node *> graphList;



void Graph::addNode(const int nodeVal)
{
    Node* n;
    n = new Node(nodeVal);
    n->visited=false;
    graphList.push_back(n);
    return;
}


void Graph::addDirectedEdge(Node *first, Node *second)
{
        
    first->neighbors.push_back(second);
    second->neighbors.push_back(first);
    
    
}



void Graph::removeUndirectedEdge(struct Node *first, struct Node *second)
{
    for (int i=0;i<first->neighbors.size();i++)
    {
        if ( first->neighbors[i]->name == second->name)
        {
            first->neighbors.erase(first->neighbors.begin() + i);
        }
        break;
        
        if ( second->neighbors[i]->name == first->name)
        {
            second->neighbors.erase(second->neighbors.begin() + i);
            
        }
    }
}


vector<Node*> Graph::getAllNodes()
{
      return graphList;
}

void Graph::printGraph(vector<Node*> graph)
{
    for (int i=0;i<graphList.size();i++)
    {
        cout << graphList[i]->name << endl;
    }
    
    
}

vector<Node> Graph::BFTRecLinkedList(const Graph graph)
    {
        
        // generate linked list from above ^^^^^^
        
        GraphSearch rec;
        
        Graph* BFTgraph;
        
        BFTgraph=createLinkedList(10000);
        
        rec.BFTRec(BFTgraph);
    }
    
    
vector<Node> Graph::BFTIterLinkedList(const Graph graph)
{
        
        // generate linked list from above ^^^^^
    
        GraphSearch iter;
    
        Graph* BFTgraph;
        
        BFTgraph = createLinkedList(10000);
    
        iter.BFTIter(BFTgraph);
        
        // perform a BFT on the linked list graph
        
}


int main()
{
    
    
    return 0;

}

