#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <stddef.h>
#define DEF_SIZE 20

class Array {
private:
    int* buffer = NULL;
    int size;
public:
    Array( unsigned int size = DEF_SIZE );
    Array( const int* arr, unsigned int size );

    const int* getBuffer() const;
    int getSize() const;

    const Array& operator=( const Array& );

    int& operator[](int index);
    int operator[](int index) const;

    ~Array();
};

#endif
