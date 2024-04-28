#pragma once
#include <sol/forward.hpp>
#include <sol/sol.hpp>
#include <cstdint>
#include <raylib.h>

struct CName
{
  std::string name;
};

struct CTransform
{
  Vector2 pos;
  uint32_t scale;//scale in pixels
};

struct CBaseStats
{
  uint8_t hp;
  uint8_t mp;
  uint8_t dt;
  uint8_t dr;
  uint8_t stamina;
  uint8_t strength;
  uint8_t agility;
  uint8_t inteligence;
};

struct CBodyParts
{
  sol::table bp_table;
};

struct CScripting
{
  sol::state vm;
};

struct CSkills
{
  sol::table skill_table;
};

struct CSpells
{
  sol::table spell_list;
};

struct CSymbol
{
  const char *symbol;
  Color color;
};

struct CInventory
{
  sol::table inv;
};

struct CTileType
{
  enum
  {
    WALL,
    DOOR,
    FLOOR,
    WATER,
    LAVA,
  };
};

//Tag
struct CInput {};
