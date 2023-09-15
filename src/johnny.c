#include "gba.h"
#include "mode0.h"
#include "sprites.h"
#include "game.h"
#include "johnny.h"
#include "print.h"

extern SPRITE johnny;
OBJ_ATTR shadowOAM[128];
void initJohnny()
{
  johnny.width = 16;
  johnny.height = 32;
  johnny.dx = 1;
  johnny.dy = 1;
  johnny.timeUntilNextFrame = 10;
  johnny.numOfFrames = 3;
  johnny.frame = 0;
  // johnny.direction = DOWN;
  johnny.x = 120;
  johnny.y = 150;
  johnny.active = 1;
  johnny.hide = 0;
  johnny.sleepy = 0;
  johnny.direction = DOWN;
}

void drawJohnny()
{

  if (johnny.isMoving)
  {
    if (johnny.timeUntilNextFrame > 0)
    {
      johnny.timeUntilNextFrame--;
    }
    else
    {
      johnny.frame = ++johnny.frame % johnny.numOfFrames;
      johnny.timeUntilNextFrame = 10;
    }
  }
  else
  {
    johnny.frame = 0;
  }

  shadowOAM[0].attr0 = ATTR0_Y(johnny.y - vOff) | ATTR0_TALL;
  shadowOAM[0].attr1 = ATTR1_X(johnny.x - hOff) | ATTR1_MEDIUM;
  shadowOAM[0].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(johnny.frame * 2, johnny.direction * 4) | ATTR2_PRIORITY(0);
}
