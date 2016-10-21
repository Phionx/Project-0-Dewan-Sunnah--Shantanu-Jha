#ifndef _NODESONG_H
#define _NODESONG_H

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


void print_list( song_node *n );


song_node* getNext(song_node *n);

char* getSong(song_node *n);

char* getArtist(song_node *n);

song_node* insert_front( song_node *n, char* song, char* singer);

song_node* free_list( song_node *n );
song_node* new_song( song_node *n , char* song, char* singer);

song_node* insert_order(song_node *n, char* song, char* singer);
song_node *search_artist(song_node *n, char *singer);


song_node *search_name(song_node *n, char *song);

int len(song_node *n);

song_node *random_song(song_node *n);
#endif
