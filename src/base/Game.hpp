#pragma once
#include <entt/entity/fwd.hpp>
#include <filesystem>
#include <sol/state.hpp>
#include <raylib.h>
#include <sol/sol.hpp>
#include <entt/entt.hpp>
#include <fmtlog/fmtlog.h>

struct Game
{
  void run();

  void init();
  void setup();
  void handle_input();
  void update();
  void draw();
  void deinit();

  //store lua defined systems,components and entity definitions here here
  sol::state g_lstate;
  entt::registry world;

  bool debug_draw = false;
  //Base window dimensions if ini file doesn't exist
  static constexpr int d_windowWidth = 720;
  static constexpr int d_windowHeight = 480;
  int current_windowW;
  int current_windowH;
  bool is_running = false;
};

inline bool file_exist(const std::string &name)
{
  return std::filesystem::exists(name);
}
