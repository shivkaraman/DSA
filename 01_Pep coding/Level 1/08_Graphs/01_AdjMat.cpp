// Adjacency Matrix representation in C++
// Implementation for Undirected Graph

#include <iostream>
using namespace std;

class Graph {
   	private:
		bool** adj;	//Adjascency Matrix
		int V;		//No of vertices

   	public:
  		// Initialize the matrix to zero
  		Graph(int V) {
    		this->V = V;
    		adj = new bool*[V];
    		for (int i = 0; i < V; i++) {
    		  	adj[i] = new bool[V];
    		  	for (int j = 0; j < V; j++)
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
  		  	for (int i = 0; i < V; i++) {
  		  	  	cout << i << " : ";
  		  	  	for (int j = 0; j < V; j++)
  		  	  	  	cout << adj[i][j] << " ";
  		  	  	cout << "\n";
  		  	}
  		}

  		~Graph() {
  		  	for (int i = 0; i < V; i++)
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
  	Graph g(4);

  	g.addEdge(0, 1);
  	g.addEdge(0, 2);
  	g.addEdge(1, 2);
  	g.addEdge(2, 0);
  	g.addEdge(2, 3);

  	g.display();
	return 0;
}