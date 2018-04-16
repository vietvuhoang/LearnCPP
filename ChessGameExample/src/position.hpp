#ifndef _POSITION_HPP_
#include <sstream>
#include <stdexcept>
#include <iostream>

#define VALIDATE_CRANK(rank) { if ( rank < 1 || rank > 8 ) throw std::invalid_argument("Invalid Rank");}
#define VALIDATE_CFILE(rank) { if ( file < 'A' || file > 'H') throw std::invalid_argument("Invalid File");}

enum CFile
{
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H'
};

enum CRank
{
    R1 = 1,
    R2 = 2,
    R3 = 3,
    R4 = 4,
    R5 = 5,
    R6 = 6,
    R7 = 7,
    R8 = 8
};

class Position
{

  private:
    CRank rank;
    CFile file;

  public:
    Position(const CFile &file, const CRank &rank) : rank(rank), file(file)
    {
    }

    Position(const CFile &file, unsigned char rank) 
    {
        this->set( file, rank );
    }

    Position(unsigned char file, const CRank &rank) 
    {
        this->set( file, rank );
    }

    Position(unsigned char file, unsigned char rank) 
    {
        this->set( file, rank );
    }

    Position(const Position &pos) : rank(pos.rank), file(pos.file)
    {
    }

    ~Position() {
    }

    const Position &operator=(const Position &pos)
    {
        this->rank = pos.rank;
        this->file = pos.file;
        return *this;
    }

    bool operator==(const Position& pos ) const {
        return this->rank == pos.getRank() && this->file == pos.getFile();
    }

    const CRank &getRank() const
    {
        return rank;
    }

    const CFile &getFile() const
    {
        return file;
    }

    std::string toString() const 
    {
        std::ostringstream stringStream;
        stringStream << (char)file << rank;
        return stringStream.str();
    }

    void set( const CFile& file, const CRank& rank)
    {
        this->rank = rank;
        this->file = file;
    }

    void set(const CFile& file, unsigned char rank)
    {
        VALIDATE_CRANK(rank);
        this->rank = CRank(rank);
        this->file = file;
    }

    void set( unsigned char file, const CRank &rank)
    {
        VALIDATE_CFILE(file);        
        this->rank = rank;
        this->file = CFile(file);
    }

    void set( unsigned char file, unsigned char rank)
    {
        VALIDATE_CRANK(rank);
        VALIDATE_CFILE(file);
        this->rank = CRank(rank);
        this->file = CFile(file);
    }
};

inline CRank add(CRank rank, unsigned int step)
{
    unsigned int num = rank + step;
    if (num > 8)
        throw std::invalid_argument("Invalid moving steps");
    return CRank(num);
}

inline CRank minus(CRank rank, unsigned int step)
{
    if (rank <= step)
        throw std::invalid_argument("Invalid moving steps");
    return CRank(rank - step);
}

inline CFile add(CFile file, unsigned int step)
{
    unsigned int c = file + step;
    if (c > 'H')
        throw std::invalid_argument("Invalid moving steps");
    return CFile(c);
}

inline CFile minus(CFile file, unsigned int step)
{
    if (step > 8 || file - step < 'A')
        throw std::invalid_argument("Invalid moving steps");
    return CFile(file - step);
}

#endif
