#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/


// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

int generer(int arr[9][9]){
    int nbr = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (arr[i][j] !=0){
                nbr = nbr + 1;
                printf("%d",rand() % 2);

            }
        }
    }
    return nbr;       
}
// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

int saisir(int remplissage,int arr[9][9]){
    int i;
    int j;
    int v;

    do {
        printf ("Numero de la ligne i :");
        scanf("%i", &i);
    }while (i >= 10 || i <= 0);

    do {
        printf ("Numero de la colonne j :");
        scanf ("%i", &j);
    }while (j >= 10 || j <= 0);

    do {
        printf ("Chiffre à inserer :");
        scanf ("%i", &v);
    } while (0 > v || v > 10 ) ;
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

int verifierLigneColonne(int num, const int dir, int arr[9][9]){
    int values[9][2] = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
    for(int i = 0; i < 9; i++){
        if (dir == 0){ //vérifie les doublons sur chaques lignes
            if(arr[num][i] == values [i][0]){
                values [i][1] += 1;
            }
        }else{ // vérifie les doublons sur les colonnes
            if(arr [i][num] == values [i][0]){
                values [i][1] += 1;
            }
        }
    }
    int len = sizeof(values)/ sizeof (values[0]);
    for(int k = 0; k < len; k++){
        if(values[k][1 != 1]){ //Vérifie s'il n'y a pas de doublons
            return 0;
        }
    }
    return 1; //il n'y a pas de doublons
}

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int k, int l, int arr[9][9]){
    int values[9][2] = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
    int x = k;
    int y= l;
    for(int i=0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int index = 0; index < 9; index++){
                if(arr [x][y] == values[index][0]){
                    values[index][1] += 1;
                }
            }
            y += 1;
        }
        x += 1;
        y = 1;
    }
    int len = sizeof(values) / sizeof(values [0]);
    for (int s = 0; s < len; s++){
        if (values [s][1] != 1){
            return 0;
        }
    }
    return 1;
}

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int arr[9][9]){
    int x;
    int y; 
    for (int i= 0; i<9; i++){
        int rows = verifierLigneColonne(i, 0, arr);
        int columns = verifierLigneColonne(1, 1, arr);
        int region = verifierRegion (x, y, arr);
    }
}

//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 

    int random = rand() %9 +1;
    int table[9][9] =
    {
        {9,0,0,1,0,0,0,0,5},
        {0,0,5,0,9,0,2,0,1},
        {8,0,0,0,4,0,0,0,0},
        {0,0,0,0,8,0,0,0,0},
        {0,0,0,7,0,0,0,0,0},
        {0,0,0,0,2,6,0,0,9},
        {2,0,0,3,0,0,0,0,6},
        {0,0,0,2,0,0,9,0,0},
        {0,0,1,9,0,4,5,7,0}
    };

    int remplissage = 0;

    saisir(remplissage, solution);



    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

