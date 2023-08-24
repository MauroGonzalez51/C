#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct Element {
    char item;
    int number;
    struct Element *nextElement;
} Element;

#endif
