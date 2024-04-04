#include "Game.hpp"
#include "raylib.h"
#include "sol/types.hpp"

void Game::init()
{
  InitWindow(d_windowWidth, d_windowHeight, "RougueLike");
  if(IsWindowReady())
  {
    is_running = true;
  }
  g_lstate.open_libraries(sol::lib::base, sol::lib::os, sol::lib::utf8, sol::lib::math);
}

void Game::handle_input()
{}

void Game::update()
{}

void Game::draw()
{
  BeginDrawing();
  EndDrawing();
}

void Game::run()
{
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
  
}
