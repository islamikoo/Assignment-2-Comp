#include "inord_list.h"

using namespace std;

MyList::MyList()
{
	head = NULL;
	tail = NULL;
	NumOfElem = 0;
	NumOfChars=0;
	NumOfSpaces=0;
	TotNumOfChars=0;
}

///////////////////////////////////////////////////////////////////////

void MyList::insert(const ListElement& e , int x)
{
	Node* NewNode = new Node;
	NewNode->data = e;
	NewNode->LineNum = x;
	if (head == NULL || e <= head->data )
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL && e > temp->link->data)
			temp = temp->link;
		NewNode->link = temp->link;
		temp->link = NewNode;
	}
	NumOfElem++;
}

///////////////////////////////////////////////////////////////////////

void MyList::remove(const ListElement& e)
{
/*	Node* NewNode = new Node;
	NewNode->data = e;*/
	if (head == NULL)
	{
		cout << "ERROR List is empty" << endl;
		exit(0);
	}
	else if (head->data == e)
	{
		head = head->link;
	}
	else
	{
		Node* temp = head;
		while (temp->link != NULL)
		{
			if (temp->link->data == e)
			{
				temp->link = temp->link->link;
				break;
			}
			temp = temp->link;
		}
	}
	NumOfElem--;
}

///////////////////////////////////////////////////////////////////////

void MyList::PrintList()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
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
		NumOfSpaces += count(line.begin(), line.end(), ' ');
		NumOfCarriages += count(line.begin(), line.end(), '\r');
		NumOfChars += (line.length() - (NumOfCarriages + NumOfSpaces));
		istringstream ss(line);
		do
		{
			string tmp;
			if(!(ss >> tmp))
				break;
			this->insert(tmp,i);
		} while(ss);
		i++;
    }
	TotNumOfChars = NumOfCarriages + NumOfChars + NumOfSpaces ;
	myfile.close();
}

///////////////////////////////////////////////////////////////////////

int MyList::GetNumOfChars()
{
	return NumOfChars;
}

///////////////////////////////////////////////////////////////////////

int MyList::GetNumOfSpaces()
{
	return NumOfSpaces;
}

///////////////////////////////////////////////////////////////////////

int MyList::GetTotNumOfChars()
{
	return TotNumOfChars;
}

///////////////////////////////////////////////////////////////////////

int MyList::GetNumOfCarriages()
{
	return NumOfCarriages;
}

///////////////////////////////////////////////////////////////////////

int MyList::GetNumOfElem()
{
	return NumOfElem;
}

///////////////////////////////////////////////////////////////////////