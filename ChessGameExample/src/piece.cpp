#include "piece.hpp"

Piece::Piece(const Position &pos, ChessSet party) : position(pos), party(party)
{
}

Piece::~Piece()
{
}

const Position &Piece::getPosition() const { 
    return position; 
}

const ChessSet &Piece::getParty() const { 
    return party; 
}

void Piece::set(const Position &newPos)
{
    this->position = newPos;
}

std::string Piece::toString() const {
    std::ostringstream stringStream;

    stringStream << (this->party == WHITE ? "White" : "Black") 
                << " " << this->getName() 
                << " " << this->position.toString();

    return stringStream.str();
}