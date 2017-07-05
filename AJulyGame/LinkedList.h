
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class T>
struct Node {
	Node(Node<T>*prev, Node<T>*next, T data) 
		:prev(prev),next(next),data(data)
	{
	}
	Node<T>*next;
	Node<T>*prev;
	T data;
};
template<class T>
struct LinkedList {
	LinkedList() {
		head = new Node<T>(NULL, NULL, (T)0);
		tail = new Node<T>(head, NULL, (T)0);
		head->next = tail;
		size = 0;
	}
	LinkedList(Node<T>*firstNode, Node<T>*lastNode) {
		head = new Node<T>(NULL, firstNode, (T)0);
		tail = new Node<T>(lastNode, NULL, (T)0);
		for (Node<T>*iter = head->next; iter != tail->prev->next; iter = iter->next)
			size++;
	}
	~LinkedList() {
		//what if type of data is a dynamic pointer
		emptyList();
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void addFirst(T data) {
		addNode(head, data);
	}
	void addLast(T data) {
		addNode(tail->prev, data);
	}
	void delFist() {
		if (head->next != tail)
			delNode(head->next);
	}
	void delLast() {
		if (tail->prev != head)
			delNode(tail->prev);
	}
	void addNode(Node<T>*pointer, T data) {
		Node<T>*newNode = new Node<T>(pointer, pointer->next, data);
		newNode->next->prev = newNode;
		newNode->prev->next = newNode;
		size++;
	}
	bool emptyList() {
		for (Node<T>*iter = head->next; iter != tail; iter = iter->next)
			iter = delNode(iter);
		return true;
	}
	Node<T>* delNode(Node<T>*pointer) {
		Node<T>*temp = pointer->prev;
		pointer->next->prev = pointer->prev;
		pointer->prev->next = pointer->next;
		pointer->next = NULL;
		pointer->prev = NULL;
		delete pointer;
		pointer = NULL;
		size--;
		return temp;
	}
	bool isEmpty()const {
		return(size == 0);
	}
	int getSize()const {
		return this->size;
	}
	Node<T>*getFirstNode() {
		return head->next;
	}
	//two controling nodes
	Node<T>*head;
	Node<T>*tail;
	int size;
};
#endif // !LINKED_LIST_H
