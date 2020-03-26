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
	Node* Locations[27];
public:
	MyList();
	void insert(const ListElement& ,int);
	void remove(const ListElement& );
	void FileRead(std::string );
	void SetUpList();
	/////// Assignment Methods
	void wordCount();
	void distWords();
	void charCount();
	/////////////
	void Execute(std::string );
	void Check(ListElement );
};
