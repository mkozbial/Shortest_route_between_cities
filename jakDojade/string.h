#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class String {
public:
    size_t strLength;
    char* strData;
    String() {
        strData = new char[1];
        strData[0] = '\0';
        strLength = 0;
    }
    String(const char* string) { 
        if (string != NULL) {
            strLength = strlen(string);
            strData = new char[strLength + 1];
            strcpy(strData, string);
        }
    }
    String(const String& other) {
        try {
            strLength = other.strLength;
            strData = new char[strLength + 1];
            strcpy(strData, other.strData);
        }
        catch (...) {
            delete[] strData;
            strData = nullptr;
            strLength = 0;
            throw;
        };
        if (strData == nullptr) {
            strLength = 0;
        }
    }
    String(String&& other) noexcept {
        strLength = other.strLength;
        strData = other.strData;
        other.strData = nullptr;
        other.strLength = 0;
    }
    void addChar(char c) {
        char* newData = new char[strLength + 2];
        if (strData != NULL)
            strcpy(newData, strData);
        newData[strLength] = c;
        newData[strLength + 1] = '\0';
        delete[] strData;
        strData = newData;
        strLength++;
    }
    ~String() {
        delete[] strData;
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] strData;
            strLength = other.strLength;
            strData = new char[strLength + 1];
            strcpy(strData, other.strData);
        }
        return *this;
    }
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] strData;
            strLength = other.strLength;
            strData = other.strData;
            other.strData = nullptr;
            other.strLength = 0;
        }
        return *this;
    }
    String& operator+=(const String& other) {
        int newLength = strLength + other.strLength;
        char* tmp = new char[strLength + other.strLength + 1];
        strcpy_s(tmp, strLength + 1, strData);
        strcat_s(tmp, newLength + 1, other.strData);
        delete[] strData;
        strData = tmp;
        strLength += other.strLength;
        return *this;
    }
    friend String operator+(String left, const String& right) {
        left += right;
        return left;
    }
    const char& operator[](size_t idx) const {
        return strData[idx];
    }
    char& operator[](size_t idx) {
        return strData[idx];
    }
    bool operator==(const String& other) const {
        if (strLength != other.strLength) {
            return false;
        }
        return strcmp(strData, other.strData) == 0;
    }
    size_t length() const {
        return strLength;
    }
    const char* getString() const {
        if (strLength > 0) {
            return strData;
        }
        return "";
    }
};
