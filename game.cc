#include "game.h"

void Game::Init() {
  myPlayer.SetX(300);
  myPlayer.SetY(300);
  screen.AddMouseEventListener(*this);
  screen.AddAnimationEventListener(*this);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 3; i++) {
    Opponent my_opponent(100 * i, 20);
    std::unique_ptr<Opponent> oppList = std::make_unique<Opponent>(10, 10);
    myOpp.push_back(std::move(oppList));
  }
}

void Game::UpdateScreen() {
  screen.DrawRectangle(0, 0, 800, 600, 255, 255, 255);
  for (int i = 0; i < myOpp.size(); i++) {
    if (myOpp[i]->GetIsActive() == true) {
      myOpp[i]->Draw(screen);
    }
  }
  for (int i = 0; i < myOppPro.size(); i++) {
    if (myOppPro[i]->GetIsActive() == true) {
      myOppPro[i]->Draw(screen);
    }
  }
  for (int i = 0; i < myPlayPro.size(); i++) {
    if (myPlayPro[i]->GetIsActive() == true) {
      myPlayPro[i]->Draw(screen);
    }
  }
  if (myPlayer.GetIsActive() == true) {
    myPlayer.Draw(screen);
  } else {
    screen.DrawText(235, 250, "GAME OVER", 70, graphics::Color(156,125,12));
  }
  screen.DrawText(0, 0, "Score: " + std::to_string(GetScore()), 30,
                  graphics::Color(0, 0, 0));
}  

void Game::MoveGameElements() {
  for (int i = 0; i < myOpp.size(); i++) {
    if (myOpp[i]->GetIsActive()) {
      myOpp[i]->Move(screen);
    }
  }
  for (int p = 0; p < myOppPro.size(); p++) {
    if (myOppPro[p]->GetIsActive()) {
      myOppPro[p]->Move(screen);
    }
  }
  for (int j = 0; j < myPlayPro.size(); j++) {
    if (myPlayPro[j]->GetIsActive()) {
      myPlayPro[j]->Move(screen);
    }
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < myOpp.size(); i++) {
    if (myPlayer.IntersectsWith(myOpp[i].get())) {
      myPlayer.SetIsActive(false);
      myOpp[i]->SetIsActive(false);
      haslost_ = true;
    }
  }
  for (int z = 0; z < myOppPro.size(); z++) {
    if (myPlayer.IntersectsWith(myOppPro[z].get())) {
      myPlayer.SetIsActive(false);
      myOppPro[z]->SetIsActive(false);
      haslost_ = true;
    }
  }
  for (int p = 0; p < myPlayPro.size(); p++) {
    for (int k = 0; k < myOpp.size(); k++) {
      if (myOpp[k]->IntersectsWith(myPlayPro[p].get())) {
        myPlayPro[p]->SetIsActive(false);
        myOpp[k]->SetIsActive(false);
        if (myPlayer.GetIsActive()) {
          score_++;
        }
      }
    }
  }
}

void Game::OnAnimationStep() {
  if (myOpp.size() < 1) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  screen.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent &mouse) {
  if (mouse.GetMouseAction() == graphics::MouseAction::kMoved ||
      mouse.GetMouseAction() == graphics::MouseAction::kDragged) {
    int xX = myPlayer.GetX();
    int yY = myPlayer.GetY();
    myPlayer.SetX(mouse.GetX() - myPlayer.GetWidth() / 2);
    myPlayer.SetY(mouse.GetY() - myPlayer.GetHeight() / 2);
    if (myPlayer.GetX() > 800 || myPlayer.GetX() < 0) {
      myPlayer.SetX(xX);
    }
    if (myPlayer.GetY() > 600 || myPlayer.GetY() < 0) {
      myPlayer.SetY(yY);
    }
  }

  if (mouse.GetMouseAction() == graphics::MouseAction::kPressed ||
      mouse.GetMouseAction() == graphics::MouseAction::kDragged) {
    std::unique_ptr<PlayerProjectile> onMouseEvent_myOpp =
        std::make_unique<PlayerProjectile>(mouse.GetX(), mouse.GetY());
    myPlayPro.push_back(std::move(onMouseEvent_myOpp));
  }
}
void Game::LaunchProjectiles() {
  for (int q = 0; q < myOpp.size(); q++) {
    std::unique_ptr<OpponentProjectile> oppList = myOpp[q]->LaunchProjectile();
    if (oppList != nullptr) {
      myOppPro.push_back(std::move(oppList));
    }
  }
}

void Game::RemoveInactive() {
  for (int a = myOpp.size() - 1; a >= 0; a--) {
    if (!myOpp[a]->GetIsActive()) {
      myOpp.erase(myOpp.begin() + a);
    }
  }
  for (int b = myOppPro.size() - 1; b >= 0; b--) {
    if (!myOppPro[b]->GetIsActive()) {
      myOppPro.erase(myOppPro.begin() + b);
    }
  }
  for (int c = myPlayPro.size() - 1; c >= 0; c--) {
    if (!myPlayPro[c]->GetIsActive()) {
      myPlayPro.erase(myPlayPro.begin() + c);
    }
  }
}
