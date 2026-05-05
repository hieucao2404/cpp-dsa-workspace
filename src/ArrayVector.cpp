#include "ArrayVector.hpp"
#include <algorithm>
#include <iostream>
namespace
{
    // Helper to grow array
    void grow(Elem *&A, int &capacity, int minCapacity)
    {
        int newCap = std::max(capacity * 2, std::max(16, minCapacity));
        Elem *B = new Elem[newCap];
        std::copy(A, A + capacity, B);
        delete[] A;
        A = B;
        capacity = newCap;
    }

}

ArrayVector::ArrayVector() : capacity(16), n(0), A(new Elem[16]) {}

int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return size() == 0;
}

Elem &ArrayVector::operator[](int i)
{
    return A[i];
}

Elem &ArrayVector::at(int i)
{
    if (i < 0 || i >= n)
        throw IndexOutOfBounds();
    return A[i];
}

void ArrayVector::erase(int i)
{
    if (i < 0 || i >= n)
        return;
    for (int j = i + 1; j < n; j++)
    {
        A[j - 1] = A[j];
    }
    n--;
    // Different approach
    //  for (int j = i; j < n - 1; ++j) A[j] = A[j + 1];
    //  --n;
}

void ArrayVector::reserve(int N)
{
    // Reserve at least N spots
    if (capacity >= N)
        return;
    Elem *B = new Elem[N];
    for (int j = 0; j < n; j++)
    {
        B[j] = A[j];
    }
    if (A != NULL)
        delete[] A;
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem &e)
{
    if (n >= capacity)
    {
        reserve(std::max(1, 2 * capacity));
    }
    for (int j = n - 1; j >= i; j--)
    {
        A[j + 1] = A[j];
    }
    A[i] = e;
    n++;
}


using namespace std;

int main()
{
    ArrayVector v;

    cout << "=== Test 1: Constructor & Empty ===\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Empty: " << (v.empty() ? "yes" : "no") << "\n\n";

    cout << "=== Test 2: Insert ===\n";
    v.insert(0, 10);
    cout << "After insert(0, 10): size=" << v.size() << ", [0]=" << v[0] << "\n";

    v.insert(1, 20);
    cout << "After insert(1, 20): size=" << v.size() << ", [0]=" << v[0] << ", [1]=" << v[1] << "\n";

    v.insert(1, 15);
    cout << "After insert(1, 15): size=" << v.size();
    cout << ", contents: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    cout << "=== Test 3: operator[] ===\n";
    cout << "v[0] = " << v[0] << "\n";
    cout << "v[1] = " << v[1] << "\n";
    cout << "v[2] = " << v[2] << "\n\n";

    cout << "=== Test 4: at() with bounds check ===\n";
    try
    {
        cout << "at(1) = " << v.at(1) << " (valid)\n";
        cout << "Trying at(100)...\n";
        v.at(100);
        cout << "ERROR: at(100) should have thrown!\n";
    }
    catch (IndexOutOfBounds &)
    {
        cout << "at(100) threw IndexOutOfBounds (expected)\n";
    }
    cout << "\n";

    cout << "=== Test 5: Erase ===\n";
    cout << "Before erase: size=" << v.size() << ", contents: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";

    v.erase(1);
    cout << "After erase(1): size=" << v.size() << ", contents: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    cout << "=== Test 6: Reserve (grow capacity) ===\n";
    cout << "Adding 20 more elements...\n";
    for (int i = 0; i < 20; ++i)
    {
        v.insert(v.size(), 100 + i);
    }
    cout << "Size: " << v.size() << "\n";
    cout << "First 5: ";
    for (int i = 0; i < 5; ++i)
        cout << v[i] << " ";
    cout << "\n";
    cout << "Last 5: ";
    for (int i = v.size() - 5; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    cout << "=== All tests passed! ===\n";
    return 0;
}