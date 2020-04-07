#include "inord_list.h"

using namespace std;

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
	string chars = ",;:'`&.[]{}()";
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
		line.erase(remove_if(line.begin() , line.end() , [&chars](const char& c) {
			return chars.find(c) != string::npos ;}), line.end());
		NumOfChars += line.length() + 1 ;
		istringstream ss(line);
		do
		{
			string tmp;
			if(!(ss >> tmp))
				break;
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
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