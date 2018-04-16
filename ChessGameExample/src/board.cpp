#include "board.hpp"

#define BOARD_POS( fileIndex, rankIndex) (fileIndex * 8 + rankIndex)
#define FILE_TO_INDEX(file) (file - 'A')
#define RANK_TO_INDEX(rank) (rank - 1)

using namespace std;

Board::Board() {
    for ( int i = 0; i < BOARD_COL * BOARD_ROW; i++) {

    }
}

Board::~Board() {

}

std::shared_ptr<Piece>& Board::getPiece(const Position &pos) {
    int fileIndex = FILE_TO_INDEX( pos.getFile());
    int rankIndex = RANK_TO_INDEX( pos.getRank());

    return this->mainBoard[ BOARD_POS( fileIndex, rankIndex ) ];
}

void Board::add( shared_ptr<Piece> piece ) {

    shared_ptr<Piece>& p = this->getPiece( piece->getPosition() );
    
    if ( p != NULL ) {
        throw PositionBusyException( piece->getPosition().toString() + " is busy" );
    }

    p = piece;
}

void Board::remove( shared_ptr<const Piece> piece ) {
    int fileIndex = FILE_TO_INDEX(piece->getPosition().getFile());
    int rankIndex = RANK_TO_INDEX(piece->getPosition().getRank());

    shared_ptr<Piece>& p = this->mainBoard[ BOARD_POS( fileIndex, rankIndex ) ];
    
    if ( p == NULL ) {
        throw NonManagedPieceException( piece->toString() + " is not managed" );
    }

    p = NULL;
}

void Board::verifyNewPos( std::shared_ptr<const Piece> piece, const Position &des ) const {
    
    list<Position> listPos = piece->collectAvailablePositions();

    for ( list<Position>::iterator itr = listPos.begin(); itr != listPos.end(); itr++ ) {
        if ( des == *itr) return;
    }

    throw InvalidPositionOnBoardException( string("Invalid Destination ") + des.toString());

}

void Board::moveAPiece( const Position& fromPos, const Position& toPos ) {

    int fileIndex = FILE_TO_INDEX(fromPos.getFile());
    int rankIndex = RANK_TO_INDEX(fromPos.getRank());

    // Verify from Pos
    shared_ptr<Piece>& from = this->getPiece( fromPos );

    if ( from == NULL ) {
        throw InvalidPositionOnBoardException( fromPos.toString() + " is blank" );
    }

    //Verify to Pos
    shared_ptr<Piece>& to = this->getPiece( toPos );

    if ( to != NULL ) {
        throw PositionBusyException( toPos.toString() + " is busy" );
    }

    this->verifyNewPos( from, toPos );

    from->set( toPos );
    to = from;
    from = NULL;
}

shared_ptr<const Piece> Board::getPiece( const Position& pos ) const {
    int fileIndex = FILE_TO_INDEX(pos.getFile());
    int rankIndex = RANK_TO_INDEX(pos.getRank());
    return this->mainBoard[ BOARD_POS( fileIndex, rankIndex ) ];
}

Board* Board::getInstance() {

    static Board* motherBoard = NULL;

    if ( motherBoard == NULL ) motherBoard = new Board();

    return motherBoard;
}
