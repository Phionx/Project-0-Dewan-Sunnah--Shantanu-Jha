#ifndef _PLAYLIST_H
#define _PLAYLIST_H
#include "nodeSong.h"
/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/







void add_song(char *song, char *singer);
void delete_song(char *song, char *singer);

void delete_all();

song_node *search_song(char* song);

song_node *search_artist(char* singer);

void print_letter_songs(char letter);

void print_artist_songs(char *singer);
void print_playlist();

void shuffle(int i);


#endif
