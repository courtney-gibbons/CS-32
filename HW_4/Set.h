#ifndef SET_INCLUDED
#define SET_INCLUDED

template<typename T>
class Set
{
  public:
    Set();               // Create an empty set (i.e., one with no items).
    bool empty() const;  // Return true if the set is empty, otherwise false.
    int size() const;    // Return the number of items in the set.

    bool insert(const T& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value is actually inserted.  Leave the set unchanged
      // and return false if the value is not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const T& value);
      // Remove the value from the set if it is present.  Return true if the
      // value was removed; otherwise, leave the set unchanged and
      // return false.

    bool contains(const T& value) const;
      // Return true if the value is in the set, otherwise false.

    bool get(int i, T& value) const;
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly less than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
      // Exchange the contents of this set with the other one.

      // Housekeeping functions
    ~Set();
    Set(const Set& other);
    Set& operator=(const Set& rhs);

  private:
      // Representation:
      //   a circular doubly-linked list with a dummy node.
      //   m_head points to the dummy node.
      //   m_head->m_prev->m_next == m_head and m_head->m_next->m_prev == m_head
      //   m_size == 0  iff  m_head->m_next == m_head->m_prev == m_head
      //   If p and p->m_next point to nodes other than the dummy node,
      //      p->m_value > p->m_next->m_value

    struct Node
    {
        T m_value;
        Node*    m_next;
        Node*    m_prev;
    };

    Node* m_head;
    int   m_size;

    void createEmpty();
      // Create an empty list.  (Will be called only by constructors.)

    void insertBefore(Node* p, const T& value);
      // Insert value in a new Node before Node p, incrementing m_size.

    void doErase(Node* p);
      // Remove the Node p, decrementing m_size.

    Node* findFirstAtMost(const T& value) const;
      // Return pointer to first Node whose m_value <= value if present,
      // else m_head
};

// Declarations of non-member functions

template<typename T>
void unite(const T& s1, const T& s2, T& result);
      // result = { x | (x in s1) OR (x in s2) }

template<typename T>
void difference(const T& s1, const T& s2, T& result);
      // result = { x | (x in s1) AND NOT (x in s2) }

// Inline implementations

template<typename T>
inline
int Set<T>::size() const
{
    return m_size;
}

template<typename T>
inline
bool Set<T>::empty() const
{
    return size() == 0;
}

template<typename T>
inline
bool Set<T>::contains(const T& value) const
{
    Node* p = findFirstAtMost(value);
    return p != m_head  &&  p->m_value == value;
}

// Non inline functions

template<typename T>
Set<T>::Set()
{
    createEmpty();
}

template<typename T>
bool Set<T>::insert(const T& value)
{
      // Fail if value already present

    Node* p = findFirstAtMost(value);
    if (p != m_head  &&  p->m_value == value)
        return false;

      // Insert new Node preserving descending order and incrementing m_size

    insertBefore(p, value);
    return true;
}

template<typename T>
bool Set<T>::erase(const T& value)
{
      // Find the Node with the value, failing if there is none.

    Node* p = findFirstAtMost(value);
    if (p == m_head  ||  p->m_value != value)
        return false;

      // Erase the Node, decrementing m_size
    doErase(p);
    return true;
}

template<typename T>
bool Set<T>::get(int i, T& value) const
{
    if (i < 0  ||  i >= m_size)
        return false;

      // Return the value at position i.  Since the values are stored in
      // descending, the value at position i will be less than exactly i
      // items in the set, meeting get's specification.

      // If i is closer to the head of the list, go forward to reach that
      // position; otherwise, start from tail and go backward.

    Node* p;
    if (i < m_size / 2)  // closer to head
    {
        p = m_head->m_next;
        for (int k = 0; k != i; k++)
            p = p->m_next;
    }
    else  // closer to tail
    {
        p = m_head->m_prev;
        for (int k = m_size-1; k != i; k--)
            p = p->m_prev;
    }

    value = p->m_value;
    return true;
}

template<typename T>
void Set<T>::swap(Set<T>& other)
{
      // Swap head pointers

    Node* p = other.m_head;
    other.m_head = m_head;
    m_head = p;

      // Swap sizes

    int s = other.m_size;
    other.m_size = m_size;
    m_size = s;
}

template<typename T>
Set<T>::~Set()
{
      // Delete all Nodes from first non-dummy up to but not including
      // the dummy

    while (m_head->m_next != m_head)
        doErase(m_head->m_next);

      // delete the dummy

    delete m_head;
}

template<typename T>
Set<T>::Set(const Set<T>& other)
{
    createEmpty();

      // Copy all non-dummy other Nodes.  (This will set m_size.)
      // Inserting each new node before the dummy node that m_head points to
      // puts the new node at the end of the list.

    for (Node* p = other.m_head->m_next; p != other.m_head; p = p->m_next)
        insertBefore(m_head, p->m_value);
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& rhs)
{
    if (this != &rhs)
    {
          // Copy and swap idiom

        Set temp(rhs);
        swap(temp);
    }
    return *this;
}

template<typename T>
void Set<T>::createEmpty()
{
    m_size = 0;

      // Create dummy node

    m_head = new Node;
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
}

template<typename T>
void Set<T>::insertBefore(Node* p, const T& value)
{
      // Create a new node

    Node* newp = new Node;
    newp->m_value = value;

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp;
    newp->m_next->m_prev = newp;

    m_size++;
}

template<typename T>
void Set<T>::doErase(Node* p)
{
      // Unlink p from the list and destroy it

    p->m_prev->m_next = p->m_next;
    p->m_next->m_prev = p->m_prev;
    delete p;

    m_size--;
}

template<typename T>
typename Set<T>::Node* Set<T>::findFirstAtMost(const T& value) const
{
      // Walk through the list looking for a match

    Node* p = m_head->m_next;
    for ( ; p != m_head  &&  p->m_value > value; p = p->m_next)
        ;
    return p;
}

template<typename T>
void unite(const Set<T>& s1, const Set<T>& s2, Set<T>& result)
{
      // Check for aliasing to get correct behavior or better performance:
      // If result is s1 and s2, result already is the union.
      // If result is s1, insert s2's elements into result.
      // If result is s2, insert s1's elements into result.
      // If result is a distinct set, assign it s1's contents, then
      //   insert s2's elements in result, unless s2 is s1, in which
      //   case result now already is the union.

    const Set<T>* sp = &s2;
    if (&result == &s1)
    {
        if (&result == &s2)
                return;
    }
    else if (&result == &s2)
        sp = &s1;
    else
    {
        result = s1;
        if (&s1 == &s2)
            return;
    }
    for (int k = 0; k < sp->size(); k++)
    {
        T v;
        sp->get(k, v);
        result.insert(v);
    }
}

template<typename T>
void difference(const Set<T>& s1, const Set<T>& s2, Set<T>& result)
{
      // Guard against the case that result is an alias for s2 by copying
      // s2 to a local variable.  This implementation needs no precaution
      // against result being an alias for s1.

    Set<T> s2copy(s2);
    result = s1;
    for (int k = 0; k < s2copy.size(); k++)
    {
        T v;
        s2copy.get(k, v);
        if (!result.erase(v))
            result.insert(v);
    }
}

#endif // SET_INCLUDED
