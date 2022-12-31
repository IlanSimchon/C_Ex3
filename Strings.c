#include "Strings.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

#define false 0
#define  true 1

void print_similar_words(char *word);

int getLine(char s[LINE]){
    int j;
    for (j = 0; j < LINE ; j++) {
        *(s+j) = getchar();
       // printf("%c\n" , *(s+j));
        if(s[j] == '\n' || s[j] == '\r' ||  s[j] == EOF){
            s[j] = '\0';
            break;
        }
    }
    if(s[j] == EOF) return 0;
    return j-1;
}

int getword(char w[WORD]){
    char c;
    int j;
    for (j = 0; j < WORD; j++) {
        c = getchar();
    //    printf("%c\n", c);
//        if (c != '\n' && c != '\t' && c != ' ' && c != '\r' && c != EOF) {
        if (c == '\n' ||  c == '\t' || c == ' ' || c == EOF) {
            //if(c =='\n') j--;
                 *(w+j) = '\0';
//                  printf("%s" , w );
//                  printf(" len %d\n" , j);
                  return j;
            }
        else{
            *(w+j) = c;
        }
    }

    return j;
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
//    printf("%s" , t);
//    printf(" and ");
//    printf("%s\n" , s);
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
       // printf("%s\n" , w);
        if(similar(w , word , 1)){
            printf("%s\n" , w);
        }

    }

}










int main(){
    char word[WORD];
    char option;
    char garbeage[LINE];
    getword(word);
    option = getchar();
    getLine(garbeage);
    getLine(garbeage);
    if(option == 'a'){
        print_lines(word);
    }
    else {
        print_similar_words(word);

    }
    return 0;
}
