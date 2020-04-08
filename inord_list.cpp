#include "inord_list.h"
#include <string.h>

using namespace std;

/////////////////////////////Some Utility functions///////////////////////////////////////
void UselessFuncts::str_low(string &word)
{
	for (char& x : word)
		x = tolower(int(x));
}

void UselessFuncts::str_replace(string &word,const string &chars)
{
	for (char& x : word)
		if (chars.find(x) != std::string::npos)
			x = ' ';
}

///////////////////////////////////////////////////////////////////////

MyList::MyList()
{
	head = NULL;
	NumOfElem = 0;
	NumOfChars=0;
	for(int i=0; i<27 ;i++)
		Locations[i] = NULL;
}

///////////////////////////////////////////////////////////////////////

void MyList::insert(const ListElement& e , int x)
{
	Node* NewNode = new Node;
	NewNode->data = e;
	NewNode->LineNum = x;
	if (head == NULL || e <= head->data )
	{
		if(head != NULL && e==head->data)
			head->NumOfOcc++;
		else
		{
			NewNode->link = head;
			head = NewNode;
		}
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL && e > temp->link->data)
			temp = temp->link;
		if(temp->link != NULL && e==temp->link->data)
			temp->link->NumOfOcc++;
		else
		{
			NewNode->link = temp->link;
			temp->link = NewNode;
		}
	}
	NumOfElem++;
}

///////////////////////////////////////////////////////////////////////

void MyList::FileRead(string FileName)
{
	string line;
	string chars = ",.\t";
	int i=1;
    ifstream myfile;
    myfile.open(FileName);
   if(!myfile.is_open())
   {
      perror("File doesn't exist !!");
      exit(EXIT_FAILURE);
   }
    while(getline(myfile, line))
	{
		UselessFuncts::str_replace(line, chars);
		NumOfChars += line.length() + 1 ;
		istringstream ss(line);
		do
		{
			string tmp;
			if(!(ss >> tmp))
				break;
			UselessFuncts::str_low(tmp);
			this->insert(tmp,i);
		} while(ss);
		i++;
    }
	myfile.close();
}

///////////////////////////////////////////////////////////////////////

void MyList::Execute(string FileName)
{
	ifstream myfile;
	string line;
    myfile.open(FileName);
   if(!myfile.is_open())
   {
      perror("File doesn't exist !!");
      exit(EXIT_FAILURE);
   }
   
   while(getline(myfile, line))
	   Check(line);
   myfile.close();
}

///////////////////////////////////////////////////////////////////////

void MyList::Check(string Command)
{
	if(Command == "wordCount")
		wordCount();
	else if(Command == "distWords")
		distWords();
	else if(Command == "charCount")
		charCount();
	else
		cout << "Undefined command" << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::wordCount()
{
	cout << NumOfElem << " words" << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::distWords()
{
	Node *temp = head;
	int i=0;
	while (temp != NULL)
	{
		i++;
		temp = temp->link;
	}
	cout << i << " distinct words" << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::charCount()
{
	cout << NumOfChars-1 << " characters" << endl;
}

///////////////////////////////////////////////////////////////////////