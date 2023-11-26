//BFS mplementation for Undirected Graph for Adjacency Matrix 
// 1. Push any vertex to queue
// 2. Take the first element from the queue and add it to visited list
// 3. Create a list of al adjascent nodes and add the unvisited oned to queue
// 4. Repeat steps 2 and 3 until queue is empty

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
   	private:
		bool** adj;	//Adjascency Matrix
		int v;		//No of vertices
   	public:
  		// Initialize the matrix to zero
  		Graph(int v) {
    		this->v = v;
    		adj = new bool*[v];
    		for (int i = 0; i < v; i++) {
    		  	adj[i] = new bool[v];
    		  	for (int j = 0; j < v; j++)
    		  	  adj[i][j] = false;
    		}
  		}

 		// Add edges
 		void addEdge(int i, int j) {
 		  	adj[i][j] = true;
 		  	adj[j][i] = true;
 		}

  		// Remove edges
  		void removeEdge(int i, int j) {
  		  	adj[i][j] = false;
  		  	adj[j][i] = false;
  		}

  		// Print the martix
  		void display() {
  		  	for (int i = 0; i < v; i++) {
  		  	  	cout << i << " : ";
  		  	  	for (int j = 0; j < v; j++)
  		  	  	  	cout << adj[i][j] << " ";
  		  	  	cout << "\n";
  		  	}
  		}

		void BFS_Traversal(int src){
			vector <int> visited (v, 0);
			queue<int> q;
			//Starting with source node
			q.push(src);
			visited[src] = 1;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				cout << node << " ";
				//Visiting all connected nodes and enqueue unvisited nodes for exploration
				for(int j = 0; j < v; j++){
					if(adj[node][j] == 1 && visited[j] != 1){
						visited[j] = 1;
						q.push(j);	//Enqueing unvisited node
					}
				}
			}
			cout << endl;
		}

  		~Graph() {
  		  	for (int i = 0; i < v; i++)
  		  	  	delete[] adj[i];
  		  	delete[] adj;
  		}
};

/*
	0---- 1
    | \   |
    |  \  |
	3-----2
	 \	 /
	  \	/
	   4
	  / \
	 5   6
*/
int main() {
  	Graph g(7);
  	g.addEdge(0, 1);
  	g.addEdge(0, 2);
  	g.addEdge(0, 3);
  	g.addEdge(2, 1);
  	g.addEdge(2, 3);
  	g.addEdge(2, 4);
  	g.addEdge(3, 4);
  	g.addEdge(4, 5);
  	g.addEdge(4, 6);

  	cout << "BFS :  "; 
	g.BFS_Traversal(0);
	return 0;
}