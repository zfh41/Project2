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
  string name;
  vector<Node*> neighbors;
  bool visited;
  Node(string name) {
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
    typedef map<string, Node *> vmap;
    vmap work;
    void addNode(const string nodeVal);
    void addUndirectedEdge(struct Node *first, struct Node *second);
    void removeUndirectedEdge(struct Node *first, struct Node *second);
    vector<Node> getAllNodes();
    
    
    Graph* createRandomUnweightedGraphIter(int n)
    {
        // create n random nodes
        
        Graph *randomGraph;
        
        static const char pool[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
        
        int poolsize = sizeof(pool)-1;
        
        string random_string;
        
        int iRand;
        
        
        
        for (int i=0;i<n;i++)
        {
            //create random value
            
            iRand = rand() % 10 + 1;
            
             for (int i=0;i<iRand;i++)
             {
                 random_string += pool[rand() % poolsize];
                 
             }
            //pass that random value into the graph as a node
            randomGraph->addNode(random_string);
        }



        // randomly assign unweighted bidirectional edges to the nodes
        vector<Node> bunchNodes=randomGraph->getAllNodes();
        
        
        // generate two random numbers in range of n
        for(int i=0;i<n;i++)
        {
            int rand1 = rand() % n + 1;
            int rand2 = rand() % n + 1;

            Node node1 = bunchNodes[rand1];
            Node node2 = bunchNodes[rand2];

            randomGraph->addUndirectedEdge(&node1, &node2);

        }

        return randomGraph;
    }
    
    Graph* createLinkedList(int n)
    {
        Graph *linkedGraph;
        
        vector<Node> bunchNodes;

        // go through one and its increment and add an undirected edge
        for (int i=0;i<n;i++)
        {
            linkedGraph->addNode(to_string(i));
            linkedGraph->addNode(to_string(i+1));
            
            bunchNodes=linkedGraph->getAllNodes();
            
            linkedGraph->addUndirectedEdge(&bunchNodes[i], &bunchNodes[i+1]);
        }
    }
    
    
    vector<Node> BFTRecLinkedList(const Graph graph)
    {
        
        // generate linked list from above ^^^^^^
        
        Graph* BFTgraph;
        
        BFTgraph=createLinkedList(10000);
        
        
        // perform a BFT on the linked list graph
        
        
        
        
        
        
    }
    
    
    vector<Node> BFTIterLinkedList(const Graph graph)
    {
        
        // generate linked list from above ^^^^^
        
        // createLinkedList(10000)
        
        // perform a BFT on the linked list graph
        
        
        
        
    }
    
};

class GraphSearch
{

    vector<Node> DFSRec(struct Node *start, struct Node *end)
    {

        // does a DFS search and return between the start and end node
        
        //if v is not visited:
        //                mark v as visited
        //                "process" v
        //                for each vertex vi that has an edge from v:
        //                    if vi is not visited:
        //                        DFSRec()
        
        
        
        // get graph with start node to end node ... not sure how to do that lol
        vector<Node*> vertices = start->neighbors;
        
        for (int i; i<sizeof(vertices) ; i++)
        {
            vertices[i]->visited = true;
            //not sure what process v means.... maybe add to array?
            vector<Node*> viNodes = vertices[i]->neighbors;
            for (int i=0;i<sizeof(viNodes);i++)
            {
                if (viNodes[i]->visited==false)
                    DFSRec(viNodes[i], viNodes[sizeof(viNodes)-1]);
            }
        }
    }


    vector<Node> DFSIter(struct Node *start, struct Node *end)
    {

        // does an iterative DFS search and returns in the array
        
        // get graph with start node to end node ... not sure how to do that lol
        vector<Node*> vertices = start->neighbors;
        
        stack<Node*> S;
        for (int i;i<sizeof(vertices);i++)
        {
            if (vertices[i]->visited==false)
            {
                vertices[i]->visited=true;
                S.push(vertices[i]);
                while (!S.empty())
                {
//                    Node cur = S.pop(); // giving me weird rvalue error // check w/ Subhrasree
                    //again not sure what process means... maybe add to array?
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

    }


    vector<Node> BFTRec(Graph* graph) // ask Subhrasree if this has to be const
    {


        // does a recursive BFT search
        
        Queue* Q = new Queue();
        Q->capacity=100;
        Q->front = Q->size = 0;
        Q->rear = Q->capacity - 1;
        Q->array = *new Node*[(Q->capacity * sizeof(Node*))];
        
        vector<Node> G = graph->getAllNodes();
        for (int i=0;i<sizeof(G);i++)
        {
            if (G[i].visited==false)
            {
                G[i].visited=true;
                Q->rear = (Q->rear + 1) % Q->capacity;
                Q->array[Q->rear] = G[i];
                Q->size = Q->size + 1;
                while (Q->size!=0)
                {
                    Node
                }
            }
            
        }
        
        
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
        
        


    }
//
//    ArrayList<Node> BFTIter(final Graph graph)
//    {
//
//
//
//        // does an iterative BFT search
//
//
//
//    }



};



vector<int> adj[50];

void Graph::addNode(const string nodeVal)
{
  vmap::iterator itr = work.find(nodeVal);
  if (itr == work.end())
  {
    Node* n;
    n = new Node(nodeVal);
    work[nodeVal]=n;
    return;
  }
  cout << "\nNode already exists!";
}


void Graph::addUndirectedEdge(struct Node *first, struct Node *second)
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


vector<Node> Graph::getAllNodes()
{
      vector<Node> Nodelist;
      Node* n;

      for (int i=0; i<work.size();i++)
      {
        string l = to_string(i);
        n=work[l];
        Nodelist.push_back(*n);

      }
      return Nodelist;

}


int main()
{
    return 0;

}

