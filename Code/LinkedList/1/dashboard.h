#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_linked_list.h"
#include "functions.h"
#include "static_linked_list.h"
#include "selected_course.h"

void showAllCourses(DynamicLinkedList *list);
void selectCourse(DynamicLinkedList *list);
int selectedCourseExists();
int printSelectedCourse();
void modifyCourse();
void deleteCourse(DynamicLinkedList *list);
void showAllStudentsInSelectedCourse();

void insertStudent(StaticLinkedList *list);

void deleteStudent();
void modifyStudent();

void averagePerCourse(DynamicLinkedList *list);
void averageInSelectedCourse();
void showAllStudents(DynamicLinkedList *list);

#endif