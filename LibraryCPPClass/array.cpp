#include <iostream>
#include "array.h"

Array::Array(size_t size)
{
    len = size;
    contents = new Data[size];
}

Array::Array(const Array &a)
{
    copy(a);
}

Array &Array::operator=(const Array &a)
{
    if (this != &a) {
        delete[] contents;
        copy(a);
    }
    return *this;
}

Array::~Array()
{
    delete[] contents;
}

Data Array::get(size_t index) const
{
    return contents[index];
}

void Array::set(size_t index, Data value)
{
    contents[index] = value;
}

size_t Array::size() const
{
    return len;
}

void Array::copy(const Array& a) {
    contents = new Data[a.len];
    for (size_t i = 0; i < a.len; i++)
        contents[i] = a.contents[i];
}


Array* array_create_and_read(FILE* input)
{
    int n;
    if(fscanf(input, "%d", &n) != 1)
        return NULL;
    /* Create array */
    Array* arr = new Array(n);
    /* Read array data */
    for (int i = 0; i < n; ++i)
    {
        int x;
        if (fscanf(input, "%d", &x) != 1)
            return NULL;
        arr->set(i, x);
    }
    return arr;
}