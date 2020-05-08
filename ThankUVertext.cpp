#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <stack>
#include <queue>

using namespace std;

struct Node {
  int name;
  vector<Node*> neighbors;
  bool visited;
  int degree;
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



class DirectedGraph
{
  public:
    vector<Node *> graphList;
    void addNode(const int nodeVal);
    void addDirectedEdge(struct Node *first, struct Node *second);
    void removeDirectedEdge(struct Node *first, struct Node *second);
    vector<Node*> getAllNodes();
    void printGraph(vector<Node*> graph);
    
    DirectedGraph* createRandomDAGIter(const int n)
    {
        // creates n random nodes
        
        DirectedGraph *randomGraph;
        
        random_device rd;
        
        int iRand;
        
        iRand = rand() % 10 + 1;
        
        for (int i = 0; i < n; i++){
            randomGraph->addNode(iRand);
        }
        
        vector<Node*> bunchNodes=randomGraph->getAllNodes();
        int a,b;
        
        for(int i=0;i<n;i++)
        {
            
            a = iRand % randomGraph->getAllNodes().size();
            b = iRand % randomGraph->getAllNodes().size();
            randomGraph->addDirectedEdge(bunchNodes[a], bunchNodes[b]);
        }
        
        
        return randomGraph;
        
    }
};

class TopSort
{
    vector<Node> Kahns(DirectedGraph graph)
    {
        
//        Count the in-degree (number of edges ending at) each vertex.
//        Create a queue of nodes with in-degree 0.
//        While the queue is not empty:
//            Add the first element in the queue to the ordering.
//            Decrement the in-degree of each of the first element’s neighbors.
//            Add any neighbors that now have in-degree 0 to the queue.
//            Remove the first element from the queue.
        
        vector<Node> result;
        vector<Node*> nodes = graph.getAllNodes();
        queue<Node> kahn;
        
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]->degree == 0)
                //add to queue
                kahn.push(*nodes[i]);
        }
        while(!kahn.empty())
        {
            for(int i=0;i<nodes.size();i++)
            {
                result.push_back(kahn.front());
                vector<Node*> kneigh = kahn.front().neighbors;
                for(int i =0;i<kneigh.size();i++)
                {
                    kneigh[i]->degree--;
                    if(kneigh[i]->degree==0)
                        kahn.push(*kneigh[i]);
                    kahn.pop();
                }
            }
        }
        
        return result;
    }
    
    vector<Node*> mDFS(DirectedGraph graph)
    {
        
//        Have an output stack for the topological sort.
//        Perform a DFS with every node (a full traversal).
//        After all of a node’s neighbors have been visited, push the node onto the output stack.
//        After the traversal finishes, pop every element off the output stack. The order you pop              elements is your topological sort.
        
        
        vector<Node*> result;
        vector<Node*> temp;
        vector<Node*> nodes = graph.getAllNodes();
        
        Node *n;
        
        for(int i=0;i<nodes.size();i++)
        {
            if (!nodes[i]->visited)
            {
                nodes[i]->visited=true;
                temp.push_back(nodes[i]);
                while(!temp.empty())
                {
                    n=temp.back();
                    temp.pop_back();
                    result.push_back(n);
                    for (int j=0;j<n->neighbors.size();j++)
                    {
                        if (!n->neighbors[j]->visited){
                            n->neighbors[j]->visited = true;
                            temp.push_back(n->neighbors[j]);
                        }
                            
                    }
                }
            }
        }
        
        return result;
    }
    
};

vector<int> adj[50];



void DirectedGraph::addNode(const int nodeVal)
{
    Node* n;
    n = new Node(nodeVal);
    n->visited=false;
    graphList.push_back(n);
    return;
}


void DirectedGraph::addDirectedEdge(struct Node *first, struct Node *second)
{
    first->neighbors.push_back(second);
    second->degree++;
    
}



void DirectedGraph::removeDirectedEdge(struct Node *first, struct Node *second)
{
    for (int i=0;i<first->neighbors.size();i++)
    {
        if ( first->neighbors[i]->name == second->name)
        {
            first->neighbors.erase(first->neighbors.begin() + i);
        }
        break;
        
    }
}

vector<Node*> DirectedGraph::getAllNodes()
{
      return graphList;
}

void DirectedGraph::printGraph(vector<Node*> graph)
{
    for (int i=0;i<graphList.size();i++)
    {
        cout << graphList[i]->name << endl;
    }
}

int main()
{
    
    DirectedGraph *randomgraph;
    
    randomgraph->createRandomDAGIter(7);
    
    
    return 0;
    
}
    

