#include <fstream>
#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
	GRAPH* g = NULL;

	ifstream file;
	int nodes, edges, source, destination, cmd, p1, p2, w;

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
		file >> destination;
		file >> w;
		g->setEdge(source, destination, w);
	}
	file.close();

	file.open("cmd.txt");
	if (!file.is_open())
	{
		cout << "Error: Failed to open cmd file\n";
		return 0;
	}

	while (file >> cmd)
	{
		switch (cmd) 
		{
			case 1:
				file >> p1;
				file >> p2;
				file >> w;
				g->setEdge(p1, p2, w);
				break;
				break;
			case 2:
				g->printGraph();
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
			case 5:
				file >> p1;
				g->dijkstra(p1);
				break;
			case 6:
				file >> p1;
				g->primm(p1);
				break;
			default:
				cout << "Error: Unknown cmd\n";
		}
	}
	
	file.close();
	return 0;
}