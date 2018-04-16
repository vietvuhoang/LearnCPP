#include "king.hpp"
#include "board.hpp"

King::King(const Position &pos, ChessSet party) : Piece( pos, party ) {

}

King::~King() {

}

std::list<Position> collectAvailablePositions() {
    std::list<Position> list;

    Board* board = Board::getInstance();

    return list;
}

std::string getName() {
    return "King";
}