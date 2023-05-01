#pragma once
#include "Miasto.h"

class Node {
public:
    String miasto;
    int dystans;
    Node* next;

    Node(String miasto, int distance) {
        this->miasto = miasto;
        this->dystans = distance;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    void add(String miasto, int dystans) {
        Node* newNode = new Node(miasto, dystans);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                if (curr->miasto == miasto)
                {
                    if (curr->dystans > dystans) {
                        curr->dystans = dystans;
                    }
                    else {
                        return;
                    }
                    
                }
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void remove(int index) {
        if (index >= size) {
            return;
        }
        Node* curr = head;
        if (index == 0) {
            head = curr->next;
            delete curr;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }

    String getMiasto(int index) {
        if (head == nullptr) {
            // handle empty list
            return "";
        }

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            if (curr->next == nullptr) {
                // handle index out of range
                return "";
            }
            curr = curr->next;
        }
        return curr->miasto;
    }

    int getDistance(int index) {
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->dystans;
    }

    int getSize() {
        return size;
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->miasto.getString() << ", dystans: " << curr->dystans << " ";
            curr = curr->next;
        }
    }

};
