#include "graph.h"

GRAPH::GRAPH()
{
	nodeCount = 0;
}

GRAPH::GRAPH(int nodes)
{
	
	nodeCount = (nodes + 1);
	array = new adjList[nodeCount];

	for(int i = 1; i < nodeCount; i++){
		array[i].head = NULL;
	}

	
}


void GRAPH::setEdge(int source, int destination, int weight)
{			
	if(source != 0 && destination != 0){

		listNode *node = new listNode;
		node->val = destination;
		node->weight = weight;
		node->next = NULL;
	
		node->next = array[source].head;
		array[source].head = node;		
	}

	else{	
		return;
	}
}

void GRAPH::printGraph()
{	
	cout<<"Adjacency List:"<<endl;

	for(int j = 1; j < nodeCount; j++){
		listNode* temp = array[j].head;
		cout<<j<<" | " << "-> ";
		while(temp != NULL){
			cout<<temp->val << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	} 
}



void GRAPH::dfs(int start)
{	
	//list for visited/unvisited
	bool *Tracked = new bool[nodeCount];

	//stack for push and pop
	stack<int> stack;
	stack.push(start);

	while(!stack.empty()){
		int top = stack.top();
		Tracked[top] = true;
		cout << top << " ";
		stack.pop();

		listNode* tmp = array[top].head;
		while(tmp != NULL){
			if(!Tracked[tmp->val]){
				stack.push(tmp->val);
				Tracked[tmp->val] = true;
			}

		tmp = tmp->next;

		}
	}
	
	cout << endl;
}

void GRAPH::bfs(int start)
{		
	//list for visited/unvisited
	bool *Marked = new bool[nodeCount];

	//queue for enqueues/dequeues
	queue<int> queue;
	queue.push(start);

	while(!queue.empty()){
		int front = queue.front();
		Marked[front] = true;
		cout << front << " ";
		queue.pop();

		listNode* temp = array[front].head;
		while(temp != NULL){
			if(!Marked[temp->val]){
				queue.push(temp->val);
				Marked[temp->val] = true;
			}

		temp = temp->next;

		}
	
	}
	
	cout << endl;
	
}
	
bool GRAPH::isEmpty(vector<bool> vertex){
	for (int i = 0; i < vertex.size(); i++){
		if (vertex[i] == false){
			return false;
		}
	return true;
	}
}

//find the shortest paths from a source to all other nodes
void GRAPH::dijkstra(int source)
{	
	cout << "\nDijkstra\n========\n";

	//list for visited/unvisited
	vector<bool> vertex;
	int distances[nodeCount];
	int minNode;
	int minDistance;
	int parent[nodeCount];

	for(int i =0;i<nodeCount;i++){
		distances[i] = INT_MAX;
		vertex.push_back(false);
		parent[i] = 0;
	}
	
	distances[source] = 0;

	while(!isEmpty(vertex)){
		minNode = INT_MAX;
		minDistance = INT_MAX;
		
		for(int vert = 0; vert < nodeCount; vert++){
			if(vertex[vert] == false && distances[vert] <= minDistance){
				minDistance = distances[vert];
				minNode = vert;
			}
		}
	
	
		vertex[minNode] = true;
		listNode* temp = array[minNode].head;
	
		for (int vert = 0; vert < nodeCount; vert++){

			while(temp != NULL){

				int u = minNode;
				int v = temp->val;
				int w = temp->weight;
				
				if(distances[u] != INT_MAX && distances[v] > distances[u] + w ){
					distances[v] = distances[u] + w;
					parent[v] = u;
				}
				
			temp = temp->next;
			}
	
		}
	
	}
	for(int i = 1; i < nodeCount; i++){
		cout << source << " -> " << i << " | " << distances[i] << endl;
	}
}


void GRAPH::primm(int source)
{
	//print out the resulting tree
	cout << "\nPrimm\n=====" << endl;
	         
	cout << "Edge    Weight" << endl;

	//list for visited/unvisited
	vector<bool> vertex;
	int distances[nodeCount];
	int minNode;
	int minDistance;
	int parent[nodeCount];

	for(int i =0;i<nodeCount;i++){
		distances[i] = INT_MAX;
		vertex.push_back(false);
		parent[i] = 0;
	}
	
	distances[source] = 0;

	while(!isEmpty(vertex)){
		minNode = INT_MAX;
		minDistance = INT_MAX;
		
		for(int vert = 0; vert < nodeCount; vert++){
			if(vertex[vert] == false && distances[vert] <= minDistance){
				minDistance = distances[vert];
				minNode = vert;
			}
		}
	
	
		vertex[minNode] = true;
		listNode* temp = array[minNode].head;
		
	
		for (int vert = 0; vert < nodeCount; vert++){

			while(temp != NULL){

				int u = minNode;
				int v = temp->val;
				int w = temp->weight;
					
				
				if(distances[u] != INT_MAX && distances[v] > distances[u] + w ){
					distances[v] = distances[u] + w;
					parent[v] = u;
					
				}
			temp = temp->next;
			}
	
		}
	
	}

	for(int i = 2; i < nodeCount; i++){

			if(parent[i] != -1){
				cout << parent[i] << " - " << i << "    "  << distances[i] <<endl;
			}
	}

}



