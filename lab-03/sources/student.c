//
// Created by norik on 3/6/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char *getGenderText(enum Gender gender) {
    switch (gender) {
        case FEMALE:
            return "FEMALE";
        case MALE:
            return "MALE";
        default:
            return "OTHER";
    }
}

void printStudent(Student_t student) {
    printf("Name: %s\n", student.name);
    printf("Neptun code: %s\n", student.neptunCode);
    printf("Birth place: %s\n", student.birthPlace);
    printf("Birth date: %d %d %d\n", student.birthDate.year, student.birthDate.month,student.birthDate.day);
    printf("Gender: %s\n", getGenderText(student.gender));
    printf("Exam result: %f\n", student.examResult);

}


void readStudentDetails(Student_t *pStudent) {
    scanf("\n%[^\n]", pStudent->name); //(*pStudent).gender //beolvas mindent  a sor vegeig, ezert nem kell %s
    scanf("%s\n", pStudent->neptunCode);
    scanf("%[^\n]", pStudent->birthPlace);
    scanf("%d %d %d", &pStudent->birthDate.year, &pStudent->birthDate.month, &pStudent->birthDate.day);
    scanf("%d", &pStudent->gender );
    scanf("%f", &pStudent->examResult);
}


void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t*) malloc(numberOfStudents * sizeof(Student_t));
    if (!(*dpStudents)){
        printf("error");
        exit(-1);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf("error when opening file");
        exit(-1);
    }

    scanf("%d", numberOfStudents);

    allocateMemoryForStudents( dpStudents, *numberOfStudents);

    for (int i=0;i < *numberOfStudents;++i) {
        readStudentDetails( &((*dpStudents)[i])); //(*dpStudents)+i
    }

    freopen("CON", "r", stdin);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i=0;i < numberOfStudents;++i) {
        printStudent(pStudents[i]);
        printf("\n");
    }

    freopen("CON", "w", stdout);
}



void deallocate(Student_t **pStudent) {
    free(*pStudent);
    *pStudent = NULL;
}

int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender) {
    int counter = 0;
    for (int i=0;i<numberOfStudents;++i) {
        if (pStudents[i].gender == gender) {
            counter++;
        }
    }
    return counter;
}

void calculatePercentageBoysGirls(Student_t **dpStudents, int numberOfStudents) {
    int counterBoys = getNumberOfStudentsByGender(*dpStudents, numberOfStudents, MALE);
    int counterGirls = getNumberOfStudentsByGender(*dpStudents, numberOfStudents, FEMALE);

    float per1 = ((float)counterBoys/numberOfStudents)* 100;
    float per2 = ((float)counterGirls/numberOfStudents)* 100;

    printf("%.0f%% of the students are male and %.0f%% is female", per1, per2);

}

void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city) {
    for (int i=0;i<numberOfStudents;i++) {
        if (strcmp(pStudents[i].birthPlace, city)==0) {
            printStudent(pStudents[i]);
            printf("\n");
        }
    }
}


void *findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *neptunCode) {
    for (int i=0;i<numberOfStudents;i++) {
        if (strcmp(pStudents[i].neptunCode, neptunCode) == 0) {
            return pStudents + i;
        }
    }
    return NULL;
}

int cmpByName(const void *p1, const void *p2) {
    Student_t *q1 = (Student_t *)p1;
    Student_t *q2 = (Student_t *)p2;

    return strcmp(q1->name, q2->name);
}

void sortStudentsByName(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), cmpByName);
}

int cmpByAge(const void *p1, const void *p2) {
    Student_t *q1 = (Student_t *)p1;
    Student_t *q2 = (Student_t *)p2;

    if (q1->birthDate.year == q2->birthDate.year) {
        if (q1->birthDate.month == q2->birthDate.month) {
            return q1->birthDate.day - q2->birthDate.day;
        }
        else return q1->birthDate.month - q2->birthDate.month;
    }
    else return q1->birthDate.year - q2->birthDate.year;
}

int cmpByExam(const void *p1, const void *p2) {
    Student_t *q1 = (Student_t *)p1;
    Student_t *q2 = (Student_t *)p2;

    if (q1->examResult > q2->examResult) {
        return -1;
    }
    else if(q1->examResult < q2->examResult) {
        return 1;
    }
    else return 0;
}

int cmpByAgeAndExam(const void *p1, const void *p2) {
    if (cmpByAge(p1, p2) == 0) {
        return cmpByExam(p1, p2);
    }
    else return cmpByAge(p1,p2);

}

void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), cmpByAgeAndExam);
}






