#include <Systems/Systems.hpp>
#include <Components/Components.hpp>
#include <raylib.h>

void input_system(entt::registry &world)
{

}

void movement_system(entt::registry &world)
{

}

void render_system(entt::registry &world)
{
  auto view = world.view<const CChar, const CTransform>();

  for(auto entity: view)
  {
    auto &cchar = view.get<CChar>(entity);
    auto &trans = view.get<CTransform>(entity);

    DrawText(cchar.symbol, trans.pos.x, trans.pos.y, 25, RED);
  }
}
