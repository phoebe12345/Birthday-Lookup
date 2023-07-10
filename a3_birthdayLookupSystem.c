#include <stdio.h>
#include <stdlib.h>
#include "a3_birthdaylib.h"

void PrintBanner(){
    printf("====================================================\n");
    printf("================Student ID:301558325================\n");
    printf("================Name:Phoebe (Xu) Han================\n");
    printf("=============|-----------------------|==============\n");
    printf("=============|~BIRTHDAY LOOKUP SYSTEM|==============\n");
    printf("=============|-----------------------|==============\n");
    printf("===============SFU MAIL: xha91@sfu.ca===============\n");
    printf("====================================================\n");


}

int main(){
    PrintBanner();
    int option = 0;
    int cap = 16;
    Birthday* BirthdayArray = (Birthday*)malloc(sizeof(Birthday)*cap);

    while(option != 6){
        printf("\n1. Load a birthday file");
        printf("\n2. Birthday list sorted by month-day ");
        printf("\n3. Birthday list sorted by name");
        printf("\n4. Search for birthday (enter mm-dd)");
        printf("\n5. Exit the Program");
        printf("\nEnter a number between 1-5 to choose an option: ");
        scanf("%d", & option);

        //memory cap variables
        int used;
        int counter;

        //some initilinig stuff

        char fileName[100];
        short year;
        short month;
        short day;
        char knownFor[100];
        char name[100];
        
        //these are needed for part 4 or "option" 4
        int searchforday;
        int searchformonth;
        int foundcounter ;

        

        // use switch to avoid using 3 million if loops 
        // formatted like switch(option){
            // case 1:
            // case 2:
            //.....
        //}
        switch(option){
            case 1:
                // load file option
                printf("please enter a file name to load (including extension): ");
                scanf("%s",fileName);
                //scans for whatever use inputs 
                FILE *file;
                if((file = fopen(fileName,"r")) == NULL){
                    //if the file is not found then tell user that the file isnt found 
                    printf("\nError 404, The file you have entered does not exist, try another one\n");
                    break;
                }

                used = 0;
                cap = 16;
                counter = 0;
                int i = 0;
                
                while(fscanf(file, "%hd,%hd,%hd\n%[^\n]%*c\n%[^\n]%*c", &year, &month, &day, name, knownFor) ==5){
                    //used from lsat hw 
                    // make birthday index
                    BirthdayArray[i] = *create_Birthday(year, month, day, name, knownFor);
                    used += sizeof(BirthdayArray[i]);
                    if (used >= cap * sizeof(Birthday)){
                        cap *=2;
                        BirthdayArray = (Birthday*)realloc(BirthdayArray, sizeof(Birthday)*cap);

                    }
                    counter++;
                    i++;

                }
                // close file
                fclose(file);
                free(BirthdayArray);
                
                printf("\n%d entries loaded",counter);
                break;
            
            case 2:// the one that sorts birthday in date order 
            //opens files checks if empty blah blah blah (the same stuff as in part 1)
            if((file = fopen(fileName,"r"))==NULL){
                printf("invalid file");
            }
            else{

                file = fopen(fileName,"r");
                used = 0;
                cap = 16;
                counter = 0;
                int i = 0;
                while(fscanf(file, "%hd,%hd,%hd\n%[^\n]%*c\n%[^\n]%*c", &year, &month, &day, name, knownFor) ==5){
                    //used from lsat hw 
                    // make birthday index
                    BirthdayArray[i] = *create_Birthday(year, month, day, name, knownFor);
                    used += sizeof(BirthdayArray[i]);
                    if (used >= cap * sizeof(Birthday)){
                        cap *=2;
                        BirthdayArray = (Birthday*)realloc(BirthdayArray, sizeof(Birthday)*cap);

                    }
                    counter++;
                    i++;

                }
                fclose(file);
                free(BirthdayArray);

                qsort(BirthdayArray,counter, sizeof(Birthday), compareBirthdaysByMD);
                // uses quick sort and the function written to short by date 
                printf("\nBirthdays sorted by month\n");
                for (int i = 0; i < counter; i++){
                    printf("\n%d-%d-%d\n%s\n%s", BirthdayArray[i].year, BirthdayArray[i].month, BirthdayArray[i].day, BirthdayArray[i].name, BirthdayArray[i].knownFor);
                    printf("\n======================================");
                    // some nice formatting 
                    clear_Birthday(&BirthdayArray[i]);
                    free(&BirthdayArray[i]);
                    free(&BirthdayArray[i].name);
                    free(&BirthdayArray[i].knownFor);
                   

                }
                free(BirthdayArray);
                
                break;
                // breaks out of loop

            }

            case 3:// same as part 2 but sorts but name insteaed
            if((file = fopen(fileName,"r"))==NULL){
                printf("\ninvalid file\n");
            }
            else{
                file = fopen(fileName,"r");
                used = 0;
                cap = 16;
                counter = 0;
                int i = 0;
                while(fscanf(file, "%hd,%hd,%hd\n%[^\n]%*c\n%[^\n]%*c", &year, &month, &day, name, knownFor) ==5){
                    //used from lsat hw 
                    // make birthday index
                    BirthdayArray[i] = *create_Birthday(year, month, day, name, knownFor);
                    used += sizeof(BirthdayArray[i]);
                    if (used >= cap * sizeof(Birthday)){
                        cap *=2;
                        BirthdayArray = (Birthday*)realloc(BirthdayArray, sizeof(Birthday)*cap);

                    }
                    counter++;
                    i++;

                }
                fclose(file);
                free(BirthdayArray);

                qsort(BirthdayArray, counter, sizeof(Birthday),compareBirthdaysByName);
                // sorts by name 
                for (int i = 0;i < counter; i++){
                    printf("\n%d-%d-%d\n%s\n%s\n",BirthdayArray[i].year, BirthdayArray[i].month, BirthdayArray[i].day, BirthdayArray[i].name, BirthdayArray[i].knownFor);
                    printf("=========================\n");

                    //more formatting 
                    clear_Birthday(&BirthdayArray[i]);
                    free(&BirthdayArray[i]);
                    free(&BirthdayArray[i].name);
                    free(&BirthdayArray[i].knownFor);
                    
                    
                }
                free(BirthdayArray);
                break;
            }
//===================================================================================================================
            case 4:
            //search for a persons birthday by date 
            //opens the file
            if((file = fopen(fileName,"r"))==NULL){
                //if the file opened is invalid return invalid file 
                printf("invalid file");
            }
            else{
                // otherwise 

                file = fopen(fileName,"r");
                used = 0;
                cap = 16;
                counter = 0;
                int i = 0;
                while(fscanf(file, "%hd,%hd,%hd\n%[^\n]%*c\n%[^\n]%*c", &year, &month, &day, name, knownFor) ==5){
                    //used from lsat hw 
                    // make birthday index
                    BirthdayArray[i] = *create_Birthday(year, month, day, name, knownFor);
                    used += sizeof(BirthdayArray[i]);
                    if (used >= cap * sizeof(Birthday)){
                        cap *=2;
                        BirthdayArray = (Birthday*)realloc(BirthdayArray, sizeof(Birthday)*cap);

                    }
                    counter++;
                    i++;

                }
                fclose(file);
                //the search begins
                

                printf("\nPlease enter a month and day seperated by a dash (m-d): ");
                scanf("%d-%d",&searchformonth,&searchforday);
                //scand then stores into variables i made earlier 

                for (int i = 0; i < counter; i++){
                    if(BirthdayArray[i].month == searchformonth && BirthdayArray[i].day == searchforday){
                        printf("\n%d-%d-%d\n%s\n%s\n", BirthdayArray[i].year,BirthdayArray[i].month, BirthdayArray[i].day, BirthdayArray[i].name, BirthdayArray[i].knownFor );
                        printf("\n=========================");
                        foundcounter = 0;
                        //count if found
                    }
                    clear_Birthday(&BirthdayArray[i]);
                    free(&BirthdayArray[i]);
                    free(&BirthdayArray[i].name);
                    free(&BirthdayArray[i].knownFor);

                    
                }
                
                if(foundcounter != 0){
                    printf("\nNo birthday found\n");
                    // if not found then no birthday found
                }
                free(BirthdayArray);
                // free the birthday arra y
                break;
            }
            
            case 5:
                printf("Exiting the Prgram...");
                // exits the program 
                printf("\nthank you for using the Birthday Lookup System\n");
                // thanks the user
                for (int i = 0;i < counter; i++){
                    clear_Birthday(&BirthdayArray[i]);
                    free(BirthdayArray[i].name);
                    free(BirthdayArray[i].knownFor);
                    // frees everything 

                }
                free(BirthdayArray);
                exit(0);// exist the code 
                break;
                

                default:
                    printf("invalid option. Please try again\n");
                    // default option for invalid choices 

                    break;




        }
        free(BirthdayArray);
        
 
    }

    
    
}