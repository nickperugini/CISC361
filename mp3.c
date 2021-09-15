#include "MP3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 128

struct mp3 {
        char *name;
        char *artist;
        int year;
        int time;
        struct mp3 *next;
        struct mp3 *prev;
} *mp3_h,*tmp1,*tmp2,*tmp3;

int main (int argc, char *argv[]){

        mp3_h = NULL;
        int n;

        printf("To add a song type 1 \nTo delete a song type 2\nTo print list type 3\nTo print list inversely type 4\nTo exit type 5\n");
        scanf("%d", &n);

        while(1){

                printf("To add a song type 1 \nTo delete a song type 2\nTo print list type 3\nTo print list inversely type 4\nTo exit type 5\n");
                scanf("%d", &n);

                if(n==1){
                        addSong();
                }
                else if(n==2){
                        removeSong();
                }
                else if(n==3){
                        printDLL();
                }
                else if(n==4){
                        printInverseDLL();
                }
                else if(n==5){
                        printf("Exiting Program");
                        return 0;
                }
                else{
                        printf("Invalid input. Try Again");
                }
        }
}
void addSong(){
        int len;
        char  buffer[BUFFERSIZE];

        if(mp3_h==NULL){
                tmp1 = (struct *mp3)malloc(sizeof(struct mp3));

                printf("Enter song name: ");
                if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
                len = (int) strlen(buffer);
                buffer[len-1]='\0';
                tmp1->name = (char *)malloc(len);
                strcpy(tmp1->name, buffer);
                }
                printf("Enter artist name: ");
                if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
                len = (int) strlen(buffer);
                buffer[len-1]='\0';
                tmp1->name = (char *)malloc(len);
                strcpy(tmp1->artist, buffer);
                }
                printf("Enter year made: ");
                scanf("%d", &(tmp1->year));

                printf("Enter song time: ");
                scanf("%d", &(tmp1->time));

                mp3_h=tmp1;

                tmp1->prev=NULL;
                tmp1->next=NULL;
        }
}

void removeSong(){printf("2");}

void printDLL(){
        tmp1=mp3_h;
        while (tmp1!=NULL){
                printf("Name: [%s] \n",tmp1->name);
                tmp1=tmp1->next;
        }
}
void printInverseDLL(){
        tmp1=mp3_h;
        while (tmp1 != NULL) {
                tmp2 = node;
                tmp1 = tmp1->next;
        }i
        while (tmp2 != NULL){
                printf(printf("Name: [%s] \n",tmp2->name);
                tmp2=tmp2->prev;
        }
}
