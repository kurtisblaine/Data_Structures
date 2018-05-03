#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <cstddef>
#include <iostream>
#include <iomanip>

// These are the headers to include to use STL stacks/queues/vectors
// More info on how to use them can be found at http://www.cplusplus.com/reference/stl/
#include <stack>
#include <queue>
#include <vector>

using namespace std;

	struct adjList{
		
		struct listNode *head;
	};	

	struct listNode{
		int val;
		listNode* next;
	};
	

class GRAPH{
public:

	// Empty constructor for an unknown number of edges or nodes
	GRAPH(void);
	// Constructor to use when we have an initial number of nodes & edges
	GRAPH(int nodes);
	// Set the edge going from src to dst
	bool setEdge(int src, int dst);
	// Print your backing data store. If using a matrix, print the matrix, if
	// using the list print the list
	void printGraphData(void);
	// Perform a dfs from the provided start node
	void dfs(int start);
	// perform a bfs from the provided start node
	void bfs(int start);
	
private:
	int nodeCount;
	adjList* array;
	
};

#endif
