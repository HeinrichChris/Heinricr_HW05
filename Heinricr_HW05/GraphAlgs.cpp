#include "GraphAlgs.h"
#include "Graph.h"
#include <vector>

void swap(int* arr, int n, int m){
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;
}

double tour(int* arr, int n, int startingPlace, Graph* G, double min){
	double myMin = 0;
	if(n-startingPlace == 1){
		for(int i = 0; i<n-1; i++){
			myMin += G->weight(arr[i], arr[i+1]);
		}
		if(min == -1){
			min = myMin;
		}
		else{
			if(myMin < min){
				min = myMin;
			}
		}
	}
	else{
		for(int i=startingPlace; i<n; i++){
			swap(arr, startingPlace, i);
			min = tour(arr, n, startingPlace, G, min);
			swap(arr, startingPlace, i);
		}
	}
	return min;
}

std::vector<NodeID> findVector(int* arr, int n, int startingPlace, Graph* G, double min){
	std::vector<NodeID> vect(G->size(), -1);

	for(int i = 0; i<n; i++){
		vect[i] = arr[i];
	}

	double myMin = 0;
	if(n-startingPlace == 1){
		for(int i = 0; i<n-1; i++){
			myMin += G->weight(arr[i], arr[i+1]);
		}
		if(min == -1){
			min = myMin;
		}
		else{
			if(myMin = min){
				return vect;
			}
		}
	}
	else{
		for(int i=startingPlace; i<n; i++){
			swap(arr, startingPlace, i);
			vect = findVector(arr, n, startingPlace, G, min);
			swap(arr, startingPlace, i);
		}
	}
	return vect;
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	int* arr = new int[G->size()];
	double min;


	for(int i = 0; i<G->size(); i++){
		arr[i] = i;
	}
	min = tour(arr, G->size(), 0, G, -1);
	std::vector<NodeID> vect = findVector(arr, G->size(), 0, G, min);

	return std::pair<std::vector<NodeID>, EdgeWeight> (vect, min);
}