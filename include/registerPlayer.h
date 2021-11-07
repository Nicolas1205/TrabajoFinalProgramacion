#include <string>
#include <vector>

#ifndef REGISTERPLAYER
#define REGISTERPLAYER

typedef struct Player {
  std::string name;
  std::string surname;
  std::string username;
  bool playing = false;
  uint32_t points = 0;
  uint32_t turns = 1;

} Player;

std::vector<Player> get_players_data();

bool compare(Player a, Player b);

void post_player(std::string &name, std::string &surname, std::string &username,
                 std::vector<Player> &playersData);

void show_players();

#endif
