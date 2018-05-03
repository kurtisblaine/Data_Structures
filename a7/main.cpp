#include <fstream>
#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
	GRAPH* g = NULL;

	ifstream file;
	int nodes, source, destination, cmd, p1, p2;

	/*
	* Open our edges file so we can read in our graph data
	*/
	file.open("edges.txt");
	if (!file.is_open())
	{
		cout << "Error: Failed to open input file\n";
		return 0;
	}
	file >> nodes;
	g = new GRAPH(nodes);

	while (file >> source)
	{
		// working in an undirected graph so add both edges to the graph               
		file >> destination;
		g->setEdge(source, destination);
		g->setEdge(destination, source);
	}
	file.close();

	file.open("cmd.txt");
	if (!file.is_open())
	{
		cout << "Error: Failed to open cmd file\n";
		return 0;
	}

	/*
	* Read in our cmd file and perform operations on the graph
	*/
	while (file >> cmd)
	{
		switch (cmd) 
		{
			case 1:
				file >> p1;
				file >> p2;
				g->setEdge(p1, p2);
				break;
				break;
			case 2:
				g->printGraphData();
				cout << "\n";
				break;
			case 3:
				file >> p1;
				cout << "DFS from "<<p1<<": ";
				g->dfs(p1);
				break;
			case 4:
				file >> p1;
				cout << "BFS from " << p1 << ": ";
				g->bfs(p1);
				break;
			default:
				cout << "Error: Unknown cmd\n";
		}
	}
	
	file.close();
	return 0;
}