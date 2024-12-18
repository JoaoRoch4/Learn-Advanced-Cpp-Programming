#pragma once

#include "MyTypes.hpp"

template<typename T>
class ring {

private:

    T     *m_values;
    int m_size;
    int m_pos;

public:

    ring() : m_values(nullptr), m_size(size_passed), m_pos(0) {};

    
    ring(int size_passed) : m_values(nullptr), m_size(size_passed), m_pos(0) {
        m_values = new T [];
    }
        
    
    void   Add(T &Value);

    inline size_t Size() { return m_values; }
    inline T     &Get(int &pos) { return m_values [pos]; }
       

    class iterator;
    virtual ~ring();

    ring(T *m_values, int m_size, int m_pos) : m_values(m_values), m_size(m_size), m_pos(m_pos) {}
};
