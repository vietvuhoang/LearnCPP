#ifndef _MOVE_HPP_
#define _MOVE_HPP_

#include "position.hpp"

class IMove
{
  public:
    virtual Position move() const = 0;
};

class StepMove : public IMove
{
  protected:
    Position pos;
    unsigned int step;

  public:
    StepMove(const Position &pos, unsigned int step) : pos(pos), step(step)
    {
    }
};

class MoveUp : public StepMove
{
  public:
    MoveUp(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }

    Position move() const 
    {
        return Position(add(pos.getFile(), step), pos.getRank());
    }
};

class MoveDown : public StepMove
{
  public:
    MoveDown(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }

    Position move() const 
    {
        return Position(minus(pos.getFile(), step), pos.getRank());
    }
};

class MoveRight : public StepMove
{
  public:
    MoveRight(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }

    Position move() const 
    {
        return Position(pos.getFile(), add(pos.getRank(), step));
    }
};

class MoveLeft : public StepMove
{
  public:
    MoveLeft(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }

    Position move() const 
    {
        return Position(pos.getFile(), minus(pos.getRank(), step));
    }
};

class MoveUpRight : public StepMove
{
  public:
    MoveUpRight(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }

    Position move() const 
    {
        return Position(add(pos.getFile(), step), add(pos.getRank(), step));
    }
};

class MoveUpLeft : public StepMove
{
  public:
    MoveUpLeft(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }
    Position move() const 
    {
        return Position(add(pos.getFile(), step), minus(pos.getRank(), step));
    }
};

class MoveDownRight : public StepMove
{
  public:
    MoveDownRight(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }
    Position move() const 
    {
        return Position(minus(pos.getFile(), step), add(pos.getRank(), step));
    }
};

class MoveDownLeft : public StepMove
{
  public:
    MoveDownLeft(const Position &pos, unsigned int step) : StepMove(pos, step)
    {
    }
    Position move() const 
    {
        return Position(minus(pos.getFile(), step), minus(pos.getRank(), step));
    }
};

#endif // _MOVE_HPP_