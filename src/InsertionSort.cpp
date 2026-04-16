#include <utility>
#include <cassert>
#include <string>
#include <iostream>
#include <stdlib.h>

void insertionSort(char *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        char cur = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cur))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cur;
    }
}

void printArray(const char *label, const char *A, int n)
{
    std::cout << label << ": ";
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    char t1[] = {'d', 'a', 'c', 'b'};
    int n1 = sizeof(t1) / sizeof(t1[0]);
    printArray("Test 1 before", t1, n1);
    insertionSort(t1, n1);
    printArray("Test 1 after ", t1, n1);
    std::cout << "Expected    : a b c d\n\n";

    char t2[] = {'z', 'x', 'x', 'a', 'm'};
    int n2 = sizeof(t2) / sizeof(t2[0]);
    printArray("Test 2 before", t2, n2);
    insertionSort(t2, n2);
    printArray("Test 2 after ", t2, n2);
    std::cout << "Expected    : a m x x z\n\n";

    char t3[] = {'a'};
    int n3 = sizeof(t3) / sizeof(t3[0]);
    printArray("Test 3 before", t3, n3);
    insertionSort(t3, n3);
    printArray("Test 3 after ", t3, n3);
    std::cout << "Expected    : a\n\n";

    return 0;
}