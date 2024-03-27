#include "Music_player.h"
Music::Music() {
    album = "";
    artist = "";
    year = 0;
}

Music::Music(string album, string artist, int year) {
    this->album=album;
    this->artist=artist;
    this->year = year;
}

void Music::set_album(string album) {
    this->album=album;
}

void Music::set_artist(string artist) {
    this->artist=artist;
}

void Music::set_year(int year) {
    this->year = year;
}

string Music::get_album() {
    return album;
}

string Music::get_artist() {
    return artist;
}

int Music::get_year() {
    return year;
}

void Music::set_link(Music *link) {
    this->link=link;
}

Music *Music::get_link() {
    return link;
}


MusicPlayer::MusicPlayer() {
    head = new Music;
}

Music *MusicPlayer::get_head() {
    return head;
}

void MusicPlayer::create_ll() {
    Music* current = head;
    int num;
    cout << "No of Elements:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        string x,y;
        int z;
        cout << "Enter Album:";
        cin >> x;
        cout << "Enter Artist:";
        cin >> y;
        cout << "Enter Year:";
        cin >> z;
        Music* node = new Music(x,y,z);
        current->set_link(node);
        current = node;
    }
}

void MusicPlayer::display_ll() {
    int i = 1;
    Music* current = head->get_link();
    cout<<"---------------------------"<<endl;
    while (current != nullptr) {
        cout<<"Album no :"<<i++<<endl;
        cout <<"Album :"<< current->get_album() <<endl;
        cout <<"Artist :"<< current->get_artist() <<endl;
        cout <<"Year :"<< current->get_year() <<endl;
        cout<<"---------------------------"<<endl;
        current = current->get_link();
    }
    cout << endl;
}

void MusicPlayer::sort() {
        bool swapped;
        do{
            swapped = false;
            Music* current = head->get_link();
            Music* next = nullptr;
            while (current->get_link()!=next){
                if(current->get_album()>current->get_link()->get_album()){
                    swap(current,current->get_link());
                    swapped = true;
                }
                current = current->get_link();
            }
            next = current;
        } while (swapped);
}

void MusicPlayer::swap(Music* current, Music* next_node) {
    string temp_album = current->get_album();
    string temp_artist = current->get_artist();
    int temp_year = current->get_year();
    current->set_album(next_node->get_album());
    current->set_artist(next_node->get_artist());
    current->set_year(next_node->get_year());
    next_node->set_album(temp_album);
    next_node->set_artist(temp_artist);
    next_node->set_year(temp_year);
}
