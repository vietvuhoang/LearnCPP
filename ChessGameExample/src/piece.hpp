#ifndef _PIECE_HPP_
#define _PIECE_HPP_

#include "position.hpp"
#include <list>

enum ChessSet
{
    WHITE,
    BLACK
};

class Piece
{

  protected:
    Position position;
    ChessSet party;

  public:
    Piece(const Position &pos, ChessSet party);
    virtual ~Piece();

    const Position &getPosition() const;
    const ChessSet &getParty() const;

    virtual std::list<Position> collectAvailablePositions() const = 0;
    virtual std::string getName() const = 0;

    void set( const Position& newPos );
    std::string toString() const;
};

#endif
