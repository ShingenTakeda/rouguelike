#pragma once
#include "raylib.h"
#include <GUI/GUI.hpp>
#include <string>

struct Panel
{
  Rectangle rec = {0};
  bool shouldDraw = true;
  std::string name;
};


struct MainMenuPanel
{
  Panel panel;

};
