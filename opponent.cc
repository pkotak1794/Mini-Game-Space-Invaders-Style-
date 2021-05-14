#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"

void OpponentProjectile::Draw(graphics::Image &screen) {
  screen.DrawRectangle(GetX(), GetY(), 4, 4, space);
  screen.DrawRectangle(GetX() + 6, GetY(), 4, 4, space);
  screen.DrawRectangle(GetX(), GetY() + 6, 4, 4, space);
  screen.DrawRectangle(GetX() + 6, GetY() + 6, 4, 4, space);
  screen.DrawRectangle(GetX() + 4, GetY(), 2, 10, green);
  screen.DrawRectangle(GetX(), GetY() + 4, 4, 2, green);
  screen.DrawRectangle(GetX() + 6, GetY() + 4, 4, 2, green);
}

void OpponentProjectile::Move(const graphics::Image &image) {
  SetY(GetY() + 3);
  SetX(GetX() + 3);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}

std::unique_ptr<class OpponentProjectile> Opponent::LaunchProjectile() {
  if (launch >= 10) {
    launch = 0;
    std::unique_ptr<OpponentProjectile> oppProList;
    oppProList = std::make_unique<OpponentProjectile>();
    return std::move(oppProList);
  } else {
    launch++;
    return nullptr;
  }
}

