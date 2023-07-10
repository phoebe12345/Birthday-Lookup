#include <stdlib.h> 
#include <string.h> 
#include "a3_birthdaylib.h"



Birthday* create_Birthday(short year, short month, short day,char* name, char* knownFor) {
    Birthday* BirthdayArray = (Birthday*)malloc(sizeof(Birthday));
   
    if (BirthdayArray != NULL) {
        BirthdayArray->year = year;
        BirthdayArray->month = month;
        BirthdayArray->day = day;
        BirthdayArray->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
        
        if (BirthdayArray->name != NULL) {
            strcpy(BirthdayArray->name, name);
        }
        BirthdayArray->knownFor = (char*)malloc(sizeof(char)*(strlen(knownFor)+1));
        
        if (BirthdayArray->knownFor != NULL) {
            strcpy(BirthdayArray->knownFor, knownFor);
        }
    }
    return BirthdayArray;
}
// given at bottom of the assignment 3 description 

void clear_Birthday(Birthday* BirthdayArray) {
    if(BirthdayArray == NULL){
        return;
    }
    else{
        BirthdayArray->year = -1;
        BirthdayArray->month = -1;
        BirthdayArray->day = -1;
        free(BirthdayArray->name);
        free(BirthdayArray->knownFor);

    // also given at bottom of assignment 3 description but I added 2 extra lines 
        
        
        
    }
    free(BirthdayArray);
    // if (BirthdayArray != NULL) {
    //     BirthdayArray->year = -1;
    //     BirthdayArray->month = -1;
    //     BirthdayArray->day = -1;
    //     free(BirthdayArray->name);
    //     free(BirthdayArray->knownFor);
    // }
}

int compareBirthdaysByName(const void *p1,const void *p2){
    char* name1 = ((Birthday*)p1)->name;
    char* name2 = ((Birthday*)p2)->name;
    return strcmp(name1,name2);
}

int compareBirthdaysByMD(const void *p1, const void *p2){
    int month1 = ((Birthday*)p1)->month;
    int month2 = ((Birthday*)p2)->month;
    int day1 = ((Birthday*)p1)->day;
    int day2 = ((Birthday*)p2)->day;

    if(month1 == month2){
        return day1 - day2;
    }
    else{
        return month1 - month2;
    }
    // there is a easier way to write this with a question mark but I didnt nuderstand it 


}