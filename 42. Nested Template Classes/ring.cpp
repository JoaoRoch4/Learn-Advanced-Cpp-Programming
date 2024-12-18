#include "ring.hpp"

#include <iostream>

//template<typename T> 
//ring<T>::ring() : m_values(nullptr), m_pos(0), m_size(0) {}
////
//template<typename T> 
//ring<T>::ring(int size_passed)
//  {
//
//	
//}

template<typename T> 
void ring<T>::Add(T &Value) {

	m_values [m_pos++] = Value;

	if (m_pos == m_size) m_pos = 0;
}

template<typename T> 
ring<T>::~ring() { 
	
	delete[] m_values;
    m_values = nullptr;
    m_size   = 0;
    m_pos    = 0;
}
