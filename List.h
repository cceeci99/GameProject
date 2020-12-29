#include <iostream>

#ifndef GAMEPROJECT_LIST_H
#define GAMEPROJECT_LIST_H

template<typename T>
class List {

private:

    class Node {
    public:
        T item;
        Node *next;

        explicit Node(T data) : item(data), next(nullptr) {};

        ~Node() = default;
    };

public:

    unsigned int size = 0;
    Node *head = nullptr;

    List() = default;
    ~List();

    bool empty() const;

    T swap(int pos, T other);

    T get(int pos);

    void remove(int pos);

    void add(T key);

    void remove(T key);

    T operator[](int index) const;

};

template<typename T>
List<T>::~List() {
    Node *current = head;
    Node *temp;

    while (current != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
        size--;
    }
}

template<typename T>
bool List<T>::empty() const {
    return (size == 0);
}

template<typename T>
T List<T>::swap(int pos, T other) {
    T current;

    if (pos >= size)
        return nullptr;

    Node *temp = head;
    if (pos == 0)
    {
        current = head->item;
        head->item = other;
    }
    else
    {
        int k = 0;
        while (temp != nullptr && k < pos)
        {
            k++;
            temp = temp->next;
        }
        current = temp->item;
        temp->item = other;
    }

    return current;
}

template<typename T>
T List<T>::get(int pos) {
    T var;

    if (pos >= size)
        return nullptr;

    if (pos == 0)
        var = head->item;
    else
    {
        int k = 0;
        Node *temp = head;
        while (temp != nullptr && k < pos)
        {
            k++;
            temp = temp->next;
        }
        var = temp->item;
    }
    return var;
}

template<typename T>
void List<T>::remove(int pos) {

    if (pos >= size)
        return;

    Node *temp = head;
    if (pos == 0)
    {
        head = head->next;
        delete temp;
    }
    else
    {
        int k = 0;
        while (temp != nullptr && k < (pos - 1))
        {
            k++;
            temp = temp->next;
        }
        Node *node = temp->next->next;

        delete temp->next;

        temp->next = node;
    }
    size--;
}

template<typename T>
void List<T>::add(T key) {
    Node *newNode = new Node(key);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename T>
void List<T>::remove(T key) {
    Node *temp = head;
    Node *prev;

    if (temp != nullptr && temp->item == key)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        while (temp != nullptr && temp->item != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;

        delete temp;
    }
    size--;
}

template<typename T>
T List<T>::operator[](const int index) const {
    T var;
    if (index == 0)
        var = head->item;
    else
    {
        int k = 0;
        Node *temp = head;
        while (temp != nullptr && k < index)
        {
            k++;
            temp = temp->next;
        }
        var = temp->item;
    }

    return var;
}


#endif //GAMEPROJECT_LIST_H