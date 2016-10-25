#include "nodeSong.h"
/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/




struct playlist {
	song_node *music;
	song_node *songs[26];
	song_node *shuffle;
};

typedef struct playlist playlist;

//INIT MUSIC ===============================================================
playlist *init_music();


//SONG HANDELING ===========================================================
playlist *add_song(playlist *tunes, char *song, char *singer);
playlist *delete_song(playlist *tunes, char *song, char *singer);
playlist *delete_all(playlist *tunes);


//SEARCH ===================================================================
song_node *search_song(playlist *tunes, char* song);
song_node *search_artist(playlist *tunes, char* singer);


//PRINTING =================================================================
void print_letter_songs(playlist *tunes, char letter);
void print_artist_songs(playlist *tunes, char *singer);
void print_playlist(playlist *tunes);


//SHUFFLING ================================================================
playlist *shuffle(playlist *tunes);


int *randomShuffleSet(int *elements, int max);
