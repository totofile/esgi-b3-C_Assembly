#include "../include/user.h"

static bool admin_check()
{
    int is_admin = -1;
    bool is_valid = false;
    while (is_admin != 0 && is_admin != 1) {
        printf("Enter 1 if user is admin 0 if is not admin: ");
        scanf("%d", &is_admin);
        if (is_admin != 0 && is_admin != 1)
            printf("heuuuuuuu c'est pas ca hein\n");
    }
    return is_admin == 1 ? true : false;
}

user_s create_user(void)
{
    user_s user;
    int is_admin = -1;

    printf("Welcome !!!\n");
    printf("Enter an user ID :");
    scanf("%d", &user.id);
    printf("Enter your nickname: ");
    scanf("%s", user.pseudo);
    user.isAdmin = admin_check();
    return user;
}


void print_users(user_s *users)
{
    for (int i = 0; i < MAX_USERS; i++) { // i<100 car MAX_USERS est définit dans user.h
        if (users[i].id == 0 && users[i].pseudo[0] == '\0') {
            break;
        }
        printf("ID: %d\n", users[i].id);
        printf("Pseudo: %s\n", users[i].pseudo);
        printf("Is admin: %d\n", users[i].isAdmin);
    }
}

user_s* edit_user(user_s users[], int id, int value) // modifier pour corriger cette erreur car je ne renvoie pas le bon truc je dois recup le tab complet
{
    user_s user;
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].id == id) {
            user = users[i];
        }
    }
    switch (value)
    {
    case 0:
        printf("Enter a new ID: ");
        scanf("%d", &user.id);
        break;
    case 1:
        printf("Enter a new pseudo: ");
        scanf("%s", user.pseudo);
        break;
    case 2:
        user.isAdmin = admin_check();
        break;
    default:
        break;
    }
}
