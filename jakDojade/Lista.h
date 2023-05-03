#pragma once
#include "Miasto.h"

class Node {
public:

    String miasto;
    int data;
    Node* next;

    Node(String miasto, int distance) {
        this->miasto = miasto;
        this->data = distance;
        this->next = nullptr;
    }
};

class Lista {

    

public:
    int size;
    Node* head;

    Lista() {
        this->head = nullptr;
        this->size = 0;
    }

    void dodaj(String miasto, int dystans) {

        Node* newNode = new Node(miasto, dystans);
        if (head == nullptr) {

            head = newNode;
        }
        else {

            Node* curr = head;
            if (curr == nullptr) {
				return;
			}
            while (curr->next != nullptr) {

                if (curr->miasto == miasto) {

                    if (curr->data > dystans) {
                        curr->data = dystans;
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

    String getMiasto(int index) {

        if (head == nullptr) {
            return "";
        }

        Node* curr = head;

        for (int i = 0; i < index; i++) {

            if (curr->next == nullptr) {

                return "";
            }
            curr = curr->next;
        }

        return curr->miasto;
    }

    int getDystans(int index) {

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data;
    }

    int getRozmiar() {
        return size;
    }

    void printList() {
        Node* curr = head;
        //if (curr == nullptr) {
        //    std::cout << "Lista jest pusta" << std::endl;
        //}
      while (curr != nullptr) {
            std::cout << curr->miasto.getString() << ", dystans: " << curr->data << " ";
            curr = curr->next;
        }
    }

};
