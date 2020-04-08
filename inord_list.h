#include <iostream>
#include <fstream>
#include <sstream>

typedef std::string ListElement;

struct Node
{
	ListElement data;
	int LineNum;
	int NumOfOcc=1;
	Node* link;
};

class MyList
{
private:
	int NumOfChars;
	int NumOfElem;
	Node* head;
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
	void frequentWord();
	/////////////
	void Execute(std::string );
	void Check(ListElement );
};



class UselessFuncts
{
public:
	static void str_low(std::string& );
	static void str_replace(std::string& ,const std::string& );
};