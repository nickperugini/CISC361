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

		printf("To add a song type 1 \nTo delete a song type 2\nTo print list type 3\nTo print list inversely type 4\nTo exit type 5\n");
		scanf("%d", &n);

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
			printf("Exiting Program");
			exit(0);
		default:
			printf("Invalid input. Try Again: ");
		}
	}
}
mp3_t *create()
{
	int nameLen;
	int artistLen;
	char name[BUFFERSIZE];
	char artist[BUFFERSIZE];
	fflush(stdin); //issues with scanf before fgets causing song name input to be skipped(or misread)

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

	printf("Enter artist name: ");
	if (fgets(artist, BUFFERSIZE, stdin) != NULL)
	{
		artistLen = (int)strlen(artist);
		artist[artistLen - 1] = '\0';
		tmp1->artist = (char *)malloc(artistLen);
		strcpy(tmp1->artist, artist);
	}

	printf("Enter year made: ");
	scanf("%d", &(tmp1->year));

	printf("Enter song time: ");
	scanf("%d", &(tmp1->time));

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
	fflush(stdin);

	printf("Enter artist of song(s) you want to delete: ");
	if (fgets(toDel, BUFFERSIZE, stdin) != NULL)
	{
		toDelLen = (int)strlen(toDel);
		toDel[toDelLen - 1] = '\0';
		mp3_t *tmp1 = head;
		
		while (tmp1 != NULL)
		{
			if(strcmp(tmp1->artist, toDel)){
			
			if(tmp1->prev==NULL && tmp1->next==NULL){//if prev and next null (first and only song)
				head=NULL;
			}
			else if(tmp1->prev==NULL && tmp1->next!=NULL){//if prev null and next not null (first song)
				head=tmp1->next;
				tmp1->next->prev=NULL;
			}
			else if(tmp1->prev!=NULL && tmp1->next!=NULL){//if prev and next not null (middle song)
				tmp1->prev->next=tmp1->next;
				tmp1->next->prev=tmp1->prev;
			}
			else if(tmp1->prev!=NULL && tmp1->next==NULL){//if prev not null and next null (end song)
				tmp1->prev->next=NULL;
			}
			printf("Dleteing: [%s] \n", tmp1->name);
			/*free(tmp1->name);
			free(tmp1->artist);
			free(tmp1);*/
			tmp1=tmp1->next;
			printf("\n-----------\n");
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
