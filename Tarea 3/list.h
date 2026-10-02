

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>


template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) {
	value = val;
	next = NULL;
}

template <class T>
Link<T>::Link(T val, Link* nxt) {
	value = val;
	next = nxt;
}

template <class T>
Link<T>::Link(const Link<T> &source) {
	value = source.value;
	next = source.next;
}

template <class T>
class List {
public:
	List();
	List(const List<T>&);
	~List();

	bool empty() const;
	int  length() const;
	void addFirst(T) ;
	std::string toString() const;



	void insertion(T);
	int  search(T) const;
	void update(int, T);
	T    deleteAt(int);


private:
	void clear();

	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List(){
	head = NULL;
	size = 0;
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *n = new Link(val);
	n->next = head;
	head = n;
	size++;
}





template <class T>
void List<T>::insertion(T val)  {
Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		return;
	}

	if (empty()) {
		addFirst(val);
		return;
	}
   
	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
int List<T>::search(T val) const {
	Link<T> *p;
	p = head;
	int count = 0;
	while (p != 0) {
		if (p->value == val) {
			return count;
		}
		p = p->next;
		count++;
	}
	return -1;
}

template <class T>
void List<T>::update(int index, T newVal) {
   	if (index < 0 || index >= size) {
   		return;
   	}
   	Link<T> *p = head;
   	for (int i = 0; i < index; i++) {
   		p = p->next;
   	}
   	p->value = newVal;
   }

template <class T>
T List<T>::deleteAt(int index) {
	if (index < 0 || index >= size) {
	 return -1;
	}

	Link<T> *p = head;
	T valor;

	if (index == 0) {
		head = p->next;
		valor = p->value;
		delete p;
	} 
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		Link<T> *borrar = p->next;
		p->next = borrar->next;
		valor = borrar->value;
		delete borrar;
	}
	size--;
	return valor;
}



#endif
