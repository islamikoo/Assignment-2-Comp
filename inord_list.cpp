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

int UselessFuncts::str_numofwords(const string &word)
{
	int i = 0;
	istringstream ss(word);
	do
	{
		string tmp;
		if (!(ss >> tmp))
			break;
		i++;
	} while (ss);
	return i;
}

///////////////////////////////////////////////////////////////////////

MyList::MyList()
{
	head = NULL;
	NumOfElem = 0;
	NumOfChars=0;
}

///////////////////////////////////////////////////////////////////////

void MyList::insert(const ListElement& e, int x)
{
	Node* NewNode = new Node;
	NewNode->data = e;
	if (head == NULL || e <= head->data)
	{
		if (head != NULL && e == head->data)
		{
			head->NumOfOcc++;
			if (head->LineNum.find(to_string(x)) != string::npos)
				goto J1;
			head->LineNum += (" " + to_string(x));
		}
		else
		{
			NewNode->link = head;
			head = NewNode;
			head->LineNum = to_string(x);
		}		
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL && e > temp->link->data)
			temp = temp->link;
		if (temp->link != NULL && e == temp->link->data)
		{
			temp->link->NumOfOcc++;
			if (temp->link->LineNum.find(to_string(x)) != string::npos)
				goto J1;
			temp->link->LineNum += (" " + to_string(x));
		}
		else
		{
			NewNode->link = temp->link;
			NewNode->LineNum = to_string(x);
			temp->link = NewNode;
		}
	}
J1:
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
		cout << "File not found" << endl;
        exit(EXIT_FAILURE);
    }
    char x;
    while (myfile.get(x))
		NumOfChars++;
	myfile.clear();
	myfile.seekg(0, ios::beg);
    while(getline(myfile, line))
	{
		UselessFuncts::str_replace(line, chars);
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
	   cout << "File not found" << endl;
      exit(EXIT_FAILURE);
   }
   
   while (getline(myfile, line))
   {
	   if(line.length() != 0)
		   Check(line);
   }
   myfile.close();
}

///////////////////////////////////////////////////////////////////////

void MyList::Check(string Command)
{

	int i = 0;
	int length = UselessFuncts::str_numofwords(Command);
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
	if (arr[0] == "wordCount" || arr[0] == "distWords" || arr[0] == "charCount" || arr[0] == "frequentWord")
		if (length == 1)
		{
			if (arr[0] == "wordCount")
				wordCount();
			else if (arr[0] == "distWords")
				distWords();
			else if (arr[0] == "charCount")
				charCount();
			else
				frequentWord();
		}
		else
			cout << "Incorrect number of arguments" << endl;
	else if (arr[0] == "countWord" || arr[0] == "starting" || arr[0] == "containing" || arr[0] == "search")
		if (length == 2)
		{
			if (arr[0] == "countWord")
				countWord(arr[1]);
			else if (arr[0] == "starting")
				starting(arr[1]);
			else if (arr[0] == "containing")
				containing(arr[1]);
			else
				search(arr[1]);
		}
		else
			cout << "Incorrect number of arguments" << endl;
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

void MyList::countWord(ListElement& word)
{
	UselessFuncts::str_low(word);
	Node* temp = head;
	int ch = 0;
	while (temp != NULL)
	{
		if (temp->data == word)
		{
			ch = 1;
			break;
		}
		temp = temp->link;
	}
	if(ch==0)
		cout << word << " is repeated " << 0 << " times" << endl;
	else
		cout << temp->data << " is repeated " << temp->NumOfOcc << " times" << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::starting(ListElement& word)
{
	UselessFuncts::str_low(word);
	int length = word.length();
	Node* temp = head;
	int ch = 0;
	while (temp != NULL)
	{
		if (temp->data.substr(0, length) == word)
		{
			ch = 1;
			cout << temp->data << ": " << temp->NumOfOcc << "\t";
		}
		temp = temp->link;
	}
	if (ch == 0)
		cout << "Word not found";
	cout << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::containing(ListElement& word)
{
	UselessFuncts::str_low(word);
	int length = word.length();
	Node* temp = head;
	int ch = 0;
	while (temp != NULL)
	{
		if (temp->data.find(word) != string::npos)
		{
			ch = 1;
			cout << temp->data << ": " << temp->NumOfOcc << "\t";
		}
		temp = temp->link;
	}
	if (ch == 0)
		cout << "Word not found";
	cout << endl;
}

///////////////////////////////////////////////////////////////////////

void MyList::search(ListElement& word)
{
	UselessFuncts::str_low(word);
	int length = word.length();
	Node* temp = head;
	int ch = 0;
	while (temp != NULL)
	{
		if (temp->data.find(word) != string::npos)
		{
			ch = 1;
			cout << temp->data << ":\tlines " << temp->LineNum << "\n";
		}
		temp = temp->link;
	}
	if (ch == 0)
		cout << "Word not found" << endl;	
}
