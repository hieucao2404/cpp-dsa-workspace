#include <iostream>
#include <vector>
using namespace std;

// Simple Sequence wrapper around vector
class Sequence
{
public:
    typedef vector<int>::iterator Iterator;

    Sequence() {}

    void insert(int value)
    {
        data.push_back(value);
    }

    int size() const
    {
        return data.size();
    }

    Iterator begin()
    {
        return data.begin();
    }

    Iterator end()
    {
        return data.end();
    }

    Iterator atIndex(int i)
    {
        return data.begin() + i;
    }

    // Print sequence
    void print() const
    {
        for (int val : data)
            cout << val << " ";
        cout << "\n";
    }

private:
    vector<int> data;
};

// Fixed bubble sort version 1 (by index)
void bubbleSort1(Sequence &S)
{
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++) // Fixed: j < n - i to avoid redundant passes
        {
            Sequence::Iterator prec = S.atIndex(j - 1); // predecessor
            Sequence::Iterator succ = S.atIndex(j);     // successor
            if (*prec > *succ)
            {
                int tmp = *prec;
                *prec = *succ; // Fixed: was just "*prec;"
                *succ = tmp;
            }
        }
    }
}

// Fixed bubble sort version 2 (by iterator)
void bubbleSort2(Sequence &S)
{
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        // i-th pass
        Sequence::Iterator prec = S.begin();
        for (int j = 1; j < n - i; j++)
        {
            Sequence::Iterator succ = prec;
            ++succ;
            // swap if out of order
            if (*prec > *succ)
            {
                int tmp = *prec;
                *prec = *succ;
                *succ = tmp;
            }
            ++prec; // advance predecessor
        }
    }
}

int main()
{
    cout << "=== Bubble Sort Test ===\n\n";

    cout << "Test 1: bubbleSort1 (by index)\n";
    Sequence s1;
    s1.insert(5);
    s1.insert(2);
    s1.insert(8);
    s1.insert(1);
    s1.insert(9);

    cout << "Before: ";
    s1.print();
    bubbleSort1(s1);
    cout << "After:  ";
    s1.print();
    cout << "\n";

    cout << "Test 2: bubbleSort2 (by iterator)\n";
    Sequence s2;
    s2.insert(7);
    s2.insert(3);
    s2.insert(6);
    s2.insert(1);
    s2.insert(4);

    cout << "Before: ";
    s2.print();
    bubbleSort2(s2);
    cout << "After:  ";
    s2.print();
    cout << "\n";

    cout << "=== All tests passed! ===\n";
    return 0;
}