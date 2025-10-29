#include "Massive.h"

void createMassive(Massive* massive, int capasity) {
    massive->capacity = capasity;
    massive->size = 0;
    massive->data = new std::string[capasity];
    for (int i = 0; i < capasity; i++) {
        massive->data[i] = "";
    }
}
void resize(Massive* massive) {
    massive->capacity = (massive->capacity == 0 ? 1 : massive->capacity * 2);
    std::string* newData = new std::string[massive->capacity];
    for (int i = 0; i < massive->size; i++) {
        newData[i] = massive->data[i];
    }
    delete[] massive->data;
    massive->data = newData;
}
void pushBack(Massive* massive, std::string value) {
    if (massive->size >= massive->capacity) {
        resize(massive);
    }
    massive->data[massive->size] = value;
    massive->size += 1;
}
void insert(Massive* massive, int index, std::string value) {
    if (index >= massive->capacity * 2) {
        std::cout << "Out of range ERROR\n";
    }
    else {
        if (massive->size >= massive->capacity) {
            resize(massive);
        }
        if (index > massive->size) {
            std::cout << "Index is too big, the value is set to the end of the massive\n";
            pushBack(massive, value);
        }
        if (massive->data[index] == "") {
            massive->data[index] = value;
            massive->size += 1;
        }
        else {
            for (int i = massive->size-1; i >= index; i--) {
                if (massive->data[i] != "") {
                    insert(massive, i+1, massive->data[i]);
                    massive->data[i] = "";
                }
            }
            massive->data[index] = value;
            massive->size += 1;
        }
    }
}
void remove(Massive* massive, int index) {
    if (index >= massive->capacity) {
        std::cout << "Out of range ERROR\n";
    }
    else {
        massive->data[index] = "";
        massive->size -= 1;
        if (index != massive->size && massive->data[index + 1] != "") {
            massive->data[index] = massive->data[index + 1];
            massive->size += 1;
            remove(massive, index + 1);
        }
    }
}
int getSize(Massive* massive) {
    return massive->size;
}
std::string getElement(Massive massive, int index) {
    return massive.data[index];
}
std::ostream& operator<< (std::ostream& os, Massive massive) {
    for (int i = 0; i < massive.capacity; i++) {
        if (massive.data[i] != "") {
            os << massive.data[i] << " ";
        }
    }
    return os;
}

void exportMassive(Massive mass, std::string path) {
    std::ofstream out;
    out.open(path);
    if (out.is_open()) {
        out << mass.capacity << " ";
        out << mass;
    }
    out.close();
}

Massive* importMassive(std::string path) {
    Massive* result = new Massive;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        std::string data;
        in >> data;
        createMassive(result, stoi(data));
        while(in >> data) {
            pushBack(result, data);
        }
    }
    in.close();
    return result;
}

void set(Massive* massive, int index, std::string value) {
    if (index >= massive->capacity * 2) {
        std::cout << "Out of range ERROR\n";
    }
    else {
        if (massive->size >= massive->capacity) {
            resize(massive);
        }
        if (massive->data[index] == "") {
            std::cout << "empty element\n";
        }
        else {
            massive->data[index] = value;
        }
    }
}