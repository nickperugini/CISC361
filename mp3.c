#include "MP3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 128

mp3_t *head;

int main(int argc, char *argv[])
{

        int n;

        while (1)
        {

                printf("(1) To add a song\n(2) To delete a song\n(3) To print list\n(4) To print list inversely\n(5) To exit\n");
                char input[1];
                fgets(input, 10, stdin);
                int n = atoi(input);

                switch (n)
                {

                case 1:
                        addSong();
                        break;
                case 2:
                        removeSong();
                        break;
                case 3:
                        printDLL();
                        break;
                case 4:
                        printInverseDLL();
                        break;
                case 5:
                        delAll();
                        printf("Exiting program");
                        exit(0);
                default:
                        printf("\nInvalid input. Try Again: \n");
                }
        }
}
mp3_t *create()
{
        int nameLen;
        int artistLen;
        char name[BUFFERSIZE];
        char artist[BUFFERSIZE];

        mp3_t *tmp1 = (struct mp3 *)malloc(sizeof(struct mp3));
        tmp1->prev = NULL;
        tmp1->next = NULL;

        printf("Enter song name: ");
        if (fgets(name, BUFFERSIZE, stdin) != NULL)
        {
                nameLen = (int)strlen(name);
                name[nameLen - 1] = '\0';
                tmp1->name = (char *)malloc(nameLen);
                strcpy(tmp1->name, name);
        }
        fflush(stdin);
        printf("Enter artist name: ");
        if (fgets(artist, BUFFERSIZE, stdin) != NULL)
        {
                artistLen = (int)strlen(artist);
                artist[artistLen - 1] = '\0';
                tmp1->artist = (char *)malloc(artistLen);
                strcpy(tmp1->artist, artist);
        }

        printf("Enter song time: ");
        char input2[100];
        fgets(input2, 100, stdin);
        int time = atoi(input2);
        tmp1->time=time;


        printf("Enter year made: ");
        char input[100];
        fgets(input, 100, stdin);
        int year = atoi(input);
        tmp1->year=year;

        return tmp1;
}

void addSong()
{
        mp3_t *newNode = create();
        if (head == NULL)
        {
                head = newNode;
        }
        else
        {
                mp3_t *tmp = head;
                while (tmp->next != NULL)
                {
                        tmp = tmp->next;
                }
                tmp->next = newNode;
                newNode->prev = tmp;
        }
}

void removeSong()
{
        char toDel[BUFFERSIZE];
        int toDelLen;

        printf("Enter artist of song(s) you want to delete: ");
        if (fgets(toDel, BUFFERSIZE, stdin) != NULL)
        {
                toDelLen = (int)strlen(toDel);
                toDel[toDelLen - 1] = '\0';
                mp3_t *tmp1 = head;

                while (tmp1 != NULL){
                        mp3_t *delNode = NULL;
                        if (strcmp(tmp1->artist, toDel) == 0)
                        {
                                delNode = tmp1;
                                if (tmp1->prev == NULL && tmp1->next == NULL)
                                { //if prev and next null (first and only song)
                                        head = NULL;
                                }
                                else if (tmp1->prev == NULL && tmp1->next != NULL)
                                { //if prev null and next not null (first song)
                                        head = tmp1->next;
                                        tmp1->next->prev = NULL;
                                }
                                else if (tmp1->prev != NULL && tmp1->next != NULL)
                                { //if prev and next not null (middle song)
                                        tmp1->prev->next = tmp1->next;
                                        tmp1->next->prev = tmp1->prev;
                                }
                                else if (tmp1->prev != NULL && tmp1->next == NULL)
                                { //if prev not null and next null (end song)
                                        tmp1->prev->next = NULL;
                                }
                                tmp1=tmp1->next;

                                printf("\nDeleting: [%s] \n", delNode->name);
                                free(delNode->name);
                                free(delNode->artist);
                                free(delNode);
                                printf("\n-----------\n");
                        }
                        else{
                                tmp1 = tmp1->next;
                        }
                }
        }
}


void printDLL()
{
	if (head == NULL)
	{
		printf("Nothing to print \n");
	}
	else
	{
		mp3_t *tmp1 = head;
		while (tmp1 != NULL)
		{
			printf("Name: [%s] \n", tmp1->name);
			printf("Artist: [%s] \n", tmp1->artist);
			printf("Length: [%d] \n", tmp1->time);
			printf("Year: [%d] \n", tmp1->year);
			printf("-----------\n");
			tmp1 = tmp1->next;
		}
	}
}
void printInverseDLL()
{
	if (head == NULL)
	{
		printf("Nothing to print \n");
	}
	else
	{
		mp3_t *tmp1 = head;
		mp3_t *tmp2;
		while (tmp1 != NULL)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		while (tmp2 != NULL)
		{
			printf("Name: [%s] \n", tmp2->name);
			printf("Artist: [%s] \n", tmp2->artist);
			printf("Length: [%d] \n", tmp2->time);
			printf("Year: [%d] \n", tmp2->year);
			printf("-----------\n");
			tmp2 = tmp2->prev;
		}
	}
}

void delAll(){
        mp3_t *cur=head;

        while(cur!=NULL){
                mp3_t *next=cur->next;
                printf("Deleting: [%s] \n", cur->name);
                free(cur->name);
                free(cur->artist);
                free(cur);
                printf("\n-----------\n");
                cur=next;
        }
}
