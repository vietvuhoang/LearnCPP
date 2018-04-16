#ifndef _BOARD_HPP_
#define _BOARD_HPP_
#include <memory>
#include "appexception.hpp"
#include "piece.hpp"

#define BOARD_COL 8
#define BOARD_ROW 8

class Board
{

  private:
    std::shared_ptr<Piece> mainBoard[BOARD_COL * BOARD_ROW];

    void verifyNewPos( std::shared_ptr<const Piece>, const Position &des ) const;
    std::shared_ptr<Piece>& getPiece(const Position &pos);

  public:
    Board();
    ~Board();

    void add(std::shared_ptr<Piece> piece);
    void add(const Piece& piece);
    void remove(std::shared_ptr<const Piece> piece);
    void moveAPiece(const Position &fromPos, const Position &toPos);

    std::shared_ptr<const Piece> getPiece(const Position &pos) const;    

    static Board *getInstance();
};

class PositionBusyException : public AppException
{

  public:
    PositionBusyException(const std::string &message) : AppException(message)
    {
    }

    virtual ~PositionBusyException() throw()
    {
    }
};

class InvalidPositionOnBoardException : public AppException
{

  public:
    InvalidPositionOnBoardException(const std::string &message) : AppException(message)
    {
    }

    virtual ~InvalidPositionOnBoardException() throw()
    {
    }
};

class NonManagedPieceException : public AppException
{

  public:
    NonManagedPieceException(const std::string &message) : AppException(message)
    {
    }

    virtual ~NonManagedPieceException() throw()
    {
    }
};

#endif
