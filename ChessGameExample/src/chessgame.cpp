#define BUFF_SIZE 10
#include <iostream>
#include <stdexcept>
#include "position.hpp"

using namespace std;

int main(int argc, const char *argv[])
{

	try
	{
		Position p ( 'A', 1 );

		cout << p.toString() << endl;

		p.set( add( p.getFile(), 3 ), p.getRank() );

		cout << p.toString() << endl;
	}
	catch (const exception &ex)
	{
		cerr << "ERROR : " << ex.what() << endl;
	}

	return 0;
}
