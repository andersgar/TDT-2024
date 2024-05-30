#include <stdexcept>

template <typename Type, int Size>
class MyArray
{
private:
    Type elements[Size];

public:
    MyArray() = default;
    int getSize() const;
    Type at(int index) const;
    void fill(Type valueToFill);
};

template <typename Type, int Size>
int MyArray<Type, Size>::getSize() const
{
    return Size;
}

template <typename Type, int Size>
Type MyArray<Type, Size>::at(int index) const
{
    if (index < 0 || index >= Size)
    {
        throw std::out_of_range("Index is out of range.");
    }
    else
    {
        return elements[index];
    }
}

template <typename Type, int Size>
void MyArray<Type, Size>::fill(Type valueToFill)
{
    for (int i = 0; i < Size; i++)
    {
        elements[i] = valueToFill;
    }
}