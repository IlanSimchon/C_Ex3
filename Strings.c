#include "Strings.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

#define false 0
#define  true 1

int main(){
    char word[WORD];
    char option;
    char garbeage[LINE];
    getword(word);
    option = getchar();
    getLine(garbeage);
    getLine(garbeage);
    switch (option) {
        case 'a':
            print_lines(word);
            break;
        case 'b':
            print_similar_words(word);
            break;
        default:
            printf("Your input does not match");

    }
    return 0;
}

int getLine(char s[LINE]) {
    int j = 0;
    scanf("%c", &s[j]);
    while (j < LINE && s[j] != '\n' && s[j] != '\r') {
        j++;
        if (scanf("%c", &s[j]) == EOF) {
            s[j] = '\0';
            return 0;
        }
    }

    s[j] = '\0';
    return j + 1;
}

int getword(char w[]) {
    int j = 0;
    scanf("%c", &w[j]);
    while (j < WORD && w[j] != '\n' && w[j] != '\r' && w[j] != '\t' && w[j] != ' '){
        j++;

        if (scanf("%c", &w[j]) == EOF) {
            w[j] = '\0';
            return 0;
        }

    }
    w[j] = '\0';
    return j+1;
}

int substring(char * str1 , char * str2){
    int index1 = 0;
    int index2 = 0 ;
    while (index1 < strlen(str1) ) {
        if(str1[index1] == str2[index2]){
            index1++;
            index2++;
        }
        else{
            index2 = 0;
            if(str1[index1] != str2[index2]) index1++;
        }
        if(index2 == strlen(str2)) return true;
    }
    return false;
}

int similar(char *s , char *t , int n){
    if(strlen(s) < strlen(t)) return false;
    if(strlen(s) == strlen(t)) return !strcmp(s , t);
    int count = 0;
    int index1 = 0 , index2 = 0;
    while(s[index1]){
        if(s[index1] == t[index2]){
            index1++;
            index2++;
        }
        else {
            count++;
            index1++;
        }
    }
    return count == n;
}
void print_lines(char * str) {
    int len = -1;
    char s[LINE];
    while (len != 0) {
        len = getLine(s);
        if(substring(s , str)) {
            printf("%s\n", s);
        }
    }


}

void print_similar_words(char *word) {
    char w[WORD];
    int len = -1;
    while (len != 0){
        len = getword(w);
        if(similar(w , word , 1)){
            printf("%s\n" , w);
        }
    }
}
