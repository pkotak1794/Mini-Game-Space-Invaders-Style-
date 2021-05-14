#ifndef GAME_H
#define GAME_H
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game() : Game(800, 600) {}
  Game(int width, int height) : screen(width, height) {}

  graphics::Image &GetGameScreen() { return screen; }
  std::vector<std::unique_ptr<Opponent>> &GetOpponents() { return myOpp; }
  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles() {
    return myOppPro;
  }
  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles() {
    return myPlayPro;
  }
  Player &GetPlayer() { return myPlayer; }

  void CreateOpponents();
  void Init();
  void UpdateScreen();
  void Start() { screen.ShowUntilClosed(); }
  void MoveGameElements();
  void FilterIntersections();
  void OnAnimationStep();
  void OnMouseEvent(const graphics::MouseEvent &mouse);
  void RemoveInactive();
  int GetScore() { return score_; }
  bool HasLost() { return haslost_; }
  void LaunchProjectiles();

 private:
  graphics::Image screen;
  std::vector<std::unique_ptr<Opponent>> myOpp;
  std::vector<std::unique_ptr<OpponentProjectile>> myOppPro;
  std::vector<std::unique_ptr<PlayerProjectile>> myPlayPro;
  Player myPlayer;
  int score_ = 0;
  bool haslost_ = false;
};

#endif
