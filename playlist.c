/*
Dewan Sunnah & Shantanu Jha
Systems pd4
Project 0
2016-10-20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

//TABLE ================================================================================

playlist *init_music(){
	return (playlist *)calloc(1,sizeof(playlist));
}


//ADD SONG =============================================================================
playlist *add_song(playlist *tunes, char *song, char *singer) {
	int i = (*singer - 65)%26;
	tunes->songs[i] = insert_order(tunes->songs[i], song, singer);
	tunes->music = insert_order(tunes->music, song, singer);
	return tunes;
}

//DELETE SONG  =========================================================================
playlist *delete_song(playlist *tunes, char *song, char *singer){
	song_node *removed = remove_song(tunes->music, song, singer);
	song_node *temp;
	if(removed){
		tunes->music = removed;
		tunes->songs[(*singer-65)%26] = remove_song(tunes->songs[(*singer-65)%26], song, singer);
		return tunes;
	}
	return tunes;
}

	/*
	if(removed){
		tunes->music = removed;
		int n,m = 0;
		for(;n<26;n++){
			int length = len(tunes->songs[n]);
			for (;m<length;m++){
				temp = getSong(tunes->songs[n], m);
				if(strstr(temp->name, song) && strstr(temp->artist, singer)){
					tunes->songs[n] = remove_i(tunes->songs[n],m);
					return tunes;}}}}
	return NULL;
}*/

playlist *delete_all(playlist *tunes){
	int n = 0;
	for (;n<26;n++) {
		if (tunes->songs[n]) tunes->songs[n] = free_list(tunes->songs[n]);
		else free(tunes->songs[n]);
	}
	tunes->music = free_list(tunes->music);
	free(tunes);
	printf("REMOVED ALL SONGS\n");
	return tunes;
}

//SEARCH  ==============================================================================
song_node *search_song(playlist *tunes, char* song) {
  return search_name(tunes->music, song);
}

song_node *search_artist(playlist *tunes, char* singer) {
  return search_singer(tunes->music, singer);
}


//PRINT  ===============================================================================
void print_letter_songs(playlist *tunes, char letter) {
	int i = (letter - 65)%26;
	printf("LETTER: %c", i+65);
	print_list(tunes->songs[i]);
}

void print_artist_songs(playlist *tunes, char *singer) {
	song_node *artist = tunes->music;
	while (artist) {
		if(strstr(artist->artist, singer)) print_node(artist);
		artist=artist->next;
	}
}
void print_playlist(playlist *tunes) {
	printf("\nSTART PLAYLIST =================================================/---\\");
	int n = 0;
	for(;n<26;n++) { 
		if(tunes->songs[n]){
		printf("\n\tLETTER: %c", (char)(n+65));
		print_list(tunes->songs[n]);}
	}
	printf("\nEND PLAYLIST ===================================================\\---/\n");
}



//SHUFFLE  ==============================================================================

playlist* shuffle(playlist *tunes) {
	int *rand;
	rand = randomShuffleSet(rand, len(tunes->music));
	song_node *temp;
	int i = 0;
	tunes->shuffle = free_list(tunes->shuffle);
	for(;i<len(tunes->music);i++){
		temp =  getSong(tunes->music, rand[i]);
		tunes->shuffle = insert_front(tunes->shuffle, temp->name, temp->artist);
	}
	return tunes;
}

/*	song_node* temp = tunes->musc;
	int length = len(temp);
	int change[length];
	int n = 0; 
	
	for (; n < length; n++) change[n] = n;
	for (n = 0; n < 7 * l; i++) {
    int seed = rand()%l;
    int store = order[i%l];
    change[i%l] = order[seed];
    order[seed] = store;
  }
  node* ret = insert_front(NULL, 
			get_song(raw,order[0])->title,
			   get_song(raw,order[0])->artist);
  for (i = 1; i < l; i++) 
    ret = insert_front(ret, 
		       get_song(raw,order[i])->title,
		       get_song(raw,order[i])->artist);
  return ret;
  
	return NULL;
}*/

int *randomShuffleSet(int *elements, int max){
	int size = max;
	elements = malloc(sizeof(int)*size);

	for (int i = 0; i < size; ++i)
		elements[i] = i;

	for (int i = size - 1; i > 0; --i) {
		int w = rand()%i;
		int t = elements[i];
		elements[i] = elements[w];
		elements[w] = t;
	}
	return elements;
}
/*
int main (){
	playlist *test = init_music();
	add_song(test, "first", "try");
	print_playlist(test);

	
	return 0;
}*/
