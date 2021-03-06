#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <functional>
#include <fstream>
#include <list>


using namespace std;
//#define INFINITY INT_MAX

	struct adjList{
		
		struct listNode *head;
	};	

	struct listNode{
		int val;
		int weight;
		listNode* next;
	};


class GRAPH{
public:
	GRAPH();
	GRAPH(int);
	void setEdge(int, int, int);
	void printGraph();
	void dfs(int);
	void bfs(int);
	// Use dijkstra's to find the shortest distance from a given node
	void dijkstra(int);
	// construct a MST using primm's algorithm
	void primm(int);
	bool isEmpty(vector<bool>);

private:
	int nodeCount;
	int *edgeCount;
	adjList* array;
	int *distances;
	int minNode, minDistance;
	int *parent;
	listNode* temp;
	int u, v, w;
	
};


#endif
