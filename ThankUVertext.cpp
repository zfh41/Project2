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


class DirectedGraph
{
  public:
    vector<Node *> graphList;
    void addNode(const string nodeVal);
    void addDirectedEdge(struct Node *first, struct Node *second);
    void removeDirectedEdge(struct Node *first, struct Node *second);
    vector<Node*> getAllNodes();
    void printGraph(vector<Node*> graph);
    
    DirectedGraph* createRandomDAGIter(const int n)
    {
        
        
        
        
        
        
        
    }
};

vector<int> adj[50];

void DirectedGraph::addNode(const string nodeVal)
{

    Node* n;
    n = new Node(nodeVal);
    graphList.push_back(n);
    return;
}


void DirectedGraph::addDirectedEdge(struct Node *first, struct Node *second)
{
    first->neighbors.push_back(second);
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
    return 0;
    
}
    

