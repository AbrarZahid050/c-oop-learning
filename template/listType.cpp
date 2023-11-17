#include <iostream>

using namespace std;

template <class element>
class listType {
public:
    bool isEmpty() const;
    bool isFull() const;
    void destoryList();
    void printList();
    listType(); // Constructor
    void search(const element& searchItem) const;
    void insert(const element& newElement);
    void remove(const element& removeElement);

protected:
    element list[100];
    int length;
};

