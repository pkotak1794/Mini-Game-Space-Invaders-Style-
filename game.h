#ifndef GAME_H
#define GAME_H
#include <vector>
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game() : Game(800, 600) {}
  Game(int width, int height) : screen(width, height) {}

  graphics::Image &GetGameScreen() { return screen; }
  std::vector<Opponent> &GetOpponents() { return myOpp; }
  std::vector<OpponentProjectile> &GetOpponentProjectiles() { return myOppPro; }
  std::vector<PlayerProjectile> &GetPlayerProjectiles() { return myPlayPro; }
  Player &GetPlayer() { return myPlayer; }

  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();
  void Init();
  void UpdateScreen();
  void Start() { screen.ShowUntilClosed(); }
  void MoveGameElements();
  void FilterIntersections();
  void OnAnimationStep();
  void OnMouseEvent(const graphics::MouseEvent &mouse);

 private:
  graphics::Image screen;
  std::vector<Opponent> myOpp;
  std::vector<OpponentProjectile> myOppPro;
  std::vector<PlayerProjectile> myPlayPro;
  Player myPlayer;
};

#endif
