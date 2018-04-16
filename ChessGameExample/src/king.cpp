#include "king.hpp"
#include "board.hpp"
#include "move.hpp"
using namespace std;

King::King(const Position &pos, ChessSet party) : Piece( pos, party ) {

}

King::~King() {

}

void King::collectAvailablePositions( list<Position>& positionList ) const {
    
    Board* board = Board::getInstance();

    list< shared_ptr<IMove> > moveList;

    moveList.push_back( shared_ptr<IMove>( new MoveUp( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveDown( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveLeft( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveRight( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveUpRight( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveUpLeft( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveDownRight( this->getPosition(), 1) ));
    moveList.push_back( shared_ptr<IMove>( new MoveDownLeft( this->getPosition(), 1) ));

    for (list<shared_ptr<IMove>>::iterator itr = moveList.begin(); itr != moveList.end(); itr++)
    {
        try
        {
            shared_ptr<IMove> pMove = *itr;

            Position pos = pMove->move();

            shared_ptr<const Piece> piece = board->getPiece( pos );

            if ( piece->getParty() == this->getParty() ) throw InvalidMovingStepException();

            positionList.push_back(pos);
        }
        catch (const InvalidMovingStepException &ex)
        {
            continue;
        }
    }
    
}

string King::getName() const {
    return "King";
}