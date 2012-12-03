#include "MatrixGraph.h"
#include "Graph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	arr = new double[num_nodes*num_nodes];
	this->num_nodes = num_nodes;

	for(int i = 0; i<num_nodes*num_nodes; i++){
		arr[i] = -1;
	}
}


MatrixGraph::~MatrixGraph(void)
{
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	arr[u*num_nodes + v] = weight;
	arr[v*num_nodes + u] = weight;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return arr[u*num_nodes + v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> nodes;

	for(int i = u*num_nodes; i<(u+1)*num_nodes; i++){
		if(arr[i] != -1){
			NWPair add (i, arr[i]);

			nodes.push_back(add);
		}
	}

	return nodes;
}

unsigned MatrixGraph::degree(NodeID u) const{
	unsigned num = 0;

	for(int i = num_nodes*u; i<num_nodes*(u+1); i++){
		if(arr[i]!= -1)
			num++;
	}
	return num;
}

unsigned MatrixGraph::size() const{
	return num_nodes;
}

unsigned MatrixGraph::numEdges() const{
	unsigned num = 0;
	for(int i = 0; i<num_nodes; i++){
		for(int j = 0; j<num_nodes; j++){
			if(arr[i*num_nodes + j] != -1)
				num++;
		}
	}
	return num;
}