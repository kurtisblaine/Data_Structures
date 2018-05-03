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


bool GRAPH::setEdge(int source, int destination)
{
	if(source != 0 && destination != 0){
		listNode *node = new listNode;
		node->val = destination;
		node->next = NULL;
	
		node->next = array[source].head;
		array[source].head = node;		

		return true;
	}

	else{	
		return false;	
	}
}

void GRAPH::printGraphData()
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


