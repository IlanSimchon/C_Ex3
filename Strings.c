<<<<<<< HEAD
#include "Strings.h"
#include <stdio.h>
#include <string.h>
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Strings.h"
>>>>>>> c7c26a1af96b1fb7b200e4e8120c1de7ddb0ba15

#define LINE 256
#define WORD 30

<<<<<<< HEAD
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
=======
/*
 * The method accepts a string (character by character) and stores it in the String S .
 * The method checks whether each received character meets the requirements not equally to '\n' and carries out a placement.
 * for each character and finally adds the character '\0' .
 * The function returns the last index meaning the amount of characters received.
 */
int getLine(char S[] , int limit){
int ch , index=0;
    while ((ch=getchar()) != EOF && ch !='\n') {
        if (index < limit-1) {
            S[index++] = ch;
        }
    }
    if (ch == '\n' && index <= limit-1){
            S[index++]=ch;
    }
    S[index] = 0;
    return index + 1;
}
/*
 * The method accepts a string (character by character) and stores it in the String W .
 * The method checks whether each received character meets the requirements not equally to '\n' , ' ' , '\t'
 * and carries out a placement.
 * for each character and finally adds the character '\0' .
 * The function returns the last index meaning the amount of characters received.
 */
int getWord(char W[] , int limit){
    int ch , index=0;
    while ((ch=getchar()) != EOF && ch !='\n' && ch != '\t' && ch != ' ') {
        if (index < limit-1){
            W[index++] = ch;
        }
    }
    W[index]=0;
    return index + 1;
}

/*
 * The function receives two strings str1 and str2 and checks whether str2 is contained in str1.
 * The function will return 1 if yes and 0- if not.
 */
int subString( char * str1, char * str2){
    if (! *str2) return 1;
    int flag = strstr( * str1,  * str2) ;
    if (flag) return 1;
    else return 0;
}
/*
 * The method will receive two strings s t and a number n.
 * The function will check if it is possible to get from the string S to the string t by omitting n characters.
 * For identical strings and the number 0 the program will return 1 only if the two strings are identical
 */
int similar (char *s, char *t, int n){
    int index;
    while (*s){
        index=0;
        while (*(t+1) != *s){
            if (!(*(t+1))) return 0 ;
            index++;
        }
        n-=index;
        s++;
        t=t+index+1;
    }
    return (n== strlen(t));
}
/*
 * The function receives the desired string for search, receives the text lines,
 * and prints the lines in which the string appears, using the relevant functions defined above
 */

void print_lines(char * str){
    char line [LINE];
    while (getLine(line,LINE)){
        if (subString(line,str)) {
            puts(line);
        }
    }
}
/*
 * The function receives the desired string for the search,
 * picks up the words of the text and prints the words similar to the search string up to the
 * omission of one letter from the words that appear in the text (including words identical to the search string).
 * The function will use the relevant functions defined above.
 */
void print_similar_words(char * str , int n){
    char word [WORD];
    int index ;
    while (getLine(word,LINE)){
        index=n;
        while (index>=0){
            if(similar(str,word,index)) {
                printf("%s\n", word);
            }
            index--;
            }
        }
    }

    int main () {
    char word[WORD];
    char choice;
    getWord(word,WORD);
    choice=getchar();
        getchar();
        getchar();
    if (choice != 'a' && choice != 'b'){
        printf("Something goes worng please try again\n");
        exit(1);
    }
    if (choice == 'a') {
        print_lines(word);
    }
    if (choice == 'b') {
        print_similar_words(word,1);
    }
    }

>>>>>>> c7c26a1af96b1fb7b200e4e8120c1de7ddb0ba15
