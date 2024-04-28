#pragma once
#include "entt/entity/fwd.hpp"
#include <entt/entt.hpp>
#include <raylib.h>

void input_system(entt::registry &world);
void movement_system(entt::registry &world);
void render_system(entt::registry &world, Camera2D &camera);
void health_system(entt::registry &world);
