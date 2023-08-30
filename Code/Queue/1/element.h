#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct Element {
    char item;
    struct Element *nextElement;
} Element;

#endif