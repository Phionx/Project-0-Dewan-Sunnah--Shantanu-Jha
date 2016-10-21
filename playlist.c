/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

song_node *table[26];


void add_song(song_node* n) {
    char i = artist_index(n->artist[0]);
    table[i] = insert_ordered(table[i], from_song(n));
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
    song_node *try = find_song(letter_node, name);
    if (try)
      return try;
  }
  return 0;
}

song_node *search_artist(char* singer) {
  song_node *letter = table[artist[0] - 'a'];
  song_node *try = find_artist(letter, singer);
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
      if (strcmp(artist, artist->artist) == 0) 
		  printf("Artist: %s\t\tSong: %s\n", artist->artist, artist->name);
      else 
		  break;
      artist= artist->next;
    }
    printf("\n");
  }
}
void print_library() {
  char letter = 'a';
  for (; letter <= 'z'; letter++) print_letter_songs(letter);
}

// shuffle
void shuffle(int i) {
  srand(time(NULL));

  char songs[26];
  int i = 0;
  int j = 0;
  for (; table[j]; j++){
    if (table[j]) {
      songs[k] = j;
      i++;
    }
  }

  int letter_songs = i;
  for (; i < 26; i++)
    songs[i] = -1;
  
  if (!letter_songs) return;
	
  while (i) {
    int rand = songs[(int)(letter_songs * ((double)rand()/RAND_MAX) )];
    song_node *rand = find_random(table[rand]);
    printf("Aritist: %s\t\tSong: %s\n", rand_song->artist, rand_song->name);
    i--;
  }
  
  
  printf("\n");
}

}
