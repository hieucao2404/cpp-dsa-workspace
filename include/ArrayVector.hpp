// include/ArrayVector.hpp
typedef int Elem;

// simple exception type for index errors
struct IndexOutOfBounds
{
};

class ArrayVector
{
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem &operator[](int i); // Element of index
    Elem &at(int i);         // element at index (throws IndexOutOfBounds if out of range)
    void erase(int i);       // remove element at index
    void insert(int i, const Elem &e);
    void reserve(int N); // reverse first N elements (or whole vector if N > size)
private:
    int capacity;
    int n;
    Elem *A;
};