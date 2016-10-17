#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


void print_list( song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%s",n->name );
    n = n->next;
  }
  printf("]\n");
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

 song_node *new;

  new->next = n;
  strcpy(new->name, song);
  strcpy(new->artist, singer);

  return new;
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

int main(){
  song_node *a;
  strcpy(a->name, "You say run");
  strcpy(a->artist, "bnha");
  a->next=0;
  print_list(a);
  return 0;
  
}
