#include <iostream>
#include <string>
#include "inord_list.h"

using namespace std;

int main(int argc , char** argv)
{
	string tmp;
	MyList List;
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		List.insert(tmp);
	}
	List.PrintList();
	cout << "///////////" << endl;
	cin >> tmp;
	List.remove(tmp);
	List.PrintList();
	return 0;
}