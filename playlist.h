#ifndef _PLAYLIST_H
#define _PLAYLIST_H
#include "nodeSong.h"
/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/



void add_song(char* artist, char* name);
void delete_song(char *artist, char *name);
void delete_all();

song_node *search_song(char *artist, char* name);
song_node *search_artist(char* artist);

void print_song(char *artist, char *name);
void print_artist(char *artist);
void print_letter(char c);
void print_library();

void shuffle(int i);

#endif
