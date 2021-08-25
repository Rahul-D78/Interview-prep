#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <vector>
using namespace std;

/*
	we can only use directed acyclic graphs
*/

template <typename T>
class Graph {
	map<T, list<T> > l;

public:
	
	void addEdge(T x, T y) {
		// l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
		//recursive func that will traverse the graph
		// cout<<src<<" ";

		visited[src] = true;
		
		for(T nbr: l[src]) {
			//go to all the neighbour of that node which is not visited
			if(!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}

		//before returning we should push to the front of the ordering node
		ordering.push_front(src);
	}

	void dfs(T src) {
		//mark all the nodes as not visited in the beginning
		map<T, bool> visited;
		list<T> ordering;
		for(auto p:l) {
			T node = p.first;
			visited[node] = false;
		}
		//call the helper function
		for(auto p : l) {
			T node = p.first;
			if(!visited[node]) {
				dfs_helper(src, visited, ordering);
			}
		}
		//finally print the list
		for(auto node: ordering) {
			cout<<node<<endl;
		}
	}

};

int main () {

	Graph<string> g;
	
	g.addEdge("python", "data preprocessing");
	g.addEdge("python", "pytorch");
	g.addEdge("dataPreprocessing", "ML");
	g.addEdge("pytorch", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FaceRecon");
	g.addEdge("dataset", "FaceRecon");

	g.dfs("python");

	return 0;
}