#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//to store the data (Linked List)
class Node{
public:
	string key;
	int value;
	Node(string key, int value) {
		this -> key = key;
		this -> value = value;
	}
};

//LRU cache implementation
class LRUCache {
public:
	//to define the max num of elements
	int maxsize;
	list<Node> l;

	//this is the address of a perticular node that is 
	//there inside a list
	unordered_map<string, list<Node>::iterator > m;

	LRUCache(int maxsize) {
		this -> maxsize = maxsize > 1 ? maxsize : 1;
	}

	void insertKeyValue(string key, int value) {
		//present or not present
		if(m.count(key)!=0) {
			//replace the old value
			auto it = m[key];
			it -> value = value;
		}else {
			//check if the cache is present or not
			//if it is full then we have to remove the last item from the list
			//least recently used item from cache
			if(l.size()==maxsize) {
				Node last = l.back();
				m.erase(last.key); //removes from the hashmap 
				l.pop_back(); //removes from the linked list
			}

			//whatever new node you have inserted in the hashmap you need to insert
			//new followed by the address (address of the node in the begining of the list)
			Node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
			 	
		}
	}

	int* getValue(string key) {
		if(m.count(key)!=0) {
			auto it = m[key];
			int value = it -> value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin() -> value;
		}
		return NULL;
	}

	string mostRecentKey() {
		return l.front().key;
	}

};

int main() {
	LRUCache lru(3);
	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("guava", 30);
	cout<<lru.mostRecentKey()<<endl;
	lru.insertKeyValue("mango", 40);
	cout<<lru.mostRecentKey()<<endl;
	lru.insertKeyValue("banana", 20);
	if(lru.getValue("apple")==NULL) {
		cout<<"apple does not exists";
	}
	if(lru.getValue("mango")==NULL) {
		cout<<"mango does not exists";
	}
	if(lru.getValue("guava")==NULL) {
		cout<<"guava does not exists";
	}
	if(lru.getValue("banana")==NULL) {
		cout<<"banana does not exists";
	}
	return 0;
}