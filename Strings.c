#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Strings.h"

#define LINE 256
#define WORD 30

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

