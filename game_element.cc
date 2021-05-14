#include "game_element.h"
#include <vector>

bool GameElement::IntersectsWith(GameElement *game_element) {
  return !(GetX() > (*game_element).GetX() + (*game_element).GetWidth() ||
           (*game_element).GetX() > GetX() + GetWidth() ||
           GetY() > (*game_element).GetY() + (*game_element).GetHeight() ||
           (*game_element).GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image &image) {
  if (GetX() < 0 || GetX() + GetWidth() > image.GetWidth()) {
    return true;
  } else if (GetY() < 0 || GetY() + GetHeight() > image.GetHeight()) {
    return true;
  } else {
    return false;
  }
}
