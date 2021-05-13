#ifndef OPPONENT_H
#define OPPONENT_H
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image &screen) override;
  void Move(const graphics::Image &image) override;
  std::unique_ptr<class OpponentProjectile> LaunchProjectile();

 private:
  graphics::Color yellow{240, 224, 53};  // player image crown
  graphics::Color gold{219, 171, 13};    // crown outline
  graphics::Color purple{91, 29, 143};   // crown embellishments
  graphics::Color blue{79, 141, 255};    // opponent image shield
  graphics::Color navy{2, 85, 237};      // shield details
  graphics::Color red{255, 0, 0};        // player projectile cross
  graphics::Color green{0, 255, 17};     // opponent projectile cross
  graphics::Color space{255, 255, 255};  // true white

  int launch = 0;
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 10, 10) {}

  void Draw(graphics::Image &screen) override;
  void Move(const graphics::Image &image) override;

 private:
  graphics::Color yellow{240, 224, 53};  // player image crown
  graphics::Color gold{219, 171, 13};    // crown outline
  graphics::Color purple{91, 29, 143};   // crown embellishments
  graphics::Color blue{79, 141, 255};    // opponent image shield
  graphics::Color navy{2, 85, 237};      // shield details
  graphics::Color red{255, 0, 0};        // player projectile cross
  graphics::Color green{0, 255, 17};     // opponent projectile cross
  graphics::Color space{255, 255, 255};  // true white
};

#endif
