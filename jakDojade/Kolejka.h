#pragma once

class Kolejka {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* endNode;
    int size;

public:
    Kolejka() : frontNode(nullptr), endNode(nullptr), size(0) {}

    void enqueue(int value) {
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

    int front() {
        return frontNode->data;
    }

    int rear() {
        return endNode->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};
