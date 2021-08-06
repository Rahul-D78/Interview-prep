#include<iostream>
#include<map>
#include <climits>
#include <list>
#include <set>
#include <queue>
using namespace std;

template <typename T>

class Graph {
public:
	map<T ,list<T> > l;

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs(T src) {
		/* DataStructures needed
		   1. queue
		   2. visited array
		*/
		//stores the value of a node with a coresponding boolean value 
		//to check weather it is visited or not .
		map<T, int> visited;
		//functionality is mainly depens of this ds
		//when we are entering inside the while loop we are fetching the node 
		//from the frontend and poping outside of queue and printing it and 
		//inside the for loop we are l[node] and printing the nodes are which
		//are connected to that node .
		// 1 --> [2, 3, 4, 5];
		// 2 --> [5, 5, 6, 7];  something like this we have done in the addEdge function
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			
			//get front of the node and print
			T node = q.front();
			q.pop();
			cout<<node<<" ";

			for(auto nbr: l[node]) {
				//l[node] basically give me the value of that node
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		//rec fun that  will the traverse the graph
		cout<<src<<" ";
		visited[src] = true;
		for(T nbr: l[src]) {
			if(!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs(T src) {
		//make all the nodes as not visited initially
		map<T, bool> visited;
		for(auto p: l) {
			T node = p.first;
			visited[node] = false;
		}
		//call the helper function
		dfs_helper(src, visited);
	}

	//shortest path to reach from a src node 
	//to a destination node
	void dijkstra(int src, int dest) {
		//we have v nodes and all initializd with infinity initially
		//weather a node is visited or not and if it is visited 
		//then what is the dist
		vector<int> dist(v, INT_MAX);

		//set will store a pair of current nodes and it's distance
		set<pair<int, int> > s;

		//Node from itself is zero
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

			//iterate over the nbr of the node
			for(auto nbrPair: l[node]) {
				auto nbr = nbrPair.second;
				auto currEdge = nbrPair.first;
				if(distTillNow + currEdge < dist[nbr])  {
					//if a pair exists remove
					auto f = s.find({dist[nbr], nbr});
					if(f != s.end()) {
						s.erase(f);
					}

				}
			}
		}

	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(0);
	return 0;
}