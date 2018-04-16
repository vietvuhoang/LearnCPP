#define BUFF_SIZE 10
#include <iostream>
#include <stdexcept>

using namespace std;

class Piece {

protected: 

    char file;
    unsigned short rank;

public: 

    Piece( char file, unsigned short rank) : file( file), rank(rank) {
    }

    virtual void move() {
        cout << "Piece Move" << endl;
    }

    ~Piece() {
        cout << "Piece dead" << endl;
    }
};

class Knight : public Piece {
public:
    Knight( char file, unsigned short rank) : Piece( file, rank ) {
    }

    void move() {
        cout << "Knight Move" << endl;
    }

    ~Knight() {
        cout << "Knight dead" << endl;
    }
};

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

int main(int argc, const char *argv[])
{

	try
	{
        example2_test_virtual_method();
        example2_test_virtual_destructor();		
	}
	catch (const exception &ex)
	{
		cerr << "ERROR : " << ex.what() << endl;
	}

	return 0;
}
