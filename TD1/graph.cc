#include "graph.h"

DirectedGraph::DirectedGraph(int num_nodes)
{
    vector<vector<int>> nodes(num_nodes);
    this->num_nodes = num_nodes;
    this->num_arcs = 0;
    this->nodes = nodes;
}

int DirectedGraph::NumNodes() const {
    return this->num_nodes;
}

void DirectedGraph::AddArc(int from, int to) {
    this->nodes[from].push_back(to);
    this->num_arcs++;
}

int DirectedGraph::OutDegree(int node) const {
    return this->nodes[node].size();
}

const vector<int>& DirectedGraph::Neighbors(int node) const {
    return this->nodes[node];
}

int DirectedGraph::NumArcs() const {
    return this->num_arcs;
}

void DirectedGraph::MakeSimple() {
    for (int n=0;n<this->nodes.size();n++) {
        this->nodes[n].erase( std::remove( this->nodes[n].begin(), this->nodes[n].end(), n ), this->nodes[n].end() ); 
        this->nodes[n].erase( unique( this->nodes[n].begin(), this->nodes[n].end() ), this->nodes[n].end() );
    }
}