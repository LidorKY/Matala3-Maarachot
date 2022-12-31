#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LINE 256
#define WORD 30
#define length_of_text 250

int getLine (char s[LINE]){
    char temp = 'a';
    int i = 0;
    while((i < LINE)){
        temp = getchar();
        if((temp != '\n') && (temp != '\r')){
            s[i] = temp;
            i++;   
        }
        else{
            break;
        }
    }
    s[i] = '\0';
    return i;
}

int getWord(char w[WORD]){
    char temp = 'a';
    int i = 0;
    while((i < WORD)){
        temp = getchar();
        if((temp != '\n') && (temp != '\t') && (temp != ' ') && (temp != '\r')){
            w[i] = temp;
            i++;   
        }
        else{
            break;
        }
    }
    w[i] = '\0';
    return i;
}

int substring (char* str1, char* str2){
    int length1 = 0;
    length1 = strlen(str1);
    int length2 = 0;
    length2 = strlen(str2);

    for(int i = 0, j = 0; i < length1; i++){
        if(*(str2 + j) != *(str1 + i)){
            j = 0; 
        }
        if(*(str2 + j) == *(str1 + i)){
            j++; 
        }
        if(j == length2){
            return 1;
        }
    }
    return 0;
}

int similar (char *s, char *t, int n){
    int length1 = 0;
    length1 = strlen(s);
    int length2 = 0;
    length2 = strlen(t);
    int counter = 0;
    int j = 0;
    if(!strcmp(s,t)){
        return 1;
    }

    for(int i = 0; i < length1; i++){
        if((*(s + i) != *(t + j))){
            counter++;
        }
        if((*(s + i)) == (*(t + j))){
            j++; 
        }
    }
    if(counter != n){
        return 0;
    }
    if(j == length2){
        return 1;
    }
    return 0;
}

void printlines (char *str){
    char array[length_of_text][LINE] = {'0'};

    for(int i = 0; i < length_of_text-2; i++){
        getLine(array[i]);
        if(substring(array[i],str)){
            printf("%s\n",array[i]);
        }
    }
}

void print_similar_words(char *str){
    char array[length_of_text][LINE][WORD] = {'0'};
    
    for(int i = 0; i < length_of_text-2; i++){
        for(int j = 0; j < LINE; j++){
            getWord(array[i][j]);
            if(similar(array[i][j],str,1)){
                printf("%s\n",array[i][j]);
            }
        }
    }
}

int main(){
    char array[LINE] = {'0'};
    char array2[LINE] = {'0'};
    getLine(array);
    char temp = '1';
    int i;
    for(i = 0; i < LINE-2; i++){
        if(array[i] != ' '){
            array2[i] = array[i];
        }
        else{
            break;
        }
    }
    temp = array[i + 1];
    getLine(array);
    if(temp == 'a'){ 
    printlines(array2);
    }
    else{
    print_similar_words(array2);
    }
    return 0;
}