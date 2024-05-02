#include <stdio.h>
#include <string.h> //strcmp compare deux chaines de carac et strlen donne la longueur d'une chaine de carac
#include <stdbool.h>  //Permet d'utiliser la fonction booléenne
#include <unistd.h>

char password[] = "azerty12";

// Déclare une fonction qui compare le mot de passe entré par l'utilisateur avec le mot de passe stocké
bool compare(char user_pass[]){
    if (strcmp(user_pass, password) == 0){ // Si le mot de passe entré par l'utilisateur est le même que le mot de passe stocké
        printf("Bravo, tu as trouve le mot de passe\n");
        return true;
    } else {
        printf("Cherche encore\n");
        return false;
    }
}

// Déclare une fonction qui trouve et affiche les caractères communs dans le bon ordre entre le mot de passe entré par l'utilisateur et le mot de passe stocké
void element_commun(char user_pass[]){
    int i; // Déclare une variable de type entier pour la boucle
    printf("Les caracteres communs dans le bon ordre sont : ");
    for(i = 0; i < strlen(password); i++){ // Parcourt chaque caractère du mot de passe stocké
        printf("%c ", (i < strlen(user_pass) && password[i] == user_pass[i]) ? password[i] : '_'); // Affiche le caractère commun si il y en a un, sinon affiche un _
    }
    printf("\n");
}

// Déclare la fonction principale du programme
int main(){
    char user_pass[50]; // Déclare une variable de type tableau de caractères pour stocker le mot de passe entré par l'utilisateur
    bool guessed = false;
    while(!guessed){
        printf("devine le mot de passe : \n");
        scanf("%s", user_pass); // Lit le mot de passe entré par l'utilisateur
        element_commun(user_pass);
        guessed = compare(user_pass);
    }
    sleep(5);
    return 0;
}