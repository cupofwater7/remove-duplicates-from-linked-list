#include <iostream>
#include <vector>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList* addMany(LinkedList* linkedList, vector<int> values);
vector<int> getNodesInArray(LinkedList* linkedList);
LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList);

int main()
{
    auto input = addMany(new LinkedList(1), vector<int>{1, 3, 4, 4, 4, 5, 6, 6});
 
    auto actual = removeDuplicatesFromLinkedList(input);
    
    while(actual->next != nullptr)
    {
        cout << actual->value << " ";
        actual = actual->next;
    }
    cout << actual->value << " ";

    return 0;
}

LinkedList* addMany(LinkedList* linkedList, vector<int> values) {
    LinkedList* current = linkedList;
    while (current->next != nullptr) {
        current = current->next;
    }
    for (auto value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
    return linkedList;
}

vector<int> getNodesInArray(LinkedList* linkedList) {
    vector<int> nodes;
    LinkedList* current = linkedList;
    while (current != nullptr) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
    // Write your code here.
    LinkedList* currentlist = linkedList;
    while (currentlist)
    {
        LinkedList* nextList = currentlist->next;
        while (nextList && currentlist->value == nextList->value)
        {
            nextList = nextList->next;
        }
        currentlist->next = nextList;
        currentlist = currentlist->next;
    }
    return linkedList;
}

