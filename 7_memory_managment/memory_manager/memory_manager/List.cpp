#include"List.h"

List::List(int value) {
	node* t = new node(value,nullptr,nullptr);
	head = t;
	end_list = t;
	current = t;
}
List::~List() {
	while (head) {
		node* temp = head;
		head = head->Next;
		delete temp;
	}
}
void List::add(int v) {
	node* t = new node(v, nullptr,end_list);
	end_list->Next = t;
	end_list = t;
}

void List::cut() {
	if (current == head) {
		head->Next->Down = nullptr;
		head = head->Next;
		delete current;
		current = head;
	}
	else if (current == end_list) {
		end_list->Down->Next = nullptr;
		end_list = end_list->Down;
		delete current;
		current = end_list;
	}
	else {
		current->Down->Next = current->Next;
		current->Next->Down = current->Down;
		node* temp = current->Next;
		delete current;
		current = temp;
	}
}
void List::Next() {
	if (current->Next) current = current->Next;
}
void List::Down() {
	
	if (current!= head) current = current->Down;
}

std::ostream& operator<<(std::ostream& stream, const List& object) {
	return stream<<object.current->value<< " ";
}