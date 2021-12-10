#include "DynamicArrNum.h"
#include <iostream>
#include "arrException.h"
using namespace std;

DynamicArrNum::DynamicArrNum() {
    size = 1;
    arr = new int[size];
    arr[0] = 0;
}

DynamicArrNum::DynamicArrNum(int size) {
    try {
        if (size <= 0) { throw arrayException("SizeError"); }
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

DynamicArrNum::DynamicArrNum(int size, int n) {
    try {
        if (size <= 0) { throw arrayException("SizeError"); }
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 1;
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

DynamicArrNum::DynamicArrNum(const DynamicArrNum& dinamicArrToCopy) {
    try {
        if (dinamicArrToCopy == NULL) { throw arrayException("CopyError"); }
        this->arr = new int[dinamicArrToCopy.size];
        this->size = dinamicArrToCopy.size;
        for (int i = 0; i < dinamicArrToCopy.size; i++) {
            this->arr[i] = dinamicArrToCopy.arr[i];
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

DynamicArrNum::DynamicArrNum(DynamicArrNum&& arrToRelocate) {
    try {
        if (arrToRelocate == NULL) { throw arrayException("RelocateError"); }
        arrToRelocate.arr = arr;
        arrToRelocate.size = size;
        this->size = 0;
        this->arr = nullptr;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

int DynamicArrNum::getSize() {
    return size;
}

int& DynamicArrNum::operator[](const int index) {
    try {
        if (index >= size || index < 0) {
            throw arrayException("Invalid index");
        }
        return this->arr[index];
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

void DynamicArrNum::resize(int newSize) {
    try {
        if (newSize <= 0) {
            throw arrayException("NewSizeError");
        }
        if (size + reserveSize >= newSize) {
            reserveSize = size + reserveSize - newSize;
            size = newSize;
        }
        else {
            int* newArr = new int[newSize];
            reserveSize = 0;
            int i = 0;
            for (i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            for (; i < newSize; i++) {
                newArr[i] = 0;
            }
            delete[] this->arr;
            this->arr = newArr;
            this->size = newSize;
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

DynamicArrNum& DynamicArrNum::operator=(const DynamicArrNum& obj) {
    if (&obj == this) {
        return *this;
    }
    delete this->arr;
    this->size = obj.size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = obj.arr[i];
    }
    return *this;
}

bool DynamicArrNum::operator==(const DynamicArrNum& obj) const {
    if (this->size != obj.size) {
        throw arrayException("Invalid size of arrays");
    }
    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] != obj.arr[i]) {
            return false;
        }
    }
    return true;

}

bool DynamicArrNum::operator!=(const DynamicArrNum& obj) const {
    return !(obj == *this);
}

bool DynamicArrNum::operator<(const DynamicArrNum& obj) const {
    if (this->size < obj.size) {
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i] < obj.arr[i]) {
                return true;
            }
            else if (this->arr[i] > obj.arr[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i = 0; i < obj.size; i++) {
            if (this->arr[i] < obj.arr[i]) {
                return true;
            }
            else if (this->arr[i] > obj.arr[i]) {
                return false;
            }
        }
        return false;
    }
}

bool DynamicArrNum::operator<=(const DynamicArrNum& obj) const {
    return (*this < obj || obj == *this);
}

bool DynamicArrNum::operator>(const DynamicArrNum& obj) const {
    if (this->size < obj.size) {
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i] > obj.arr[i]) {
                return true;
            }
            else if (this->arr[i] < obj.arr[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i = 0; i < obj.size; i++) {
            if (this->arr[i] > obj.arr[i]) {
                return true;
            }
            else if (this->arr[i] < obj.arr[i]) {
                return false;
            }
        }
        return false;
    }
}

bool DynamicArrNum::operator>=(const DynamicArrNum& obj) const {
    return (*this > obj || obj == *this);
}


std::ostream& operator<<(std::ostream& out, const DynamicArrNum& obj) {
    out << "Array(size " << obj.size << "):" << endl;
    for (int i = 0; i < obj.size; i++) {
        out << "arr[" << i << "]" << "=" << obj.arr[i] << endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, DynamicArrNum& obj) {
    try {
        for (int i = 0; i < obj.size; i++) {
            in >> obj.arr[i];
        }
        in >> obj.size;
        if (obj.size <= 0) {
            throw arrayException("SizeError'In'");
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}

DynamicArrNum::~DynamicArrNum() {
    delete[] this->arr;
}

