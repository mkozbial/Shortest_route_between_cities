#pragma once
#include "punkt.h"

class Kolejka {
private:
    struct Node {
        punkt data;
        Node* next;
        Node(punkt val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* endNode;
    int size;

public:
    Kolejka() : frontNode(nullptr), endNode(nullptr), size(0) {}

    void enqueue(punkt value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = endNode = newNode;
        }
        else {
            endNode->next = newNode;
            endNode = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        size--;
    }

    punkt front() {
        return frontNode->data;
    }

    punkt rear() {
        return endNode->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};
