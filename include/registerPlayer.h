#include <string>
#include <vector>

#ifndef REGISTERPLAYER
#define REGISTERPLAYER

typedef struct Player {
  std::string name;
  std::string surname;
  std::string username;
  bool playing = false;
  //  int32_t currentPoints = 0;
  // uint32_t looses = 0;
  // uint32_t wins = 0;

} player;

std::vector<player> getPlayersData();

bool compare(player a, player b);

void postPlayer(std::string &name, std::string &surname, std::string &username,
                std::vector<player> &playersData);

void showPlayers();

#endif
