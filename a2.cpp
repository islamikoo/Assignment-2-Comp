#include <iostream>
#include <string>
#include "inord_list.h"

using namespace std;

int main(int argc , char** argv)
{
	MyList List;
	List.FileRead("test.txt");
	//List.PrintList();
	List.test();
	return 0;
}