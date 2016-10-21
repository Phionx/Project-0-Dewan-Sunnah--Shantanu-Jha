#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeSong.h"

void print_node (song_node *n) {
	if (n) {
    printf("Name: %s\t\tArtist: %s\n",n->name, n->artist);
	}
}

void print_list( song_node *n ) {

  if(n) {
    print_node(n);
	print_list(n->next);
	n = n->next;
  }
}

song_node* getNext(song_node *n){
  return  n->next;
}

char* getSong(song_node *n){
  return n->name;
}

char* getArtist(song_node *n){
  return n->artist;
}

song_node* insert_front( song_node *n, char* song, char* singer) {
	song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
	new->next = n;
	strcpy(new->name, song);
	strcpy(new->artist, singer);
	return new;
}

song_node* insert_order(song_node *n, char* song, char* singer) {
	song_node *behind = n;
	song_node *temp = n;

	if (!n){ n = insert_front(n, song, singer); return n;} //NULL empty linked list
	if (strcmp(n->artist, singer) > 0) {
		n = insert_front(n, song, singer);
		return n;
	}

	while (temp && strcmp(temp->artist, singer) <= 0) temp = temp->next;
	while (temp && strcmp(temp->name, song) <=0 && strcmp(temp->artist, singer) == 0) temp = temp->next;

	while (behind->next!=temp) behind=behind->next;
	
	behind->next=insert_front(temp,song,singer);
	return n;
}


	


song_node* free_list( song_node *n ) { 
  song_node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing song_node %s", f->name );
    free(f);
    f = n;    
  }
  return n;
}

song_node* new_song( song_node *n, char* song, char* singer) {
	song_node *temp = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(temp->name, song);
	strcpy(temp->artist, singer);
	temp->next = NULL;
	return temp;
}


song_node *search_artist(song_node *n, char *singer){
	song_node *temp = n;
	while (temp) {
		if (temp->artist == singer) return temp;
		temp = temp->next;
	}
	return 0;
}


song_node *search_name(song_node *n, char *song){
	song_node *temp = n;
	while (temp) {
		if (temp->name == song) return temp;
		temp = temp->next;
	}
	return 0;
}

int len(song_node *n){
	int length = 0;
	while (n) {n=n->next;length++;}
	return length;
}

song_node *random_song(song_node *n){
	int random;
	int length = len(n);
	for(random = rand()%length;random;random--, n=n->next);
	return n;
}

song_node * remove_song(song_node *n, char *singer, char *song) {
  if (strcmp(song, n->name) == 0 && strcmp(singer, n->artist) == 0)
    return n->next;
  
  song_node *ret = n; 
  while (n->next) {
    if (strcmp(song, (n->next)->name) == 0 && 
	strcmp(singer, (n->next)->artist) == 0) {
      n->next = (n->next)->next;
      return ret;
    }
    else
      n=n->next;
  }
  return ret;
}

