#pragma once
#include <iostream>
using namespace std;

template <class Type>
class clsDblLinkedList
{
public:

	class Node
	{
	public:
		Type value;
		Node* next;
		Node* prev;
	};

	

private:
	Node* _head = nullptr;
	int _Size = 0;



public:

	

	void InsertAtBeginning(Type value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->prev = nullptr;
		new_node->next = _head;

		if (_head != nullptr)
		{
			_head->prev = new_node;
		}

		
		_head = new_node;
		_Size++;

	}

	void InsertAfter(Node * Current ,Type value)
	{
		if (_head == nullptr || Current==nullptr)
			return;

		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = Current->next;
		new_node->prev = Current;

		if (Current->next != nullptr)
		{
			Current->next->prev = new_node;
		}


		Current->next = new_node;
		_Size++;

	}

	void InsertAtEnd(Type value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = nullptr;

		if (_head == nullptr)
		{
			_head = new_node;
			new_node->prev = nullptr;
			_Size++;
			return;
		}

		Node* LastNode = _head;

		while (LastNode->next != nullptr)
		{
			LastNode = LastNode->next;
		}

		new_node->prev = LastNode;
		LastNode->next = new_node;
		_Size++;

	}
	

	void PrintList()
	{
		
		Node* CurrentNode = _head;
		while (CurrentNode != nullptr)
		{
			cout << CurrentNode->value << " ";
			CurrentNode = CurrentNode->next;

		}
		cout << "\n";
	}

	Node * Find(Type value)
	{
		Node* CurrentNode = _head;

		while (CurrentNode != nullptr)
		{
			if (CurrentNode->value == value)
				return CurrentNode;

			CurrentNode = CurrentNode->next;
		}
		return nullptr;
	}


	void DeletFirstNode()
	{
		if (_head == nullptr)
			return;


		Node* tempNode = _head;
		_head = tempNode->next;

		if (_head != nullptr)
		{
			_head->prev = nullptr;
		}

		delete tempNode;
		_Size--;

	}

	void DeleteLastNode()
	{
		if (_head == nullptr)
			return;

		if (_head->next == nullptr)
		{
			delete _head;
			_head = nullptr;
			_Size--;
			return;
		}

		Node* LastNode = _head;

		while (LastNode->next != nullptr)
		{
			LastNode = LastNode->next;
		}

		if (LastNode->prev != nullptr)
		{
			LastNode->prev->next = nullptr;
		}

		delete LastNode;
		_Size--;
	}

	void DeleteNode(Node * NodeToDelete)
	{
		if (_head == nullptr || NodeToDelete == nullptr)
			return;

		if (_head == NodeToDelete)
		{
			_head = NodeToDelete->next;
		}

		if (NodeToDelete->next != nullptr)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != nullptr)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		_Size--;

	}

	int Size()
	{
		return _Size;
	}

	void Clear()
	{
		
		while (_Size > 0)
		{
			DeletFirstNode();
		}
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Reverse()
	{
		if (_head == nullptr || _head->next == nullptr)
			return;

		Node* curr = _head;
		Node* temp = nullptr;

		while (curr != nullptr)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}

		if (temp != nullptr)
		{
			temp = temp->prev;
			_head = temp;
		}
	}

	Node* GetNode(short IndexOfNode)
	{
		int Counter = 0;

		if (IndexOfNode > _Size - 1 || IndexOfNode < 0)
			return nullptr;

		Node* Current = _head;

		while (Current != nullptr && (Current->next != nullptr))
		{
			if (Counter == IndexOfNode)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	Type GetItem(short IndexOfNode)
	{
		Node* ElementNode = GetNode(IndexOfNode);

		return (ElementNode == nullptr) ? 0 : ElementNode->value;
	}

	bool UpdateItem(short IndexOfNode, Type value)
	{
		Node* NodeToUpdate = GetNode(IndexOfNode);
		if (NodeToUpdate != nullptr)
		{
			NodeToUpdate->value = value;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int IndexOfNode, Type value)
	{
		Node* NodeToInsertAfter = GetNode(IndexOfNode);

		if (NodeToInsertAfter != nullptr)
		{
			InsertAfter(NodeToInsertAfter, value);
			return true;
		}
		else
			return false;
	}

	



};


