
#include <ostream>

class DynamicArrNum
{
public:
    int* arr;
    int size;
    int reserveSize{};
    DynamicArrNum();
    DynamicArrNum(int size);
    DynamicArrNum(int size, int n);
    DynamicArrNum(const DynamicArrNum& dinamicArrToCopy);
    DynamicArrNum(DynamicArrNum&& arrToRelocate);

    int getSize();
    int& operator[](const int index);
    void resize(const int newSize);

    DynamicArrNum& operator=(const DynamicArrNum& obj);
    bool operator==(const DynamicArrNum& obj) const;
    bool operator!=(const DynamicArrNum& obj) const;
    bool operator<(const DynamicArrNum& obj) const;
    bool operator<=(const DynamicArrNum& obj) const;
    bool operator>(const DynamicArrNum& obj) const;
    bool operator>=(const DynamicArrNum& obj) const;

    friend std::ostream& operator << (std::ostream& out, const DynamicArrNum& obj);
    friend std::istream& operator >> (std::istream& in, DynamicArrNum& obj);



    ~DynamicArrNum();
};