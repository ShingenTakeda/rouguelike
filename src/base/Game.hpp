#pragma once
#include <entt/entity/fwd.hpp>
#include <sol/state.hpp>
#include <raylib.h>
#include <sol/sol.hpp>
#include <entt/entt.hpp>

struct Game
{
  void run();

  void init();
  void setup();
  void handle_input();
  void update();
  void draw();
  void deinit();

  //store lua defined systems and components here
  sol::state g_lstate;
  entt::registry world;

  bool debug_draw = false;
  static constexpr int d_windowWidth = 720;
  static constexpr int d_windowHeight = 480;
  bool is_running = false;
}; 
