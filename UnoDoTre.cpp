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
#include <unordered_map>

using namespace std;

struct Node {
  string name;
  map<Node*, int> adj;
  bool visited;
  Node(string name) {
    this->name=name;
  }
    
};


class WeightedGraph
{
  public:
    vector<Node *> graphList;
    void addNode(const string nodeVal);
    void addWeightedEdge(struct Node *first, struct Node *second, const int edgeWeight);
    void removeDirectedEdge(Node *first, Node *second);
    vector<Node*> getAllNodes();
    void printGraph(vector<Node*> graph);
    
    WeightedGraph* createRandomCompleteWeightedGraph(const int n)
    {
        // creates n random nodes
        
        WeightedGraph *randomGraph;
        
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
        
        vector<Node*> bunchNodes=randomGraph->getAllNodes();
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (bunchNodes[i]->name == bunchNodes[j]->name)
                    continue;
                else{
                    int r = rand() % 15 + 1;
                    addWeightedEdge(bunchNodes[i], bunchNodes[j], r);
                }
            }
        }

        
        
        
        
        
        
        
    }
    
    WeightedGraph createLinkedList(const int n)
    {
        
        
        
        
        
        
        
        
    }
};

class TreadmillMazeSolver
{
    map<Node, int> dijkstras(const Node start)
    {
    //    1.Create an empty map of nodes to distances. Initialize every node to map to infinity.
    //    2.Set the distance for the origin to 0. Let curr be the origin.
    //    3.While curr is not null and its distance is not infinity.
    //        a.“Finalize” curr.
    //        b.Iterate over its neighbors, “relax” each neighbor:
    //            i.For each neighbor that is not finalized, update its distance (if less than its current distance) to the sum of curr’s distance and the weight of the edge between curr and this neighbor.
    //        c.Set curr to the next min distance node – the node with the smallest distance that is not yet finalized.
        
        
        
        
        for (int i=0;i<;i++)
            
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};


vector<Node *> graphList;

void WeightedGraph::addNode(const string nodeVal)
{
    
    Node* n;
    n = new Node(nodeVal);
    n->visited=false;
    graphList.push_back(n);
    return;
}

void WeightedGraph::addWeightedEdge(Node *first, Node *second, const int edgeWeight)
{
    if (first->adj.empty() && (first->name!=second->name))
    {
        first->adj.insert ( pair<Node*,int>(second,edgeWeight) );
    }
    
}

void WeightedGraph::removeDirectedEdge(Node *first, Node *second)
{
    if (first->adj.empty())
    {
        return;
    }
    
    map<Node*, int>::iterator it;
    for (it = first->adj.begin(); it != first->adj.end(); it++)
        if (it->first->name == second->name)
            it->first->adj.erase(second);
}

vector<Node*> WeightedGraph:: getAllNodes()
{
    return graphList;
}




int main()
{
    return 0;
    
    
}

