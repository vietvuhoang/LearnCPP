#ifndef _KING_HPP_
#define _KING_HPP_

#include "piece.hpp"

class King : public Piece {

public: 

    King(const Position &pos, ChessSet party);
    ~King();

    std::list<Position> collectAvailablePositions();
    std::string getName();

};


#endif