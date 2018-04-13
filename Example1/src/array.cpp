#include "array.hpp"
#include <cstring>
#include <stdexcept>

#define ALLOC_BUFFER( buf, size ) {buf = new int[size]; if (buf==NULL) throw bad_alloc();} 
#define RELEASE(buf) delete buf;

using namespace std;

Array::Array( unsigned int size ) : size( size ) {

    if ( size == 0 ) {
        throw invalid_argument("Invalid Array Size");
    }

    ALLOC_BUFFER( this->buffer, size );
}

Array::Array( const int* arr, unsigned int size ): size(size) {
    
    if ( arr == NULL || size == 0 ) {
        throw invalid_argument("Invalid Array Size");
    }

    ALLOC_BUFFER( this->buffer, size );

    memcpy( this->buffer, arr, size * sizeof(int));

}

Array::~Array() {
    if ( this->buffer == NULL ) return;
    delete this->buffer;
}

const Array& Array::operator=( const Array& arr) {

    if ( arr.getBuffer() == NULL || arr.getSize() == 0 ) {
        throw invalid_argument("Invalid Array Size");
    }

    int* buff = NULL;
    
    ALLOC_BUFFER( buff, arr.getSize() );

    memcpy( buff, arr.getBuffer(), arr.getSize() * sizeof(int));

    delete this->buffer;

    this->buffer = buff;
    this->size = arr.getSize();

    return *this;
}

const int* Array::getBuffer() const {
    return buffer;
}

int Array::getSize() const {
    return size;
}

int& Array::operator[](int index) {

    if ( index >= this->size ) throw out_of_range("Invalid index");

    return this->buffer[index];
}

int Array::operator[](int index) const {
    return this->buffer[index];
}
