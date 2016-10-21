/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nodeSong.h"
#include "playlist.h"

song_node *table[26];



void add_song(char *song, char *singer) {
  table[singer[0] - 'a'] = insert_order(table[singer[0] - 'a'], singer, song);
  printf("ADDED SONG: Aritst: %s\t\tSong: %s\n", singer, song);
}

void delete_song(char *song, char *singer){
	table[singer[0] - 'a'] = remove_song(table[singer[0] - 'a'], singer, song);
	printf("SONG REMOVED ==>");
	printf("Artist: %s\t\tSong: %s\n", singer, song);
}

void delete_all(){
	int n = 0;
	for (;n<26;n++) free_list(table[n]);
	printf("REMOVED ALL SONGS\n");
}

song_node *search_song(char* song) {
  int n = 0;
  for (; n < 26; n++) {
    song_node *letter_node = table[n];
    song_node *try = search_name(letter_node, song);
    if (try)
      return try;
  }
  return 0;
}

song_node *search_artist(char* singer) {
  song_node *letter = table[singer[0] - 'a'];
  song_node *try = search_singer(letter, singer);
  if (try)
    return try;
  return 0;
}

void print_letter_songs(char letter) {
  printf("SONGS BEGINING WITH LETTER '%c':\n", letter);
  print_list(table[letter - 'a']);
}

void print_artist_songs(char *singer) {
  song_node *artist = search_artist(singer);
  if (artist) {
    while (artist) {
      if (strcmp(singer, artist->artist) == 0) 
		  printf("Artist: %s\t\tSong: %s\n", artist->artist, artist->name);
      else 
		  break;
      artist= artist->next;
    }
    printf("\n");
  }
}
void print_playlist() {
  char letter = 'a';
  for (; letter <= 'z'; letter++) print_letter_songs(letter);
}

void shuffle(int i) {
  printf(">> Shuffle Player (%d songs)\n", i);
  srand(time(NULL));

  char has_songs[26]; 
  int node_lens[26]; 
  int total_num = 0; //total number of songs 3
  int k = 0; // num of table nodes with songs in them 2
  int j = 0; // 'table' indexes with song nodes in them 

  for (; j < 26; j++)
    if (table[j]) {
      has_songs[k] = j;
      node_lens[k] = len(table[j]);
      total_num += len(table[j]);
      k++;
    }
  if (k == 0) return; //no songs at all in 'table'

  while (i) {
    int rand_count = (int)(total_num * (double)rand()/RAND_MAX);
    int curr_ind = 0;
    for (; curr_ind < k; curr_ind++) {
      if (rand_count - node_lens[curr_ind] < 0)
	break;
      else
	rand_count = rand_count - node_lens[curr_ind];
    }
    song_node *temp = table[has_songs[curr_ind]];
    while (rand_count) {
      temp= temp->next;
      rand_count--;
    }
    printf("\t");
    print_node(temp);
    i--;
  }
}
