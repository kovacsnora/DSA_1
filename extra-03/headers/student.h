//
// Created by norik on 3/12/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Date {
    int year;
    int month;
    int day;
}Date_t;

typedef enum Gender {
    FEMALE, MALE
}Gender_t;

typedef struct Student {
    char name[50];
    char neptunCode[8];
    char birthPlace[25];
    Date_t birthDate;
    Gender_t gender;
    float examResult;
}Student_t;

void printStudent(Student_t student);
char *getGenderText(enum Gender gender);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readStudentDetails(Student_t *pStudent);
void readAllStudentsDetails(Student_t **dpStudents, int*numberOfStudents, const char *input);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents);
void deallocate(Student_t **pStudent);
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents);
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);
void *findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *neptunCode);
void sortStudentsByName(Student_t *pStudents, int numberOfStudents);
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents);
#endif //STUDENT_H
