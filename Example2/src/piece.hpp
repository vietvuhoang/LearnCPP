#ifndef _PIECE_HPP_
#define _PIECE_HPP_
#include <iostream>

class Piece {

protected: 

    char file;
    unsigned short rank;

public: 

    Piece( char file, unsigned short rank) : file( file), rank(rank) {
    }

    virtual void move() {
        std::cout << "Piece Move" << std::endl;
    }

    ~Piece() {
        std::cout << "Piece dead" << std::endl;
    }
};

class Knight : public Piece {
public:
    Knight( char file, unsigned short rank) : Piece( file, rank ) {
    }

    void move() {
        std::cout << "Knight Move" << std::endl;
    }

    ~Knight() {
        std::cout << "Knight dead" << std::endl;
    }
};

#endif 
