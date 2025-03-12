#include <stdio.h>
#include "student.h"

int main() {
    Student_t student1 = {
        "kovacs nora",
        "TH3O3I",
        "marosvasarhely",
        {2005, 5, 2},
        FEMALE,
        8.50
    };

    printStudent(student1);
    printf("\n");

    Student_t student2;
    if (!freopen("student.txt", "r", stdin)) {
        printf("error");
        exit(-1);
    }

    readStudentDetails(&student2);
    freopen("CON", "r", stdin);
    printStudent(student2);
    printf("\n");

    Student_t *pStudents;
    int numberOfStudents;
    readAllStudentsDetails(&pStudents, &numberOfStudents, "students.txt" );
    printf("All students:\n");
    printAllStudents(pStudents, numberOfStudents, "CON");
    printAllStudents(pStudents, numberOfStudents, "all_students.txt");

    calculatePercentageBoysGirls(&pStudents, numberOfStudents);
    printf("\n");
    printf("\n");
    printf("Students born in budapest:\n");
    printStudentsFromSpecificCity(pStudents, numberOfStudents, "Budapest");
    printf("\n");

    Student_t *result = findStudentByNeptunCode(pStudents, numberOfStudents, "QSTRG9");
    if (result == NULL ) {
        printf("this student doesn't exist");
    }
    else {
        printf("QSTRG9 student: ");
        printf("\n");
        printStudent(*result);
    }
    printf("\n");

    Student_t *result2 = findStudentByNeptunCode(pStudents, numberOfStudents, "QSTSG9");
    if (result2 == NULL ) {
        printf("QSTSG9 student doesn't exist");
    }
    else {
        printf("QSTSG9 student: ");
        printf("\n");
        printStudent(*result2);
    }
    printf("\n");
    printf("\n");

    sortStudentsByName(pStudents, numberOfStudents);
    printAllStudents(pStudents, numberOfStudents, "abc_order.txt");
    printf("\n");
    printf("\n");

    sortStudentsByAgeAndExam(pStudents, numberOfStudents);
    printAllStudents(pStudents, numberOfStudents, "birth_exam_order.txt");


    return 0;
}

