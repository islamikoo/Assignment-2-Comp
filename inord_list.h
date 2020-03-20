#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

typedef std::string ListElement;

struct Node
{
	ListElement data;
	int LineNum;
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
	void insert(const ListElement& ,int);
	void remove(const ListElement& );
	void PrintList();
	int GetNumOfElem();
	void FileRead(std::string );
};
