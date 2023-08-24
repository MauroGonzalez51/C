#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct Element {
    char *item;
    float number;
    struct Element *nextElement;
} Element;

#endif
