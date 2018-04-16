#ifndef _KING_HPP_
#define _KING_HPP_

#include "piece.hpp"

class King : public Piece {

public: 

    King(const Position &pos, ChessSet party);
    ~King();

    void collectAvailablePositions( std::list<Position>& positionList ) const;
    std::string getName() const;

};


#endif