#ifndef MUSIC_MUSIC_PLAYER_H
#define MUSIC_MUSIC_PLAYER_H
#include <iostream>
using namespace std;
class Music {
    string album;
    string artist;
    int year;
    Music* link;
    public:
    Music();
    Music(string album,string artist,int year);
    void set_album(string album);
    void set_artist(string artist);
    void set_year(int year);
    string get_album();
    string get_artist();
    int get_year();
    void set_link(Music* link);
    Music* get_link();
};

class MusicPlayer {
    Music* head;
    void swap(Music* current, Music* next_node);
    public:
    MusicPlayer();
    Music* get_head();
    void create_ll();
    void display_ll();
    void sort();

};

#endif //MUSIC_MUSIC_PLAYER_H
