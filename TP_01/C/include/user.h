#ifndef USER_H // Si le user.h n'est pas définit
#define USER_H // On le définit
    #define MAX_USERS 100 // Nombre maximum d'utilisateurs
    #include <stdio.h> // les librairies nécessaires
    #include <string.h> // pour les chaines de caractères
    #include <stdbool.h> // pour les booléens
    #include <stdlib.h>

    typedef struct user_t {
        int id;
        char pseudo[30];
        bool isAdmin;
    } user_s;

    user_s create_user(void);
    void print_users(user_s *users);
    void edit_user(user_s users[], int id, int value);
#endif


