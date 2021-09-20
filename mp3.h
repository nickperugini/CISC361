typedef struct mp3 {
	char *name;
	char *artist;
	int year;
	int time;
	struct mp3 *next;
	struct mp3 *prev;
}mp3_t;

mp3_t* create();
void addSong();
void removeSong();
void printDLL();
void printInverseDLL();
void delAll();
