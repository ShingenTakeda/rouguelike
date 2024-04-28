#include "fmtlog/fmtlog.h"
#include <Systems/Systems.hpp>
#include <Components/Components.hpp>
#include <raylib.h>

void input_system(entt::registry &world)
{

}

void movement_system(entt::registry &world)
{
  auto view = world.view<const CInput, CTransform>(); 
  for(auto entity: view)
  {
    auto &trans = view.get<CTransform>(entity);
    if(IsKeyPressed(KEY_RIGHT))
    {
      trans.pos.x += 32;
      FMTLOG(fmtlog::INF, "POS X: {}, POS Y: {}", trans.pos.x, trans.pos.y);
      fmtlog::poll();
    }

  }
}

void render_system(entt::registry &world, Camera2D &camera)
{
  auto view = world.view<const CSymbol, const CTransform>();
  
  //BeginMode2D(camera);
  for(auto entity: view)
  {
    auto &cchar = view.get<CSymbol>(entity);
    auto &trans = view.get<CTransform>(entity);

    DrawText(cchar.symbol, trans.pos.x, trans.pos.y, 32, RED);
  }
  //EndMode2D();
}


void camera_system(entt::registry &world, Camera2D &camera)
{
  //for(auto )
}
