#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <list>
using namespace std;

class Graph {
	int v;
	//l is a list of pointer where each element in the array is a list
	list<pair<int, int> > *l;
public:
	Graph(int v) {
		this -> v = v;
	}

	void addEdge(int u, int v, int wt, bool undir = true) {
		l[u].push_back({wt, v});
		if(undir) {
			l[v].push_back({wt, u});
		}
	}

	// void adjList() {
	// 	//iterate over all the vertices
	// 	//for every list we keep a variable called nbr
	// 	//iterate over ith linked list
	// 	for(int i =0; i< v; i++) {
	// 			cout<< "vertex "<<i <<"-->";
	// 		for(auto nbr : l[i]) {
	// 			cout<<nbr<<",";
	// 		}
	// 	cout<<endl;
	// 	}
	// }

	//weighted graph single source sortest path
	int dijkstra(int src, int dest) {
		//data structures required
		
		//we have v nodes and all initialized with infinity initially
		//weather a node is visited or not and if it is visited then what 
		//is the dist
		vector<int> dist(v, INT_MAX);

		//set will store a pair of current node and it's distance
		set<pair<int, int> > s;

		//Node form itself is zero
		dist[src] = 0;

		//initialize the set
		s.insert({0, src});

		while(!s.empty()) {
			//front
			auto it = s.begin();
			
			int node = it -> second;
			int distTillNow = it -> first;
			//pop operation
			s.erase(it);
			//iterate over the nbr of node
			for(auto nbrPair: l[node]) {
				auto nbr = nbrPair.second;
				auto currEdge = nbrPair.first;
				if(distTillNow + currEdge < dist[nbr]) {
					//if a pair exists remove
					auto f = s.find({dist[nbr], nbr});
					if(f!=s.end()) {
						s.erase(f);
					}
					//insert the updated value with the new dist
					dist[nbr] = distTillNow + currEdge;
					s.insert({dist[nbr], nbr});
				}
			}
		}

		//single sortest dist to all other nodes
		for(int i =0; i< v; i++) {
			cout<<"Node "<<i<< " dist "<<dist[i]<<endl;
		}

		return dist[dest];

	}
};

int main() {
	Graph g(5);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 7);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 3);
	cout<<g.dijkstra(0, 4)<<endl;
	// g.adjList();
	return 0;
}