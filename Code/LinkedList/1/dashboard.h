#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_linked_list.h"
#include "static_linked_list.h"
#include "functions.h"
#include "selected_course.h"

void showAllCourses(DynamicLinkedList *list);
void selectCourse(DynamicLinkedList *list);

#endif