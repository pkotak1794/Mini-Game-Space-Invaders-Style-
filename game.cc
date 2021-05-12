#include "game.h"

void Game::Init() {
  myPlayer.SetX(300);
  myPlayer.SetY(300);
  CreateOpponents();
  //CreateOpponentProjectiles();
  //CreatePlayerProjectiles();
  screen.AddMouseEventListener(*this);
  screen.AddAnimationEventListener(*this);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 3; i++) {
    Opponent my_opponent(100 * i, 20);
    std::unique_ptr<Opponent> oppList = std::make_unique<Opponent>(10,10);
    myOpp.push_back(std::move(oppList));
  }
}
/*void Game::CreateOpponentProjectiles() {
  for (int i = 0; i < 3; i++) {
    OpponentProjectile my_opponent_projectile(100 * i, 100);
    myOppPro.push_back(my_opponent_projectile);
  }
}

void Game::CreatePlayerProjectiles() {
  for (int i = 0; i < 3; i++) {
    PlayerProjectile my_projectile(100 * i, 450);
    myPlayPro.push_back(my_projectile);
  }
}*/

void Game::UpdateScreen() {
  screen.DrawRectangle(0, 0, 800, 600, 255, 255, 255);
  for (int i = 0; i < myOpp.size(); i++) {
    if (myOpp[i].GetIsActive() == true) myOpp[i].Draw(screen);
  }
  for (int i = 0; i < myOppPro.size(); i++) {
    if (myOppPro[i].GetIsActive() == true) myOppPro[i].Draw(screen);
  }
  for (int i = 0; i < myPlayPro.size(); i++) {
    if (myPlayPro[i].GetIsActive() == true) myPlayPro[i].Draw(screen);
  }
  if (myPlayer.GetIsActive() == true) myPlayer.Draw(screen);
}

// void Game::Start(graphics::Image &screen) { screen.ShowUntilClosed(); }

void Game::MoveGameElements() {
  for (int i = 0; i < myOpp.size(); i++) {
    myOpp[i].Move(screen);
  }
  for (int i = 0; i < myOppPro.size(); i++) {
    myOppPro[i].Move(screen);
  }
  for (int i = 0; i < myPlayPro.size(); i++) {
    myPlayPro[i].Move(screen);
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < myOpp.size(); i++) {
    if (myPlayer.IntersectsWith(myOpp[i]) == true) {
      myPlayer.SetIsActive(false);
      myOpp[i].SetIsActive(false);
    }
  }
  for (int i = 0; i < myOppPro.size(); i++) {
    if (myOppPro[i].IntersectsWith(myPlayer) == true) {
      myPlayer.SetIsActive(false);
      myOppPro[i].SetIsActive(false);
    }
  }
  for (int p = 0; p < myPlayPro.size(); p++) {
    for (int k = 0; k < myOpp.size(); k++) {
      if (myPlayPro[p].IntersectsWith(myOpp[k]) == true) {
        myPlayPro[p].SetIsActive(false);
        myOpp[k].SetIsActive(false);
      }
    }
  }
}

void Game::OnAnimationStep() {
  if (myOpp.size() < 1) {
    CreateOpponents();
  }
  MoveGameElements();
  FilterIntersections();
  UpdateScreen();
  screen.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent &mouse) {
  mouse.GetMouseAction();
  if (mouse.GetX() > 0 && mouse.GetY() > 0 &&
      mouse.GetX() < screen.GetWidth() && mouse.GetY() < screen.GetHeight()) {
    myPlayer.SetX(mouse.GetX() - myPlayer.GetWidth() / 2);
    myPlayer.SetY(mouse.GetY() - myPlayer.GetHeight() / 2);
    if (myPlayer.GetX() > 800 || myPlayer.GetX() < 0) {
      player.SetX(temp_x);
    }
    if (myPlayer.GetY() > 600 || myPlayer.GetY() < 0) {
      player.SetY(temp_y);
  }
}
if (mouseEvent.GetMouseAction() == graphics::MouseAction::kPressed || 
    mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged) {
      std::unique_ptr<PlayerProjectile> onMouseEvent_myOpp = std::make_unique<PlayerProjectile>(GetX(), GetY());
      myPlayPro.push_back(std::move(OnMouseEvent_myOpp));
    }
