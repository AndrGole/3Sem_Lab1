#pragma once

#include <iostream>
#include <fstream>
#include <string>

struct Massive {
    std::string* data;
    int capacity;
    int size;
};

void createMassive(Massive* massive, int capasity);

void resize(Massive* massive);

void pushBack(Massive* massive, std::string value);

void insert(Massive* massive, int index, std::string value);

void set(Massive* massive, int index, std::string value);

void remove(Massive* massive, int index);

int getSize(Massive* massive);

std::string getElement(Massive massive, int index);

std::ostream& operator<< (std::ostream& os, Massive massive);

void exportMassive(Massive mass, std::string path);

Massive* importMassive(std::string path);