#include "mygame.h"

void cMyGame::Init() {
  // mygame constructor
}

void cMyGame::End() {
  // mygame destructor
}

void cMyGame::KeyDown(const int& iKeyEnum) {
  // keyboard down
}

void cMyGame::KeyUp(const int& iKeyEnum) {
  // keyboard up
}

void cMyGame::MouseMoved (const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse has moved
}

void cMyGame::MouseButtonUp (const int& iButton, const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse button up
}

void cMyGame::MouseButtonDown (const int& iButton,const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse button down
}

void cMyGame::Physics() {
  // this is called at strict rate, shouldn't fall behind
}

void cMyGame::Draw(float interpolation) {
  // this is called after every vsync to set up drawing
}
