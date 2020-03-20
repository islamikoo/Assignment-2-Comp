#include <iostream>

using namespace std;

typedef string ListElement;

struct Node
{
	ListElement data;
	Node* link;
};

class MyList
{
private:
	int NumOfElem;
	Node* head;
	Node* tail;
public:
	MyList();
	void insert(const ListElement& e);
	void remove(const ListElement& e);
	void PrintList();
	int GetNumOfElem();
};
