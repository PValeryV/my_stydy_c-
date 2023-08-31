//#pragma once
#ifndef DOUBLE_LIST
#define DOUBLE_LIST
//template<class T>
#include<iostream>

class List {
	friend std::ostream& operator<<(std::ostream& stream, const List& object);
public:
	List(int value);
	~List();
	void  add(int);
	void cut();
	void Next();
	void Down();


private:
	struct node {
		node* Next = nullptr;
		node* Down = nullptr;
		int value;
		node(int v, node*t,node*x) {
			value = v; Next = t; Down = x;
		};
	};
	node* head;
	node* end_list;
	node* current;
};



#endif