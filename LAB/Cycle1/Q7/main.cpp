#include <iostream>
#include "Music_player.h"
int main() {
    MusicPlayer m;
    m.create_ll();
    m.display_ll();
    m.sort();
    m.display_ll();
    return 0;
}
