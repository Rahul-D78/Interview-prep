#include<iostream>
#include<list>
#include <map>
using namespace std;

template<typename T>

class Graph {
	map<T, list<T> > l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	//since this map should remain same we have to pass it by reference
	void dfs_helper(T src, map<T, bool> &visited) {
		//recursive function that will travese the graph
		cout<<src<<" ";
		visited[src] = true;
		for(T nbr: l[src]) {
			//go to all the neighbour of that node which is not visited
			if(!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}
	void dfs(T src) {
		//mark all the nodes as not visited in the beginning
		map<T, bool> visited;
		for(auto p: l) {
			T node = p.first;
			visited[node] = false;
		}
		//call the helper function
		dfs_helper(src, visited);
	}
};


int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(0);
	return 0;
}