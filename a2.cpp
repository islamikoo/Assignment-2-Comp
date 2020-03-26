#include <iostream>
#include <string>
#include "inord_list.h"

using namespace std;


int main(int argc , char** argv)
{
	if(argc != 3)
	{
		cout << "Incorrect number of arguments" << endl;
		return 0;
	}
	MyList DFile ;
	DFile.FileRead(argv[1]);
	DFile.Execute(argv[2]);
	
	return 0;
}
