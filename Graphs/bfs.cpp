#include<iostream>
#include<map>
#include <list>
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

};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}