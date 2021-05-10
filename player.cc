#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"

void PlayerProjectile::Draw(graphics::Image &screen) {
  screen.DrawRectangle(GetX(), GetY(), 4, 4, space);
  screen.DrawRectangle(GetX() + 6, GetY(), 4, 4, space);
  screen.DrawRectangle(GetX(), GetY() + 6, 4, 4, space);
  screen.DrawRectangle(GetX() + 6, GetY() + 6, 4, 4, space);
  screen.DrawRectangle(GetX() + 4, GetY(), 2, 10, red);
  screen.DrawRectangle(GetX(), GetY() + 4, 4, 2, red);
  screen.DrawRectangle(GetX() + 6, GetY() + 4, 4, 2, red);
}

void PlayerProjectile::Move(const graphics::Image &image) {
  SetY(GetY() - 4);
  SetX(GetX() - 4);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}

bool PlayerProjectile::IntersectsWith(const Opponent &opponent) {
  return !(GetX() > opponent.GetX() + opponent.GetWidth() ||
           opponent.GetX() > GetX() + GetWidth() ||
           GetY() > opponent.GetY() + opponent.GetHeight() ||
           opponent.GetY() > GetY() + GetHeight());
}

void Player::Draw(graphics::Image &screen) {
  screen.DrawRectangle(GetX(), GetY(), 10, 30, yellow);
  screen.DrawRectangle(GetX() + 20, GetY(), 10, 30, yellow);
  screen.DrawRectangle(GetX() + 40, GetY(), 10, 30, yellow);
  screen.DrawRectangle(GetX(), GetY() + 30, 50, 20, yellow);
  screen.DrawRectangle(GetX() + 10, GetY(), 10, 30, space);
  screen.DrawRectangle(GetX() + 30, GetY(), 10, 30, space);
  screen.DrawRectangle(GetX(), GetY(), 10, 2, gold);
  screen.DrawRectangle(GetX() + 20, GetY(), 10, 2, gold);
  screen.DrawRectangle(GetX() + 40, GetY(), 10, 2, gold);
  screen.DrawRectangle(GetX(), GetY() + 2, 2, 48, gold);
  screen.DrawRectangle(GetX() + 48, GetY() + 2, 2, 48, gold);
  screen.DrawRectangle(GetX() + 8, GetY() + 2, 2, 28, gold);
  screen.DrawRectangle(GetX() + 20, GetY() + 2, 2, 28, gold);
  screen.DrawRectangle(GetX() + 28, GetY() + 2, 2, 28, gold);
  screen.DrawRectangle(GetX() + 40, GetY() + 2, 2, 28, gold);
  screen.DrawRectangle(GetX() + 8, GetY() + 30, 14, 2, gold);
  screen.DrawRectangle(GetX() + 28, GetY() + 30, 14, 2, gold);
  screen.DrawRectangle(GetX() + 2, GetY() + 48, 46, 2, gold);
  screen.DrawCircle(GetX() + 8, GetY() + 40, 3, purple);
  screen.DrawCircle(GetX() + 26, GetY() + 40, 3, purple);
  screen.DrawCircle(GetX() + 42, GetY() + 40, 3, purple);
}

void Player::Move(const graphics::Image &image) {}

bool Player::IntersectsWith(const Opponent &opponent) {
  return !(GetX() > opponent.GetX() + opponent.GetWidth() ||
           opponent.GetX() > GetX() + GetWidth() ||
           GetY() > opponent.GetY() + opponent.GetHeight() ||
           opponent.GetY() > GetY() + GetHeight());
}

bool Player::IntersectsWith(const OpponentProjectile &projectile) {
  return !(GetX() > projectile.GetX() + projectile.GetWidth() ||
           projectile.GetX() > GetX() + GetWidth() ||
           GetY() > projectile.GetY() + projectile.GetHeight() ||
           projectile.GetY() > GetY() + GetHeight());
}
