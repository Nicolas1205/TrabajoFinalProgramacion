#include <string>
#include <vector>
#ifndef REGISTERPLAYER
#define REGISTERPLAYER

typedef struct {
  std::string name, surname, username;
  bool playing = false;
  int points = 0;
  int turns = 1;
  int nothing_catched = 0;

} Player;

std::vector<Player> get_players_data();

bool compare(Player a, Player b);

void post_player(std::string name, std::string surname, std::string username,
                 std::vector<Player> &players_data);

void show_players();

#endif
