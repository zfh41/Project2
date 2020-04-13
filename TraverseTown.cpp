#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

struct Node {
  string name;
  vector<Node*> neighbors;
  Node(string name) {
    this->name=name;
  }
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
        
        const string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        random_device = random_device;
        mt19937 generator(random_device());
        
        uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
        
        string random_string;
        
        int randVal;
        
        for (int i=0;i<n;i++)
        {
            //create random value
            random_string += CHARACTERS[distribution(generator)];
            
            //store that random value into add node
            addNode(random_string);


        }

        
        
        // randomly assign unweighted bidirectional edges to the nodes
        
        
        
        
    }
                              
    

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

