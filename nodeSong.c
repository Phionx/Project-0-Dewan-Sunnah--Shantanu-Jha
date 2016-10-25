#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "nodeSong.h"


//CREATING NEW SONG NODE ===================================================================
song_node* new_song( song_node *n, char* song, char* singer) {
	song_node *temp = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(temp->name, song);
	strcpy(temp->artist, singer);
	temp->next = NULL;
	return temp;
}


//PRINTING ==================================================================================
void print_node (song_node *n) {
	if (n) {
    printf("\n\tARTIST: %s\t\tSONG: %s",n->artist, n->name);
	}
}

void print_list( song_node *n ) {
  printf("\nSTART========================================================-\\");
  if(!n) printf("\n\tNO SONGS");
  while(n) {
    print_node(n);
	n = n->next;
  }
  printf("\nEND==========================================================-/\n");
}


//GET FUNCTIONS ============================================================================
song_node* getNext(song_node *n){
  return  n->next;
}

song_node* getSong(song_node *n, int i){
	if (n) {int length = len(n); if (i < length) while (i) { n = n->next; i--;}}
  return n;
}

char* getArtist(song_node *n){
  return n->artist;
}


int len(song_node *n){
	int length = 0;
	while (n) {n=n->next;length++;}
	return length;
}
//INSERT FUNCTIONS ==========================================================================
song_node* insert_front( song_node *n, char* song, char* singer) {
	song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
	new->next = n;
	strcpy(new->name, song);
	strcpy(new->artist, singer);
	return new;
}


song_node* insert_order(song_node *n, char* song, char* singer) {
	song_node *temp2 = n;
	song_node *temp = n;

	if (!n || strcmp(n->artist, singer) > 0 || (strcmp(n->artist, singer) == 0 && strcmp(n->name, song) > 0)) return insert_front(n, song, singer);

	while (temp  && strcmp(temp->artist, singer) < 0) temp = temp->next;

	while (temp && strcmp(temp->name, song) <= 0 && strcmp(temp->artist, singer) == 0) temp = temp->next;
	while (temp2->next!=temp) temp2=temp2->next;

	temp2->next=insert_front(temp,song,singer);
	return n;
}


//FREEING SONG_NODE =========================================================================
song_node* free_list( song_node *n ) { 
	song_node *f = n;
	while(n){
		n=n->next;
		printf("\nFREEING: ARTIST: %s\t\tSONG: %s", f->artist, f->name);
		free(f);
		f = n;
	}
	return n;
}



song_node * remove_song(song_node *n, char *song, char *singer) {
	int length = len(n);
	song_node *temp;
	int i = 0;
	for (;i<length;i++){
		temp = getSong(n, i);
		if(strstr(temp->name, song) && strstr(temp->artist, singer)) return remove_i(n,i);
	}
	return n;
}

song_node *remove_i(song_node *n, int i){
	int length = len(n);
	song_node *temp = n;
	if (i < 0 || i > length - 1) return n;
	if (!i) {
		temp = n->next;
		free(n);
	} else {
		while (i - 1) {
			n = n->next;
			i--;
		}
		song_node* temp2 = n->next->next;
		free(n->next);
		n->next = temp2;
	}
	return temp;
}
//SEARCH FUNCTIONS  ==========================================================================
song_node *search_singer(song_node *n, char *singer){
	while (n) {
		if (strstr(n->artist, singer)) break;
		n = n->next;
	}
	return n;
}


song_node *search_name(song_node *n, char *song){	
	while (n) {
		if (strstr(n->name, song)) break;
		n = n->next;
	}
	return n;
}


song_node *random_song(song_node *n){
	if (n){
		int length = len(n);
		int random = rand()%length;
		int i = 0;
		for (; i < random; i++) n = n->next;
	}
	return n;
}

/*
int main(){
	song_node *testing;
	testing = new_song(testing, "aa", "bb");
	print_list(testing);
	testing = insert_order(testing, "dd", "bb");
	print_list(testing);
	testing = insert_order(testing, "cc", "bb");
	print_list(testing);
	testing = insert_order(testing, "bb", "cc");
	print_list(testing);
	printf("LENGTH: %d", len(testing));

	return 0;
}*/

