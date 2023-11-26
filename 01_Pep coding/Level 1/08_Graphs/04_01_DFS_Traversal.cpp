// IDFS and BFS mplementation for Undirected Graph for Adjacency Matrix 
// 1. Put any one vertex at top of stack
// 2. Take the top element from the stack and add it to the visited list
// 3. Create a list of all adjascent nodes and add the one which is unvisited on tho the stack
// 4. Keep repeating steps 2 and 3 until stack in not empty  

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
   	private:
		bool** adj;	//Adjascency Matrix
		int v;		//No of vertices
        bool *visited;
   	public:
  		// Initialize the matrix to zero
  		Graph(int v) {
    		this->v = v;
    		adj = new bool*[v];
    		visited = new bool[v];
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

		// void DFS_Traversal(){
		// 	bool visited[v];
		// 	//Marking all nodes unvisited
		// 	for(int i = 0; i < v;  i++)
		// 		visited[i] = 0;
		// 	stack<int> s;
		// 	int i = 0;/
		// 	s.push(i);
		// 	while(!s.empty()){
		// 		int node = s.top();
		// 		visited[node= true;
		// 		s.pop();
		// 		cout << node << " ";
		// 		for(int j = 0; j < v; j++){
		// 			if(adj[node][j] == 1 && visited[j] != 1){
		// 				s.push(j);
		// 			}
		// 		}
		// 	}
		// 	cout << endl;
		// }

		//Expectation -> Traverse the whole graph
		//Faith -> Function knows to traversse all other elements than current node/vertex
		//E-F -> Print the current node and explore thr current node and let faith do its job
		void DFS_Traversal(int node){
			visited[node] = 1;
			cout << node << " ";
			for(int i = 0; i < v; i++){
				if(adj[node][i] == 1 && visited[i] != 1)
					DFS_Traversal(i);
			}
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
	  \   /
	   \ /
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

  	cout << "DFS :  "; 
	g.DFS_Traversal(0);
	return 0;
} 