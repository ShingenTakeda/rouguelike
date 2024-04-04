#include <fmt/core.h>
#include "Components/Components.hpp"
#include "raylib.h"
#include "sol/types.hpp"
#include "Game.hpp"
#include <Systems/Systems.hpp>

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
  world.emplace<CTransform>(e, Vector2{40, 50});
  world.emplace<CChar>(e, "A");
}

void Game::handle_input()
{

}

void Game::update()
{

}

void Game::draw()
{
  BeginDrawing();
  ClearBackground(GRAY);
  render_system(world);
  //Draw UI here
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