void Opponent::Draw(graphics::Image &screen) {
  screen.DrawRectangle(GetX(), GetY(), 50, 2, gold);
  screen.DrawRectangle(GetX(), GetY() + 2, 2, 6, gold);
  screen.DrawRectangle(GetX() + 48, GetY() + 2, 2, 6, gold);
  screen.DrawRectangle(GetX(), GetY() + 8, 22, 2, gold);
  screen.DrawRectangle(GetX() + 28, GetY() + 8, 22, 2, gold);
  screen.DrawRectangle(GetX() + 20, GetY() + 10, 2, 36, gold);
  screen.DrawRectangle(GetX() + 28, GetY() + 10, 2, 36, gold);
  screen.DrawRectangle(GetX() + 2, GetY() + 2, 46, 6, yellow);
  screen.DrawRectangle(GetX() + 22, GetY() + 8, 6, 38, yellow);
  screen.DrawRectangle(GetX() + 22, GetY() + 46, 6, 2, yellow);
  screen.DrawRectangle(GetX() + 24, GetY() + 48, 2, 2, yellow);
  screen.DrawRectangle(GetX(), GetY() + 10, 20, 16, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 10, 20, 16, blue);
  screen.DrawRectangle(GetX() + 2, GetY() + 26, 18, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 26, 18, 2, blue);
  screen.DrawRectangle(GetX() + 4, GetY() + 28, 16, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 28, 16, 2, blue);
  screen.DrawRectangle(GetX() + 6, GetY() + 30, 14, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 30, 14, 2, blue);
  screen.DrawRectangle(GetX() + 8, GetY() + 32, 12, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 32, 12, 2, blue);
  screen.DrawRectangle(GetX() + 10, GetY() + 32, 10, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 32, 10, 2, blue);
  screen.DrawRectangle(GetX() + 12, GetY() + 36, 8, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 36, 8, 2, blue);
  screen.DrawRectangle(GetX() + 14, GetY() + 38, 6, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 38, 6, 2, blue);
  screen.DrawRectangle(GetX() + 16, GetY() + 40, 4, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 40, 4, 2, blue);
  screen.DrawRectangle(GetX() + 18, GetY() + 42, 2, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 42, 2, 2, blue);
  screen.DrawRectangle(GetX() + 10, GetY() + 34, 10, 2, blue);
  screen.DrawRectangle(GetX() + 30, GetY() + 34, 10, 2, blue);
  screen.DrawRectangle(GetX(), GetY() + 26, 2, 4, navy);
  screen.DrawRectangle(GetX() + 2, GetY() + 28, 2, 4, navy);
  screen.DrawRectangle(GetX() + 4, GetY() + 30, 2, 4, navy);
  screen.DrawRectangle(GetX() + 6, GetY() + 32, 2, 4, navy);
  screen.DrawRectangle(GetX() + 8, GetY() + 34, 2, 4, navy);
  screen.DrawRectangle(GetX() + 10, GetY() + 36, 2, 4, navy);
  screen.DrawRectangle(GetX() + 12, GetY() + 38, 2, 4, navy);
  screen.DrawRectangle(GetX() + 14, GetY() + 40, 2, 4, navy);
  screen.DrawRectangle(GetX() + 16, GetY() + 42, 2, 4, navy);
  screen.DrawRectangle(GetX() + 18, GetY() + 44, 2, 4, navy);
  screen.DrawRectangle(GetX() + 20, GetY() + 46, 2, 4, navy);
  screen.DrawRectangle(GetX() + 22, GetY() + 48, 2, 2, navy);
  screen.DrawRectangle(GetX() + 26, GetY() + 48, 2, 2, navy);
  screen.DrawRectangle(GetX() + 28, GetY() + 46, 2, 4, navy);
  screen.DrawRectangle(GetX() + 30, GetY() + 44, 2, 4, navy);
  screen.DrawRectangle(GetX() + 32, GetY() + 42, 2, 4, navy);
  screen.DrawRectangle(GetX() + 34, GetY() + 40, 2, 4, navy);
  screen.DrawRectangle(GetX() + 36, GetY() + 38, 2, 4, navy);
  screen.DrawRectangle(GetX() + 38, GetY() + 36, 2, 4, navy);
  screen.DrawRectangle(GetX() + 40, GetY() + 34, 2, 4, navy);
  screen.DrawRectangle(GetX() + 42, GetY() + 32, 2, 4, navy);
  screen.DrawRectangle(GetX() + 44, GetY() + 30, 2, 4, navy);
  screen.DrawRectangle(GetX() + 46, GetY() + 28, 2, 4, navy);
  screen.DrawRectangle(GetX() + 48, GetY() + 26, 2, 4, navy);
  screen.DrawRectangle(GetX(), GetY() + 30, 2, 20, space);
  screen.DrawRectangle(GetX() + 2, GetY() + 32, 2, 18, space);
  screen.DrawRectangle(GetX() + 4, GetY() + 34, 2, 16, space);
  screen.DrawRectangle(GetX() + 6, GetY() + 36, 2, 14, space);
  screen.DrawRectangle(GetX() + 8, GetY() + 38, 2, 12, space);
  screen.DrawRectangle(GetX() + 10, GetY() + 40, 2, 10, space);
  screen.DrawRectangle(GetX() + 12, GetY() + 42, 2, 8, space);
  screen.DrawRectangle(GetX() + 14, GetY() + 44, 2, 6, space);
  screen.DrawRectangle(GetX() + 16, GetY() + 46, 2, 4, space);
  screen.DrawRectangle(GetX() + 18, GetY() + 48, 2, 2, space);
  screen.DrawRectangle(GetX() + 30, GetY() + 48, 2, 2, space);
  screen.DrawRectangle(GetX() + 32, GetY() + 46, 2, 4, space);
  screen.DrawRectangle(GetX() + 34, GetY() + 44, 2, 6, space);
  screen.DrawRectangle(GetX() + 36, GetY() + 42, 2, 8, space);
  screen.DrawRectangle(GetX() + 38, GetY() + 40, 2, 10, space);
  screen.DrawRectangle(GetX() + 40, GetY() + 38, 2, 12, space);
  screen.DrawRectangle(GetX() + 42, GetY() + 36, 2, 14, space);
  screen.DrawRectangle(GetX() + 44, GetY() + 34, 2, 16, space);
  screen.DrawRectangle(GetX() + 46, GetY() + 32, 2, 18, space);
  screen.DrawRectangle(GetX() + 48, GetY() + 30, 2, 20, space);
}

void Opponent::Move(const graphics::Image &image) {
  SetY(GetY() + 2);
  SetX(GetX() + 2);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}
