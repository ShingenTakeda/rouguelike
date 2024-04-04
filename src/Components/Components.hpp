#pragma once
#include "sol/forward.hpp"
#include <cstdint>
struct CBaseStats
{
  uint8_t hp;
  uint8_t stamina;
  uint8_t strength;
  uint8_t agility;
  uint8_t inteligence;
};

struct CScripting
{
  sol::state vm;
};
