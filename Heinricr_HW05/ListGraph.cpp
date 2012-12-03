#include "ListGraph.h"


ListGraph::ListGraph(int numNodes)
{
	arr = new std::list<NWPair>[numNodes];
	this->numNodes = numNodes;
}


ListGraph::~ListGraph(void)
{
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	NWPair add (v, weight);

	arr[u].push_back(add);
}
  
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	EList::const_iterator it = arr[u].begin();

	for(it = arr[u].begin(); it!= arr[u].end(); it++){
		NWPair tPair = (*it);
		if(tPair.first == v)
			return tPair.second;
	}
	return 0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return arr[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return arr[u].size();
}

unsigned ListGraph::size() const{
	return numNodes;
}

unsigned ListGraph::numEdges() const{
	unsigned num = 0;

	for(int i = 0; i<numNodes; i++){
		num += arr[i].size();
	}
	return num;
}