#include "inord_list.h"

using namespace std;

MyList::MyList()
{
	head = NULL;
	tail = NULL;
	NumOfElem = 0;
}

void MyList::insert(const ListElement& e)
{
	Node* NewNode = new Node;
	NewNode->data = e;
	if (head == NULL || e <= head->data )
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL && e > temp->link->data)
			temp = temp->link;
		NewNode->link = temp->link;
		temp->link = NewNode;
	}
	NumOfElem++;
}

void MyList::remove(const ListElement& e)
{
	Node* NewNode = new Node;
	NewNode->data = e;
	if (head == NULL)
	{
		cout << "ERROR List is empty" << endl;
		exit(0);
	}
	else if (head->data == e)
	{
		head = head->link;
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL)
		{
			if (temp->link->data == e)
			{
				temp->link = temp->link->link;
				break;
			}
			temp = temp->link;
		}
	}
	NumOfElem--;
}

int MyList::GetNumOfElem()
{
	return NumOfElem;
}

void MyList::PrintList()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
}