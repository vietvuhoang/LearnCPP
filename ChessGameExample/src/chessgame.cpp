#define BUFF_SIZE 10
#include <iostream>
#include <stdexcept>
#include <memory>
#include "position.hpp"

using namespace std;

void print ( shared_ptr<const Position> p) {

	cout << "POS " << p->toString() << endl;

}

void move( shared_ptr<Position> p ) {
	p->set('B', 5 );
}

int main(int argc, const char *argv[])
{
	shared_ptr<Position> p2 = NULL;

	try
	{
		shared_ptr<Position> p(new Position('A', 1 ));

		move( p );

		print(p);

		p2 = p;

		p = NULL;

		cout << "Good Bye" << endl;
	}
	catch (const exception &ex)
	{
		cerr << "ERROR : " << ex.what() << endl;
	}

	return 0;
}
