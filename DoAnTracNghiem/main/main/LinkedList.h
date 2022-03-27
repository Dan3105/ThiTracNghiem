#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* next = nullptr;

	Node();
	Node(T);
};

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	int size;
	bool isSort;
	int DeleteNode(Node<T>*&, Node<T>*&); // previousNode, deleteNode

#pragma region SortAlgorithm
	Node<T>* midNode(Node<T>*);

	Node<T>* Merge(Node<T>*&, Node<T>*&, bool(*cmp)(T, T));

	Node<T>* MergeSort(Node<T>*&, bool (*cmp)(T, T));
#pragma endregion
public:
	LinkedList();
	LinkedList(T data);
	~LinkedList();

	int GetSize(); //getter

	int AddNode(T);
	int InsertOrder(T);

	template<typename S>
	int DeleteBase(S, bool); // compare condition / delete all same thing ?
	
	template<typename S>
	Node<T>* FindElement(S); // find element base on condition;

	void Sort(bool (*)(T,T)); // sort base on condition
};




