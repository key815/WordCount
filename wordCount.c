#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

int count_char(char* input_str, int len) {
    int i, count = 0;
    for(i = 0; i < len; i++) {
        if(input_str[i] != '\n' && input_str[i] != '\t' && input_str[i] != ' ') {
            count++;
        }
    }
    return count;
}

int count_word(char* input_str, int len) {
    int i, count = 0, flag = 0;
    for(i = 0; i < len; i++) {
        if(input_str[i] != '\n' && input_str[i] != '\t' && input_str[i] != ' ' && input_str[i] != ',') {
            if(flag == 0) {
                count++;
                flag = 1;
            }
        } else {
            flag = 0;
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    FILE* fp;
    char input_file[MAX_SIZE];
    char input_str[MAX_SIZE];
    char parameter[4] = "\0";
    int len, count, i;
    if(argc < 2) {
        printf("Error: not enough parameters.\n");
        return -1;
    }
    if(argc > 3) {
        printf("Error: too many parameters.\n");
        return -1;
    }
    strcpy(parameter, argv[1]);
    if(strcmp(parameter, "-c") != 0 && strcmp(parameter, "-w") != 0) {
        printf("Error: invalid parameter.\n");
        return -1;
    }
    if(argc == 2) {
        strcpy(input_file, "input.txt");
    } else {
        strcpy(input_file, argv[2]);
    }
    fp = fopen(input_file, "r");
    if(fp == NULL) {
        printf("Error: cannot open file.\n");
        return -1;
    }
    len = fread(input_str, sizeof(char), MAX_SIZE, fp);
    if(len == MAX_SIZE) {
        printf("Error: file is too big.\n");
        return -1;
    }
    fclose(fp);
    if(strcmp(parameter, "-c") == 0) {
        count = count_char(input_str, len);
        printf("%d\n", count);
    } else {
        count = count_word(input_str, len);
        printf("%d\n", count);
    }
    return 0;
}

