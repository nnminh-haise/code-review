
#include "Array.h"
#include "iostream"

Array::Array() {
}

Array::Array(int capacity) {
    this->_capacity = capacity;
    this->_container = new int[capacity];

    for (int i = 0; i < this->_capacity; ++i) {
        this->_container[i] = 0;
    }
}

Array::Array(int* arr, int length) {
    this->_capacity = length;
    this->_length = length;
    this->_container = new int[length];

    for (int i = 0; i < this->_length; ++i) {
        this->_container[i] = arr[i];
    }
}

Array::~Array() {
    delete[] this->_container;
}

int Array::size() {
    return this->_length;
}

void  Array::append(int value) {
    if (this->_container == nullptr) {
        throw std::runtime_error("Array is not initialized");
    }

    if (this->_length == this->_capacity) {
        throw std::runtime_error("Array at max capacity");
    }

    this->_container[this->_length++] = value;
}

int Array::get(int index) {
    if (this->_container == nullptr) {
        throw std::runtime_error("Array is not initialized");
    }

    if (index < 0 || index >= this->_capacity) {
        throw std::out_of_range("Index out of range");
    }

    return this->_container[index];
}

void Array::set(int index, int value) {
    if (this->_container == nullptr) {
        throw std::runtime_error("Array is not initialized");
    }

    if (index < 0 || index >= this->_capacity) {
        throw std::out_of_range("Index out of range");
    }

    this->_container[index] = value;
}

void Array::insert(int index, int value) {
    if (this->_container == nullptr) {
        throw std::runtime_error("Array is not initialized");
    }

    if (index < 0 || index >= this->_capacity) {
        throw std::out_of_range("Index out of range");
    }

    if (this->_length == this->_capacity) {
        throw std::runtime_error("Array at max capacity");
    }

    for (int i = this->_length; i > index; ++i) {
        this->_container[i] = this->_container[i - 1];
    }
    
    this->_container[index] = value;
}

void Array::print() {
    if (this->_container == nullptr) {
        throw std::runtime_error("Array is not initialized");
    }

    std::cout << "[";
    for (int i = 0; i < this->_length; ++i) {
        std::cout << this->_container[i] << (i < this->_length - 1 ? ", " : "");
    }
    std::cout << "]\n";
}





