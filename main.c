#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main() {
	//srand(time(NULL));


	printf("\nBUILDING UP SONG LIST ========================================================");
	song_node *music;
	music = new_song(music, "you say run", "bnha");

	music = insert_order(music, "sucker for pain","tonep");
	music = insert_order(music, "this is a song","tonep");
	music = insert_order(music, "numb","linkin park");
	music = insert_order(music, "radioactive", "imagine dragons");
	music = insert_order(music, "in the end","linkin park");
	music = insert_order(music, "breaking the habit","linkin park");
	music = insert_order(music, "Test","Done");
  
	print_list(music);
	

	printf("\nSEARCHING FOR SONGS ==========================================================\n");
	printf("\nradioactive:");
	print_node(search_name(music, "radioactive"));
	printf("\nlinkin park:");
	print_node(search_singer(music, "linkin park"));
	printf("\nRANDOM SONG!:");
	print_node(random_song(music));

	printf("\n\nREMOVING SONGS ===============================================================\n");
	printf("\nremoving this is a song:\n");
	music = remove_song(music, "this is a song", "tonep");
	printf("\nremoving this song is a dub:\n");
	print_list(music = remove_song(music, "this song is a dub", "whoops"));

	printf("\n\nFREE LIST ====================================================================\n");
	music = free_list(music);
	print_list(music);


	printf("\nPLAYLIST TESTING ===============================================================\n");
	playlist *tunes = init_music();
	printf("\nPLAYLIST AT THE BEGINNING:\n");
	print_playlist(tunes);
	printf("\nADDING SONGS:\n");
	
	tunes = add_song(tunes, "Sucker for pain","Tonep");
	tunes = add_song(tunes, "This is a song","Tonep");
	tunes = add_song(tunes, "Numb", "Linkin park");
	tunes = add_song(tunes, "Radioactive", "Imagine dragons");
	tunes = add_song(tunes, "In the end","Linkin park");
	tunes = add_song(tunes, "Breaking the habit","Linkin park");
	tunes = add_song(tunes, "Test","Long done");
	printf("\ntest A\n");
	print_playlist(tunes);	
	
	printf("\nSEARCH: ========================================================================\n");
	printf("\nSong: Numb:\n");
	print_node(search_song(tunes, "Numb"));
	printf("\nArtist: Linkin Park:\n");
	print_node(search_artist(tunes, "Linkin park"));
	
	printf("\nAll artists starting with \'I\' or \'L\':\n");
	print_letter_songs(tunes, 'I');
	print_letter_songs(tunes, 'L');

	printf("\nAll songs by Tonep:\n");
	print_artist_songs(tunes, "Tonep");



	printf("\nSHUFFLE ========================================================================\n");
	printf("\nShuffle 1\n");
	tunes = shuffle(tunes);
	print_list(tunes->shuffle);
	printf("\nShuffle 2\n");
	tunes = shuffle(tunes);
	print_list(tunes->shuffle);
	

	printf("\nREMOVING: ======================================================================\n");
	printf("\nremoving - Numb:\n");
	tunes = delete_song(tunes, "Numb", "Linkin park");
	print_playlist(tunes);

	printf("\nFREE ALL: ======================================================================\n");
	tunes = delete_all(tunes);
	print_playlist(tunes);

	


	/*
	print_playlist();

  printf("\t test for song searching by name and by artist and printing\n");
  printf("searching for radioactive\n");
  print_node(search_name(a, "radioactive"));
  printf("searching for numb\n");
  print_node(search_name(a, "numb"));
  printf("\t test for searching for songs by artist\n");
  printf("search for linkin park\n");
  print_node(search_artist("linkin park"));
  printf("searching for Ayman Noman\n");
 // print_node(find_song_artist(a, "Ayman Noman"));
  printf("\n");
  printf("\n");

  printf("\t test for random song\n");
  printf("Getting a random song\n");
  print_node(random_song(a));
  printf("getting another randomsong\n");
  print_node(random_song(a));
  printf("getting another another randomsong\n");
  print_node(random_song(a));
  printf("\n");
  printf("\n");

  printf("\t Test for deleting a node:\n\n");
  printf("deleting: Test\n");
  remove_song(a, "Test","Done");
  print_list(a);
  printf("\n");
  printf("\n");

  return 0;*/
}
