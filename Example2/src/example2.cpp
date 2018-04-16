#define BUFF_SIZE 10
#include <iostream>
#include <stdexcept>
#include "piece.hpp"
#include "imove.hpp"

using namespace std;

void example2_test_virtual_method() {
    cout << "example2_test_virtual_method" << endl;

    Knight knight('A', 1);

    knight.move();

}

void example2_test_virtual_destructor() {
    cout << "example2_test_virtual_destructor" << endl;

    Piece* piece = new Knight('A', 1 );

    piece->move();

    delete piece;
}

void example2_check_interface() {

    cout << "example2_check_interface" << endl;

    IMove* move = createMover();

    move->move();
    
}

int main(int argc, const char *argv[])
{

	try
	{
        example2_test_virtual_method();
        cout << endl;
        example2_test_virtual_destructor();		
        cout << endl;
        example2_check_interface();
        cout << endl;
	}
	catch (const exception &ex)
	{
		cerr << "ERROR : " << ex.what() << endl;
	}

	return 0;
}
