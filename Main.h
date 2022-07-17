#include <string>
#include "MemoryTrack.h"


#ifndef LINKED_LIST
#define LINKED_LIST

struct Node
{
	char data;
	Node* next;

	Node(char val)
	{
		data = val;
		next = NULL;
	}

	~Node()
	{
		delete next;
	}
};

struct LinkedList
{
	Node* head;
	//std::shared_ptr<Node> head;
	int count;

	LinkedList()
	{
		head = NULL;
		//head = std::make_shared<Node>(NULL);
		count = 0;
	}

//*
	//Takes nodePtr
	void Push(Node* nodeToAdd)
	{
		if (head == NULL)
		{
			//If there is no memory allocated for head
			//Make head the new node
			head = nodeToAdd;
			count++; //1
			return;
		}

		//Start looking from head till reaching the last node
		Node* runner = head;
		
		while (runner->next != NULL)
		{
			runner = runner->next;
		}

		runner->next = nodeToAdd;
		count++;
	}
//*/

	Node* FindNode(int n)
	{
		Node* runner = head;
		int tempCount = 1;

		while (tempCount < n)
		{
			runner = runner->next;
			tempCount++;
		}

		return runner;
	}

	LinkedList* SubList(int n, int m)
	{
		LinkedList* tempList = new LinkedList();

		if (n > count || n <= 0)
		{
			std::cout << "[ERROR]: n is out of bounds!" << std::endl;
			return tempList;
		}
		else if (n-1 + m > count)
		{
			std::cout << "[ERROR]: n+m is out of bounds!" << std::endl;
			return tempList;
		}

		Node* tempNode = FindNode(n);
		int tempCount = 1;

		while (tempCount <= m)
		{
			Node* newNodePtr = new Node(tempNode->data);
			tempList->Push(newNodePtr);
			tempNode = tempNode->next;
			
			tempCount++;
		}

		delete tempNode;
		return tempList;
	}

	void Print()
	{
		Node* runner = head;
		
		while (runner->next != NULL)
		{
			std::cout << runner->data << ", ";
			runner = runner->next;
		}

		std::cout << runner->data << std::endl;
	}
};

#endif