#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include "cpputils/graphics/image.h"

class GameElement {
 public:
  GameElement() : GameElement(0, 0, 50, 50) {}
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  // setters & getters
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  // width/height setters & getters
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }

  virtual void Move(const graphics::Image &image) = 0;
  virtual void Draw(graphics::Image &screen) = 0;
  // IntersectsWith & OutofBounds functions
  bool IntersectsWith(GameElement *game_element);
  bool IsOutOfBounds(const graphics::Image &image);
  // IsActive setters/getters
  bool GetIsActive() { return is_active_; }
  void SetIsActive(bool is_active) { is_active_ = is_active; }

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;
};

#endif
