#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

static void printList(const list<int>& lst, const char *name) {
    cout << name << ": ";
    for (int v : lst) cout << v << " ";
    cout << '\n';
}

int main() {
    list<int> lst1; //lst1 is empty
    list<int> lst2(3,7); //lst 2 = ( 7 7 7 )
    printList(lst2, "lst2 (init)");
    for(int j =1;j <= 5; j++)
        lst1.push_back(j); //insert j at the end of the list -> (1 2 3 4 5 )
    printList(lst1, "lst1 (after push_back)");
    list<int>::iterator i1 = lst1.begin(), i2 = i1, i3; i2++; i2++; i2++;
    //iterator begin() return an iterator that references the first node of the list
    list<int> lst3(++i1,i2); // lst3 = (2 3)
    printList(lst3, "lst3 (constructed)");
    list<int> lst4(lst1); //copy constructor -> lst4 = (1 2 3 4 5)
    printList(lst4, "lst4 (copied from lst1)");
    i1 = lst4.begin(); // i1 = 1
    lst4.splice(++i1, lst2);
    printList(lst4, "lst4 (after splice lst2 into lst4)");
    printList(lst2, "lst2 (after splice, should be empty)");
    //splice(i, lst) remove a nodes of the list lst2 and inert them into the list before (lst4) before the position referenced by iterator i ---> lst4 = (1 7 7 7 2 3 4 5); lst2 is empty

    lst2 = lst1; //lst2 = (1 2 3 4 5)
    printList(lst2, "lst2 (after assign lst1)");
    i2 = lst2.begin();
    lst4.splice(i1,lst2,++i2); //lst2 = (1 3 4 5); lst4 =  1 7 7 7 2 2 3 4 5
    printList(lst4, "lst4 (after splice single element from lst2)");
    printList(lst2, "lst2 (after removing one element)");
    //splice(i, lst, j): remove from list lst the node referenced by iterator j and insert it into the list befoere the posion referenced by interator i
    i2 = lst2.begin();
    //currently i1 = 2
    i3 = i2;
    //i2 = lst2[0]
    //I3 = lst2[1]
    //splice(i, lst, first, last): remove from the lst the nodes in the range indicated by iterators first and last, and insert them into the list before the postion referenced by iterator i
    lst4.splice(i1, lst2, i2, ++i3); // lst2 = (3 4 5), lst4 = (1 7 7 7 1 2 2 3 4 5)
    printList(lst4, "lst4 (after splice range from lst2)");
    printList(lst2, "lst2 (after splice range)");
    lst4.remove(1); //lst4 (7 7 7 2 2 3 4 5)
    printList(lst4, "lst4 (after remove 1)");
    lst4.sort(); //lst4 = (2 2 3 4 5 7 7 7)
    printList(lst4, "lst4 (after sort)");
    lst4.unique(); //lst 4= (2 3 4 5 7)
    printList(lst4, "lst4 (after unique)");
    lst1.merge(lst2); // for the sord current list and lst, remove all nodes from lst and insert them in sorted order in the current list --->> lst1 = (1 2 3 3 4 4 5 5), lst2 is empty
    printList(lst1, "lst1 (after merge lst2 into lst1)");
    printList(lst2, "lst2 (after merge, should be empty)");
    lst3.reverse(); //lst 3= (3 2)
    printList(lst3, "lst3 (after reverse)");
    lst4.reverse(); //lst4 = (7 5 4 3 2)
    printList(lst4, "lst4 (after reverse)");
    lst3.merge(lst4, greater<int>()); //lst3 = ( 7 5 4 3 3 2 2), lst4 is empty
    printList(lst3, "lst3 (after merge with lst4 using greater)");
    printList(lst4, "lst4 (after merge, should be empty)");
    // done merge mean the list the merge to the other one is empty
    lst3.remove_if([](int x){ return x != 3; }); // lst3 = (3 3)
    printList(lst3, "lst3 (after remove_if keep only 3)");
    lst3.unique(not_equal_to<int>()); // lst3 = (3 3)
    printList(lst3, "lst3 (after unique with not_equal_to)");
}
