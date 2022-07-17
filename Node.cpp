#include <iostream>

class Node
{
	char data{ NULL };
	Node* next{ NULL };

	Node(char value)
	{
		data = value;
	}
};