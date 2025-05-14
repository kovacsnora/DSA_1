#include <stdio.h>
#include "headers/lista.h"
#include "headers/bin_s_t.h"

//binaris kereso fa
int main() {
    TreeNode* fa = NULL;

    if (!readFromFileTree("baratok.txt", &fa)) {
        printf("Nem sikerült beolvasni a fájlt.\n");
        return 1;
    }

    printTree_inorder(fa);
    int buliCount = 0;

    countSuitableBaratTree(fa, &buliCount);

    if (buliCount >= 10) {
        printf("Van elegendo barat a bulihoz (%d fo):\n", buliCount);
        printSuitableBaratok(fa);
    } else {
        printf("Nincs elegendo barat a bulihoz.\n");
    }

    destroyBinaryTree(&fa);
    return 0;
}

/*
//lista
int main() {
    Node* lista = NULL;

    if (!readFromFile("baratok.txt", &lista)) {
        printf("Nem sikerült beolvasni a fájlt.\n");
        return 1;
    }

    printList(lista);
    int buliCount = 0;
    countSuitableBarat(lista, &buliCount);
    destroy_list(&lista);

    return 0;
}
*/