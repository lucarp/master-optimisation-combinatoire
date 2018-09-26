#include "ugraph.h"


UndirectedGraph::UndirectedGraph(int num_nodes) {
    this->graph = new DirectedGraph(num_nodes);
}

void UndirectedGraph::AddEdge(int a, int b) {
    this->graph->AddArc(a,b);
    this->graph->AddArc(b,a);
}

int UndirectedGraph::NumNodes() const {
    return this->graph->NumNodes();
}

int UndirectedGraph::NumEdges() const {
    return this->graph->NumArcs() / 2;
}

int UndirectedGraph::Degree(int node) const {
    return this->graph->Neighbors(node).size();
}

const vector<int>& UndirectedGraph::Neighbors(int node) const {
    return this->graph->Neighbors(node);
}

vector<int> UndirectedGraph::GetNodesConnectedTo(int node) {
   vector<int> connectedTo = { node };
    for (int k=0; k < connectedTo.size(); k++) {
      for (int i=0; i < this->Neighbors(connectedTo[k]).size(); i++) {
          if (!(std::find(connectedTo.begin(), connectedTo.end(),this->Neighbors(connectedTo[k])[i])!=connectedTo.end())) {
            connectedTo.push_back(this->Neighbors(connectedTo[k])[i]);
          }
      }
    }
    return connectedTo;
}


vector<vector<int>> UndirectedGraph::ConnectedComponents() {
    vector<vector<int>> components;
    
    for(int i; i < this->NumNodes; i++) {
        vector<int> component = this->GetNodesConnectedTo(i);
        components.push_back(component);
    }
}