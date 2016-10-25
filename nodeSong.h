
struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};
typedef struct song_node song_node;




song_node* new_song( song_node *n , char* song, char* singer);

void print_node (song_node *n);
void print_list( song_node *n );

int len(song_node *n);
song_node* getNext(song_node *n);
song_node* getSong(song_node *n, int i);
char* getArtist(song_node *n);

song_node* insert_front( song_node *n, char* song, char* singer);
song_node* insert_order(song_node *n, char* song, char* singer);

song_node *search_singer(song_node *n, char *singer);
song_node *search_name(song_node *n, char *song);
song_node *random_song(song_node *n);

song_node* free_list( song_node *n );
song_node * remove_song(song_node *n, char *song, char *singer);
song_node *remove_i(song_node *n, int i);
