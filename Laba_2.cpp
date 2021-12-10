#include <iostream>
#include "DynamicArrNum.h"
#include "arrException.h"
void test1(DynamicArrNum& dynamicArr) {
    cout << "Size = " << dynamicArr.getSize() << endl;
}

void test2(DynamicArrNum& dynamicArr, const int n) {
    cout << "arr[" << n << "] = " << dynamicArr.operator[](n) << endl;
}

void test3(DynamicArrNum& dynamicArr, int newSize) {
    dynamicArr.resize(newSize);
    cout << "new size = " << newSize << endl;
}

void test4(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator=(dynamicArr2) << endl;
}

void test5(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator==(dynamicArr2) << endl;
}

void test6(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator!=(dynamicArr2) << endl;
}

void test7(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator<(dynamicArr2) << endl;
}
void test8(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator<=(dynamicArr2) << endl;
}

void test9(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator>(dynamicArr2) << endl;
}
void test10(DynamicArrNum& dynamicArr1, const DynamicArrNum& dynamicArr2) {
    cout << dynamicArr1.operator>=(dynamicArr2) << endl;
}

int main() {
    DynamicArrNum dynamicArr1 = DynamicArrNum(10, 2);
    DynamicArrNum dynamicArr2 = DynamicArrNum(11, 2);
    test1(dynamicArr1);//getSize()
    test2(dynamicArr1, 6);//operator[]
    test3(dynamicArr1, 21);//resize
    test4(dynamicArr1, dynamicArr2);//operator=
    test5(dynamicArr1, dynamicArr2);//operator==
    test6(dynamicArr1, dynamicArr2);//operator!=
    test7(dynamicArr1, dynamicArr2);//operator<
    test8(dynamicArr1, dynamicArr2);//operator<=
    test9(dynamicArr1, dynamicArr2);//operator>
    test10(dynamicArr1, dynamicArr2);//operator>=

}
