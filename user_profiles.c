#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user_profiles.h"
#include "welcome_ui.h"

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define USER_DATA_FILE "users.dat"

void displayUsers() {
    FILE *file = fopen(USER_DATA_FILE, "r");
    if (!file) {
        printf("No users found.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s", username) != EOF) {
        printf("- %s\n", username);// use or EOF to end teh loop execution
    }

    fclose(file);
}

int userExists(char *username) {
    FILE *file = fopen(USER_DATA_FILE, "r");
    if (!file) return 0;

    char storedUsername[MAX_USERNAME_LENGTH];
    while (fscanf(file, "%s", storedUsername) != EOF) {
        if (strcmp(username, storedUsername) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void createUser(char *username) {
    FILE *file = fopen(USER_DATA_FILE, "a");
    if (file) {
        fprintf(file, "%s\n", username);
        fclose(file);
    }
}

void handleUserLogin(User *user) {
    int choice;
    char username[MAX_USERNAME_LENGTH];

    printf(CYAN"1. Login\n");
    printf(GREEN"2. Register\n");
    printf(MAGENTA"Enter your choice: "RESET);
    scanf("%d", &choice);
    getchar();  

    if (choice == 1) {
        printf("Enter your ");
        printf(RED"username: "RESET);
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;  

        if (userExists(username)) {
            printf("Login successful! Welcome back, %s\n", username);
            strcpy(user->username, username);
        } else {
            printf("Username not found. Please register first.\n");
            handleUserLogin(user);
        }
    } else if (choice == 2) {
        printf("Enter your new username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;

        if (userExists(username)) {
            printf("Username already exists. Try logging in instead.\n");
            handleUserLogin(user);
        } else {
            createUser(username);
            printf("Registration successful! Welcome, %s\n", username);
            strcpy(user->username, username);
        }
    } else {
        printf("Invalid choice. Try again.\n");
        handleUserLogin(user);
    }
}
