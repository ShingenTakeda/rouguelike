#pragma once
#include "raylib.h"

enum TILE_KIND
{
  FLOOR,
  WALL
};

enum TILE_TYPE
{

};

struct Tile
{
  Vector2 dimensions;
  Vector2 pos;
  TILE_KIND kind;
  TILE_TYPE type;
};
