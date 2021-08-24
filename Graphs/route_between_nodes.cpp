#include<iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template<typename T>

class Graph{
	map<T, list<T> >l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool search(T src, T end) {
		/* DS neede
		1. queue
		2. visited array
		*/
		map<T, int> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			T node = q.front();
			q.pop();
			if(node == end) return true;

			for(auto nbr: l[node]) {
				// l[node] --> the value of that node
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		return false;
	}
};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if(g.search(0, 9)) {
    	cout<<"path present";
    }else {
    	cout<<"path is not presetn";
    }

	return 0;
}