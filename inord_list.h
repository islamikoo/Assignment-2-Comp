#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>

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
	int NumOfChars;
	int NumOfSpaces;
	int TotNumOfChars;
	int NumOfElem;
	int NumOfCarriages;
	Node* head;
	Node* tail;
public:
	MyList();
	void insert(const ListElement& ,int);
	void remove(const ListElement& );
	void PrintList();
	int GetNumOfElem();
	int GetNumOfChars();
	int GetNumOfSpaces();
	int GetTotNumOfChars();
	int GetNumOfCarriages();
	void FileRead(std::string );
};
