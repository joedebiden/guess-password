#include <stdio.h> // Inclut la bibliothèque standard d'entrée/sortie pour utiliser des fonctions comme printf et scanf
#include <string.h> // Inclut la bibliothèque de manipulation de chaînes pour utiliser des fonctions comme strcmp et strlen
#include <stdbool.h> // Inclut la bibliothèque standard bool pour utiliser le type de données booléen

char password[] = "azerty12"; // Déclare une variable globale de type tableau de caractères pour stocker le mot de passe

// Déclare une fonction qui compare le mot de passe entré par l'utilisateur avec le mot de passe stocké
bool compare(char user_pass[]){
    if (strcmp(user_pass, password) == 0){ // Si le mot de passe entré par l'utilisateur est le même que le mot de passe stocké
        printf("Bravo, tu as trouve le mot de passe\n"); // Affiche un message de réussite
        return true; // Retourne vrai
    } else { // Sinon
        printf("Cherche encore\n"); // Affiche un message d'échec
        return false; // Retourne faux
    }
}

// Déclare une fonction qui trouve et affiche les caractères communs dans le bon ordre entre le mot de passe entré par l'utilisateur et le mot de passe stocké
void element_commun(char user_pass[]){
    int i, j; // Déclare deux variables de type entier pour les boucles
    printf("Les caracteres communs dans le bon ordre sont : "); // Affiche un message
    for(i = 0; i < strlen(password); i++){ // Parcourt chaque caractère du mot de passe stocké
        for(j = 0; j < strlen(user_pass); j++){ // Parcourt chaque caractère du mot de passe entré par l'utilisateur
            if(password[i] == user_pass[j] && i == j){ // Si le caractère actuel du mot de passe stocké est le même que le caractère actuel du mot de passe entré par l'utilisateur et qu'ils sont à la même position
                printf("%c ", password[i]); // Affiche le caractère commun
            }
        }
    }
    printf("\n"); // Passe à la ligne suivante
}

// Déclare la fonction principale du programme
int main(){
    char user_pass[50]; // Déclare une variable de type tableau de caractères pour stocker le mot de passe entré par l'utilisateur
    bool guessed = false; // Déclare une variable de type booléen pour savoir si le mot de passe a été deviné
    while(!guessed){ // Tant que le mot de passe n'a pas été deviné
        printf("devine le mot de passe : \n"); // Demande à l'utilisateur de deviner le mot de passe
        scanf("%s", user_pass); // Lit le mot de passe entré par l'utilisateur
        element_commun(user_pass); // Appelle la fonction pour trouver et afficher les caractères communs dans le bon ordre
        guessed = compare(user_pass); // Appelle la fonction pour comparer le mot de passe entré par l'utilisateur avec le mot de passe stocké et stocke le résultat
    }
    return 0; // Termine le programme avec le code de sortie 0
}