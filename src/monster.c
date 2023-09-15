#include "gba.h"
#include "mode0.h"
#include "sprites.h"
#include "game.h"
#include "monster.h"
#include "print.h"

extern SPRITE monster;
OBJ_ATTR shadowOAM[128];
void initMonster()
{
  monster.width = 32;
  monster.height = 64;
  monster.dx = 1;
  monster.dy = 1;
  monster.timeUntilNextFrame = 100;
  monster.numOfFrames = 3;
  monster.frame = 0;
  monster.x = 250;
  monster.y = 250;
  monster.active = 0;
  monster.hide = 1;
}

void drawMonster()
{

  if (monster.timeUntilNextFrame > 0)
  {
    monster.timeUntilNextFrame--;
  }
  else
  {
    monster.frame = ++monster.frame % monster.numOfFrames;
    monster.timeUntilNextFrame = 10;
  }

  if (monster.hide == 0 && monster.y - vOff > -monster.height && monster.y - vOff < SCREENHEIGHT)
  {

    shadowOAM[31].attr0 = ATTR0_Y(monster.y - vOff) | ATTR0_TALL;
  }
  else
  {

    shadowOAM[31].attr0 = ATTR0_HIDE;
  }
  shadowOAM[31].attr1 = ATTR1_X(monster.x - hOff) | ATTR1_LARGE;
  shadowOAM[31].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(monster.frame * 4, 16) | ATTR2_PRIORITY(0);
}
