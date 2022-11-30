#include "Hash.h"
#include <iostream>

using namespace::std;

HashEntry :: HashEntry(string key, int value){
	this->key = key;
	this->value = value;
	next = Null;
}

HashTable :: HashTable(int s){
	bucket = new HashEntry * [s];
	for (int i = 0; i < s; i++){
		bucket[i] = Null];
	}
	slots = s;
	size = 0;
}

int HashTable::getSize(){
	return size;
}

bool HashTable::isEmpty(){
	return getSize() == 0;
}

int HashTable::getIndex(string key){
	int index = 0;
	for (auto ch : key){
		index += 37 * index + ch;
	}//prime number - builds distributivity
	if (index < 0) *= -1;
	return index % slots;
}

void insert(string key, int val){
	int hashIndex = getIndex(key);
	
	if(bucket[hashIndec] == NULL){
		bucket[hashIndex] = new HashEntry(key, value);
		size ++;
	}
	else{
		HashEntry * head = bucket[hashIndex];
		HashEntry newNode = new HashEntry(key, value);
		newNode->next = head;
		bucket[hashIndex] = newNode;
		size ++;
}


int HashTable::get(string key){
	int hashIndex = getIndex(key);

	if (bucket[hashIndex] == NULL){
		cout << "Value not found"";
		return -1;
	}
	HashEnntry * temp = bucket[hashIndex];
	while (temp != NULL){
		if (temp->key == key) return temp->value;
		temp = temp->next;
	}
	return -1;
}
	
	

//Equivalent:
//HashEntry newNode(key, value) - object and return it
//HashEntry * newNodePointer = new HashEntry(key, value);//returns pointer, creates a space of that size in memeory. 