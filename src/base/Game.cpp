#include <fmt/core.h>
#include "Components/Components.hpp"
#include "raylib.h"
#include "sol/types.hpp"
#include "Game.hpp"
#include <Systems/Systems.hpp>
#include <GUI/GUI.hpp>

void Game::init()
{
  if(!file_exist("ini.lua"))
  {
    current_windowW = d_windowWidth;
    current_windowH = d_windowHeight;
  }

  InitWindow(current_windowW, current_windowH, "RougueLike");
  if(IsWindowReady())
  {
    is_running = true;
  }
  g_lstate.open_libraries(sol::lib::base, sol::lib::os, sol::lib::utf8, sol::lib::math);
  auto e = world.create();
  world.emplace<CTransform>(e, Vector2{0, 0});
  world.emplace<CSymbol>(e, "@");
  world.emplace<CInput>(e);
}

void Game::handle_input()
{
  
}

void Game::update()
{
  movement_system(world);
}

void Game::draw()
{
  BeginDrawing();
  ClearBackground(GRAY);
  render_system(world, camera);
  //Draw UI here
  GuiGrid((Rectangle){0, 0, (float)this->current_windowW, (float)this->current_windowH}, "Property List", 32.0f, 2, &mouseCell);
  GuiPanel((Rectangle){ 370, 25, 225, 140 }, "Menu");
  EndDrawing();
}

void Game::run()
{
  SetTargetFPS(60); 
  while(is_running)
  {
    handle_input();
    update();
    draw();
    //TODO:remove this after implementing a proper way to exit, since this is only for debug porpouses
    if(WindowShouldClose())
    {
      is_running = false;
      CloseWindow();
    }
  }

  deinit();
}

void Game::deinit()
{
  world.clear();
}
