#include <iostream>
using namespace std

class HashEntry{
public:
string key;
int value;
HashEntry * next;

HashEntery(string key, int value);
};
//declaration of data strctures

class HashTable{
private:
	HashEntery ** bucket;
	int slots;
	int size;
	int getIndex(string key);
public:
	HashTable(int size);//no of slots
	int getSize();
	bool isEmpty();
	int get(string key);
	void insert(string key, int value);
};
//hash table stores keys and values