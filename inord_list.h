#include <iostream>
#include <fstream>
#include <sstream>

typedef std::string ListElement;

struct Node
{
	ListElement data;
	std::string LineNum = "";
	int NumOfOcc=1;
	Node* link;
};

class MyList
{
private:
	int NumOfChars;
	int NumOfElem;
	Node* head;
public:
	MyList();
	void insert(const ListElement& ,int);
	void FileRead(std::string );
	/////// Assignment Methods
	void wordCount();
	void distWords();
	void charCount();
	void frequentWord();
	void countWord(ListElement&);
	void starting(ListElement&);
	void containing(ListElement&);
	void search(ListElement&);
	/////////////
	void Execute(std::string );
	void Check(std::string );
};



class UselessFuncts
{
public:
	static void str_low(std::string& );
	static void str_replace(std::string& ,const std::string& );
	static int str_numofchar(const std::string&, const char&);
};