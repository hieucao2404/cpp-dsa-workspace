#include <utility>
#include <cassert>
#include <string>
#include <iostream>

template <typename Object>
class List
{
private:
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
            : data{d}, prev{p}, next{n}
        {
        }

        Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
            : data{std::move(d)}, prev{p}, next{n}
        {
        }
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current{nullptr}
        {
        }

        const Object &operator*() const
        {
            return retrieve();
        }

        const_iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator &operator--()
        {
            current = current->prev;
            return *this;
        }

        const_iterator operator--(int)
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        Node *current;

        const Object &retrieve() const
        {
            return current->data;
        }

        const_iterator(Node *p) : current{p}
        {
        }

        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
    public:
        iterator()
        {
        }

        Object &operator*()
        {
            return const_cast<Object &>(const_iterator::retrieve());
        }

        const Object &operator*() const
        {
            return const_iterator::operator*();
        }

        iterator &operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--()
        {
            this->current = this->current->prev;
            return *this;
        }

        iterator operator--(int)
        {
            iterator old = *this;
            --(*this);
            return old;
        }

    protected:
        iterator(Node *p) : const_iterator{p}
        {
        }

        friend class List<Object>;
    };

public:
    List()
    {
        init();
    }

    ~List()
    {
        clear();
        delete head;
        delete tail;
    }

    List(const List &rhs)
    {
        init();
        for (const auto &x : rhs)
        {
            push_back(x);
        }
    }

    List &operator=(const List &rhs)
    {
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    List(List &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    List &operator=(List &&rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }

    iterator begin()
    {
        return iterator{head->next};
    }

    const_iterator begin() const
    {
        return const_iterator{head->next};
    }

    iterator end()
    {
        return iterator{tail};
    }

    const_iterator end() const
    {
        return const_iterator{tail};
    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    Object &front()
    {
        return *begin();
    }

    const Object &front() const
    {
        return *begin();
    }

    Object &back()
    {
        return *--end();
    }

    const Object &back() const
    {
        return *--end();
    }

    void push_front(const Object &x)
    {
        insert(begin(), x);
    }

    void push_front(Object &&x)
    {
        insert(begin(), std::move(x));
    }

    void push_back(const Object &x)
    {
        insert(end(), x);
    }

    void push_back(Object &&x)
    {
        insert(end(), std::move(x));
    }

    void pop_front()
    {
        erase(begin());
    }

    void pop_back()
    {
        erase(--end());
    }

    iterator insert(iterator itr, const Object &x)
    {
        Node *p = itr.current;
        ++theSize;
        return iterator{p->prev = p->prev->next = new Node{x, p->prev, p}};
    }

    iterator insert(iterator itr, Object &&x)
    {
        Node *p = itr.current;
        ++theSize;
        return iterator{p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
    }

    iterator erase(iterator itr)
    {
        Node *p = itr.current;
        iterator retVal{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;
        return retVal;
    }

    iterator erase(iterator from, iterator to)
    {
        while (from != to)
        {
            from = erase(from);
        }
        return to;
    }

private:
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

int main()
{
    List<char> letters;
    std::cout << "Test 1: Empty list check\n";
    assert(letters.empty());
    std::cout << "  PASS: List is empty\n\n";

    // Test push_front / push_back
    std::cout << "Test 2: Push operations\n";
    letters.push_back('b');
    letters.push_front('a');
    letters.push_back('d');
    std::cout << "  Pushed: 'b', 'a' (front), 'd'\n";
    std::cout << "  List should be: a b d\n";
    std::cout << "  Size: " << letters.size() << "\n";
    std::cout << "  Front: " << letters.front() << ", Back: " << letters.back() << "\n";
    assert(letters.size() == 3);
    assert(letters.front() == 'a');
    assert(letters.back() == 'd');
    std::cout << "  PASS\n\n";

    // Test insert in the middle
    std::cout << "Test 3: Insert in middle\n";
    auto it = letters.begin();
    ++it; // points to 'b'
    letters.insert(it, 'x');
    std::cout << "  Inserted 'x' before 'b'\n";
    // list: a x b d

    std::cout << "Test 4: Forward traversal\n";
    std::string order;
    for (auto itr = letters.begin(); itr != letters.end(); ++itr)
    {
        order += *itr;
    }
    std::cout << "  Traversed list: " << order << "\n";
    assert(order == "axbd");
    std::cout << "  PASS: Got expected 'axbd'\n\n";

    // Test erase range: remove x and b
    std::cout << "Test 5: Erase range\n";
    auto from = letters.begin();
    ++from; // x
    auto to = letters.end();
    --to; // d (end is tail sentinel)
    std::cout << "  Erasing from 'x' to 'd' (exclusive)\n";
    letters.erase(from, to);
    // list: a d

    std::cout << "Test 6: Verify after erase\n";
    std::cout << "  Size: " << letters.size() << "\n";
    std::cout << "  Front: " << letters.front() << ", Back: " << letters.back() << "\n";
    assert(letters.size() == 2);
    assert(letters.front() == 'a');
    assert(letters.back() == 'd');
    std::cout << "  PASS: Remaining list is 'a d'\n\n";

    // Test pop_front / pop_back
    std::cout << "Test 7: Pop operations\n";
    letters.pop_front(); // remove a
    std::cout << "  Popped front ('a')\n";
    std::cout << "  Size: " << letters.size() << "\n";

    letters.pop_back(); // remove d
    std::cout << "  Popped back ('d')\n";
    std::cout << "  Size: " << letters.size() << "\n";
    assert(letters.empty());
    std::cout << "  PASS: List is empty\n\n";

    std::cout << "===== All char-list tests passed! =====\n";
    return 0;
}