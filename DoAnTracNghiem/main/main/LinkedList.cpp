#include "LinkedList.h"

#pragma region Node
template <class T>
Node<T>::Node() : data(0) {};

template <class T>
Node<T>::Node(T _data) : data(_data) {};
#pragma endregion

#pragma region LinkedList
template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>();
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T _data)
{
	head = new Node<T>(_data);
	size = 1;
}

template<class T>
int LinkedList<T>::GetSize() { return size; }

template<class T>
int LinkedList<T>::AddNode(T _data)
{
	Node<T>* newNode = new Node<T>(_data);
	newNode->next = head;
	head = newNode;
	isSort = false;
	size++;
	return 1;
}

template<class T>
int LinkedList<T>::InsertOrder(T _data) { return1; }

template<class T>
int LinkedList<T>::DeleteNode(Node<T>*& prevNode, Node<T>*& currNode)// currNode : Node need to be deleted;
{
	if (prevNode == currNode && prevNode == head)
	{
		if (head == NULL || len == 0)
			return 0;
		Node<T>* p = head;
		head = p->next;
		delete p;
		size--;

		prevNode = head;
		return 1;
	}
	else
	{
		size--;
		prevNode->next = currNode->next;
		delete currNode;
		return 1;
	}
}

template<class T>
template<typename S>
int LinkedList<T>::DeleteBase(S cmp, bool delAll)
{
	int count = 0;
	Node<T>* loop = head;
	Node<T>* curr = head;
	Node<T>* prev = head;
	while (loop != NULL)
	{
		if (cmp(loop->data))
		{
			if (!clearAll)
				return DeleteNode(prev, curr);
			else
			{
				count += DeleteNode(prev, curr);
				loop = prev;
			}
			curr = loop;
		}
		else
		{
			prev = loop;
			loop = loop->next;
			curr = loop;
		}

	}
	return count;
}

template<class T>
template<typename S>
Node<T>* LinkedList<T>::FindElement(S cmp)
{
	Node<T>* loop = head;
	for (int i = 0; i < ll.size; i++)
	{
		if (cmp(loop->data)) return loop;
		loop = loop->next;
	}

	return nullptr;
}

#pragma region SortAlgo
template<class T>
Node<T>* LinkedList<T>::midNode(Node<T>* head)
{
	Node<T>* slow = head;
	Node<T>* fast = head->next;
	while (slow != NULL && (fast != NULL && fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

template<class T>
Node<T>* LinkedList<T>::Merge(Node<T>*& head1, Node<T>*& head2, bool(*cmp)(T, T))
{
	Node<T>* tempHead;
	Node<T>* loop = new Node<T>(head1 != NULL ? head1->data : head2->data);
	tempHead = loop;
	while (head1 != NULL && head2 != NULL)
	{
		if (cmp(head1->data, head2->data))
		{
			loop->next = head1;
			head1 = head1->next;
		}
		else
		{
			loop->next = head2;
			head2 = head2->next;
		}
		loop = loop->next;
	}
	while (head1 != NULL)
	{
		loop->next = head1;
		head1 = head1->next;
		loop = loop->next;
	}
	while (head2 != NULL)
	{
		loop->next = head2;
		head2 = head2->next;
		loop = loop->next;
	}

	return tempHead->next;
}

template<class T>
Node<T>* LinkedList<T>::MergeSort(Node<T>*& head, bool (*cmp)(T, T))
{
	if (head == NULL || head->next == NULL)
		return head;

	Node<T>* mid = midNode(head);
	Node<T>* head2 = mid->next;
	mid->next = NULL;

	head = MergeSort(head, cmp);
	head2 = MergeSort(head2, cmp);

	Node<T>* finalRes = Merge(head, head2, cmp);
	return finalRes;
}
#pragma endregion


template<class T>
void LinkedList<T>::Sort(bool (*cmp)(T,T))
{
	head = MergeSort(head, cmp);
}
#pragma endregion
