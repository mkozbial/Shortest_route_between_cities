#pragma once
#include "punkt.h"

class Kolejka {
private:

    struct Node {
        punkt data;
        Node* next;
        Node(punkt val) : data(val), next(nullptr) {}
    };

    Node* przedniNode;
    Node* koncowyNode;
    int size;

public:

    Kolejka() : przedniNode(nullptr), koncowyNode(nullptr), size(0) {}

    void enqueue(punkt wartosc) {

        Node* newNode = new Node(wartosc);

        if (czyPusty()) {
            przedniNode = koncowyNode = newNode;
        }
        else {

            koncowyNode->next = newNode;
            koncowyNode = newNode;
        }
        size++;
    }

    void dequeue() {

        if (czyPusty()) {
            return;
        }

        Node* temp = przedniNode;
        przedniNode = przedniNode->next;
        delete temp;
        size--;
    }

    punkt przedni() {
        return przedniNode->data;
    }

    punkt koncowy() {
        return koncowyNode->data;
    }

    int getRozmiar() {
        return size;
    }

    bool czyPusty() {
        return przedniNode == nullptr;
    }
};
