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

int UselessFuncts::str_numofchar(const string &word,const char &character)
{
	int i = 0;
	for (const char& x : word)
		if (x == character)
			i++;
	return i;
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

	int i = 0;
	int length = UselessFuncts::str_numofchar(Command,' ') + 1;
	string* arr = new string[length];
	istringstream ss(Command);
	do
	{
		string tmp;
		if (!(ss >> tmp))
			break;
		arr[i] = tmp;
		i++;
	} while (ss);
		if (arr[0] == "wordCount")
			wordCount();
		else if (arr[0] == "distWords")
			distWords();
		else if (arr[0] == "charCount")
			charCount();
		else if (arr[0] == "frequentWord")
			frequentWord();
		else if (arr[0] == "countWord")
			countWord(arr[1]);
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
	cout << NumOfChars << " characters" << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::frequentWord()
{
	Node* temp = head;
	int max = temp->NumOfOcc;
	while (temp->link != NULL)
	{
		if (max < temp->link->NumOfOcc)
			max = temp->link->NumOfOcc;
		temp = temp->link;
	}
	temp = head;
	cout << "Most frequent word is: ";
	while (temp != NULL)
	{
		if(temp->NumOfOcc == max && temp->data != "a" && temp->data != "an" && temp->data != "the" && temp->data != "in" && temp->data != "on" && temp->data != "of" && temp->data != "and" && temp->data != "is" && temp->data != "are")
			cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::countWord(const ListElement& word)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == word)
			break;
		temp = temp->link;
	}
	cout << temp->data << " is repeated " << temp->NumOfOcc << " times" << endl;
}