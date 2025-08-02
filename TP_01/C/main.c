#include "include/user.h"


int main(int argc, char *argv[]) {
    user_s users_tab[MAX_USERS] = {0};
    int choices = -1;
    int i = 0;

    while (choices != 3) {
        printf("What do you want to do today ?\nCreate an user: 1\nPrint all users: 2\nEdit an user: 3\nExit: 4\n");
        scanf("%d", &choices);
        switch (choices) {
        case 1:
            if (i >= MAX_USERS) {
                printf("Max users reached !\n");
                break;
            }
            users_tab[i] = create_user();
            i++;
            break;
        case 2:
            print_users(users_tab);
            break;
        case 3:
            printf("Enter the id of the user you want to edit: ");
            int id;
            scanf("%d", &id);
            printf("What do you want to edit ?\n1: ID\n2: nickname\n3: Is_Admin\n");
            int value_to_edit = -1;
            scanf("%d", &value_to_edit);
            edit_user(users_tab, id, value_to_edit); //modifier pour recup le tableau complet
            break;
        case 4:
            printf("Bye bye !\n");
            return 0;
        default:
            printf("Dont play with me my boy !\n");
            break;
        }
        choices = -1;
    }

}