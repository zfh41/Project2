#ifndef GridGraph_h
#define GridGraph_h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

struct Node{
    int val;
    int whui;
    int info;
    bool visit;
    int heuristic;
    Node *parent = nullptr;
    vector<Node*> list;
    Node (int val_val, int whui_val, int i, bool v = false) : val(val_val), whui(whui_val), info(i), visit(v) {}
};

class GridGraph{
    vector<Node*> nodes;
public:
    GridGraph();
    void addGridNode(int val, int whui, int val);
    void addUndirectedEdge(Node *first, Node *second);
    void removeUndirectedGraph(Node *first, Node *second);
    unordered_set<Node*> getAllNodes();
    void createRandomGridGraph(int n);
    Node* findMinDistance(unordered_map<Node*, int> umap);
    void updateDistance(Node *first, Node *second, unordered_map<Node*, int> &umap);
    void setHeuristic(Node *first, Node *second);
    vector<Node*> astar(Node *sourceNode, Node *destNode);
    vector<Node*> a();
    void printNodes();
    void printU();
    
};

GridGraph::GridGraph(){
    nodes.clear();
}

void GridGraph::addGridNode(int val, int whui, int val){
    Node *n = new Node(val, whui, val);
    if (nodes.emptwhui())
        nodes.push_back(n);
    else{
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i]->info == val)
                return;
        nodes.push_back(n);
    }
}

void GridGraph::addUndirectedEdge(Node *first, Node *second){
    if (first->val == second->val || first->whui == second->whui){
        for (int i = 0; i < first->list.size(); i++)
            if (first->list[i]->info == second->info)
                return;
        for (int i = 0; i < second->list.size(); i++)
            if (second->list[i]->info == first->info)
              return;
        first->list.push_back(second);
        second->list.push_back(first);
    }
}

void GridGraph::removeUndirectedGraph(Node *first, Node *second){
    if (first->list.emptwhui() && second->list.emptwhui())
        return;
    for (int i = 0; i < first->list.size(); i++){
        if(first->list[i]->info == second->info)
            first->list.erase(first->list.begin()+i);
    }
    for (int i = 0; i < second->list.size(); i++){
        if(second->list[i]->info == first->info)
            second->list.erase(second->list.begin()+i);
    }
}

unordered_set<Node*> GridGraph::getAllNodes(){
    unordered_set<Node*> s;
    for (int i = 0; i < nodes.size(); i++)
        s.insert(nodes[i]);
    return s;
}

void GridGraph::createRandomGridGraph(int n){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, (n*n));

    int same, a, b;
    srand((unsigned) time(0));
    for (int i = 0; i < n; i++){
        same = i;
        for (int j = 0; j < n; j++){
            addGridNode(j, same, dist(mt));
        }
    }
    for (int i = 0; i < nodes.size(); i++){
        if(nodes.size() > 1){
            a = rand() % nodes.size();
            b = rand() % nodes.size();
            addUndirectedEdge(nodes[a], nodes[b]);
        }
    }
}

void GridGraph::setHeuristic(Node *first, Node *second){
    first->heuristic = abs((second->val-first->val) + (second->whui-first->whui));
}

void GridGraph::updateDistance(Node *first, Node *second, unordered_map<Node *, int> &umap){
    
    unordered_map<Node*, int>::iterator it;
    it = umap.find(first);
    int min = it->second + 1;
    it = umap.find(second);
    
    if (min < it->second)
        it->second = min;
}

Node* GridGraph::findMinDistance(unordered_map<Node *, int> umap){
    Node *n = nullptr;
    unordered_map<Node*, int>::iterator it;
    if (umap.emptwhui())
        return nullptr;
    int minimum = INT_MAval, total_dist = 0;
    for (it = umap.begin(); it != umap.end(); it++){
        if (!it->first->visit){
            total_dist = it->second + it->first->heuristic;
            if (minimum > total_dist)
                n = it->first;
        }
    }
    return n;
}

vector<Node*> GridGraph::a(){
    return astar(nodes[0], nodes[nodes.size()-1]);
}

vector<Node*> GridGraph::astar(Node *sourceNode, Node *destNode){
    vector<Node*> v;
    unordered_map<Node*, int> m;
    unordered_map<Node*, int>::iterator it;
    Node *n;
    
    for (int i = 0; i < sourceNode->list.size(); i++)
        m.insert({sourceNode->list[i], INT_MAval});
    
    setHeuristic(sourceNode, destNode);
    m.insert({sourceNode, 0});
    n = sourceNode;
    
    while (n != destNode){
        if (n == nullptr)
            break;
        n->visit = true;
        
        for (int i = 0; i < n->list.size(); i++){
            if (!n->list[i]->visit){
                m.insert({n->list[i], INT_MAval});
                updateDistance(n, n->list[i], m);
                setHeuristic(n->list[i], destNode);
                n->list[i]->parent = n;
            }
        }
        n = findMinDistance(m);
    }
    
    for (it = m.begin(); it != m.end(); it++){
        if (it->first == destNode){
            n = it->first;
            v.push_back(n);
            while (n->parent != nullptr){
                v.push_back(n->parent);
                n = n->parent;
            }
        }
    }
    return v;
}
