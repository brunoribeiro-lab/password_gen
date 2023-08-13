#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define DEFAULT_LENGTH 8
#define DIGITS "0123456789"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SPECIAL_CHAR "!@#$%^&*()-_=+<>?/"

void show_help() {
    printf("Usage: ./init [OPTIONS]\n");
    printf("Generate a random password.\n\n");
    printf("Options:\n");
    printf("  -d       Use digits\n");
    printf("  -l       Use lowercase letters\n");
    printf("  -u       Use uppercase letters\n");
    printf("  -sp      Use special characters\n");
    printf("  -s SIZE  Specify the password size (default is 8)\n");
    printf("  -h, -help Show this help message\n");
}

void generate_password(int s, bool d, bool l, bool u, bool sp) {
    char pool[128] = ""; 
    char password[s + 1];

    if(d) {
        strcat(pool, DIGITS);
    }
    if(l) {
        strcat(pool, LOWERCASE);
    }
    if(u) {
        strcat(pool, UPPERCASE);
    }
    if(sp) {
        strcat(pool, SPECIAL_CHAR);
    }

    int pool_length = strlen(pool);
    for(int i = 0; i < s; i++) {
        password[i] = pool[rand() % pool_length];
    }

    password[s] = '\0';
    printf("Generated Password: %s\n", password);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int s = DEFAULT_LENGTH;
    bool d = true, l = true, u = true, sp = true;

    if(argc > 1) { 
        d = l = u = sp = false;
    }

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-d") == 0) {
            d = true;
        }
        else if(strcmp(argv[i], "-l") == 0) {
            l = true;
        }
        else if(strcmp(argv[i], "-u") == 0) {
            u = true;
        }
        else if(strcmp(argv[i], "-sp") == 0) {
            sp = true;
        }
        else if(strcmp(argv[i], "-s") == 0 && i+1 < argc) {
            s = atoi(argv[++i]);
        }
        else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-help") == 0) {
            show_help();
            return 0; 
        }
    }

    generate_password(s, d, l, u, sp);
    return 0;
}
