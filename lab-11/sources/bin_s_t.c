//
// Created by norik on 5/8/2025.
//
#include "../headers/bin_s_t.h"
//#include "../headers/barat.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

TreeNode *createNewNode(Barat newData) {
    TreeNode *newNode= (TreeNode *) malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("memory allocation error");
        exit(-1);
    }
    newNode->info = newData;
    newNode->left = newNode->right = NULL;

    return newNode;
}

TreeNode *insertTree(TreeNode *node, Barat newData) {
    if (node == NULL) {
        node = createNewNode(newData);
        return node;
    }

    if (strcmp(newData.nev, node->info.nev) < 0) {
        node -> left = insertTree(node->left, newData);
    }
    else node->right =  insertTree(node->right, newData);

    return node;
}

//abc sorrendbe legyenek kiirva
void printTree_inorder(TreeNode* node) {
    if (node != NULL) {
        printTree_inorder(node->left);

        // Egy barát adatainak kiírása táblázatosan
        printf("%-20s %4d-%02d-%02d   %c     %d\n",
               node->info.nev,
               node->info.szuletesiDatum.ev,
               node->info.szuletesiDatum.honap,
               node->info.szuletesiDatum.nap,
               node->info.nem,
               node->info.bulizas);

        printTree_inorder(node->right);
    }
}

int readFromFileTree(const char* filename, TreeNode** node) {
    FILE* fin = fopen(filename, "r");
    if (!fin) {
        perror("nem lehet megnyitni a fajlt!");
        return 0;
    }


    char sor[256]; // ide olvassuk be a sort
    while (fgets(sor, sizeof(sor), fin)) {
        if (sor[0] == '\n' || sor[0] == '\0') break;

        Barat b;

        if (sscanf(sor, "%99[^;];%d;%d;%d;%c;%d",
                   b.nev,
                   &b.szuletesiDatum.ev,
                   &b.szuletesiDatum.honap,
                   &b.szuletesiDatum.nap,
                   &b.nem,
                   &b.bulizas) == 6) {
            *node = insertTree(*node, b);  // beszúrás a fába
                   } else {
                       fprintf(stderr, "Hibás sor: %s\n", sor);
                   }
    }

    fclose(fin);
    return 1;
}

void destroyBinaryTree(TreeNode **root) {
    if ((*root) != NULL) {
        destroyBinaryTree(&(*root)->left);
        destroyBinaryTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

void countSuitableBaratTree(TreeNode *node, int *count) {
    int evszam = 2025;

    if (node == NULL) return;

    //bal oldal bejarasa
    countSuitableBaratTree(node->left, count);

    int kor = evszam - node->info.szuletesiDatum.ev;

    if (kor >= 20 && node->info.bulizas >= 5) {
        (*count)++;
    }

    //jobb oldal bejarasa
    countSuitableBaratTree(node->right, count);
}

void printSuitableBaratok(TreeNode *node) {
    if (node == NULL) return;

    printSuitableBaratok(node->left);

    int evszam = 2025;
    int kor = evszam - node->info.szuletesiDatum.ev;

    if (kor >= 20 && node->info.bulizas >= 5) {
        printf("%-20s %4d-%02d-%02d   %c     %d\n",
               node->info.nev,
               node->info.szuletesiDatum.ev,
               node->info.szuletesiDatum.honap,
               node->info.szuletesiDatum.nap,
               node->info.nem,
               node->info.bulizas);
    }

    printSuitableBaratok(node->right);
}

