#include "gba.h"
#include "mode0.h"
#include "sprites.h"
#include "game.h"
#include "dimitri.h"
#include "print.h"

extern SPRITE dimitri;
OBJ_ATTR shadowOAM[128];
void initDimitri()
{
  dimitri.width = 16;
  dimitri.height = 32;
  dimitri.dx = 1;
  dimitri.dy = 1;
  dimitri.timeUntilNextFrame = 10;
  dimitri.numOfFrames = 2;
  dimitri.frame = 0;
  dimitri.x = 120;
  dimitri.y = 150;
  dimitri.active = 1;
  dimitri.hide = 1;
}

void drawDimitri()
{

  if (dimitri.timeUntilNextFrame > 0)
  {
    dimitri.timeUntilNextFrame--;
  }
  else
  {
    dimitri.frame = ++dimitri.frame % dimitri.numOfFrames;
    dimitri.timeUntilNextFrame = 30;
  }

  shadowOAM[30].attr0 = ATTR0_Y(dimitri.y - vOff) | ATTR0_TALL;
  if (dimitri.hide)
  {
    shadowOAM[30].attr0 = ATTR0_HIDE;
  }
  shadowOAM[30].attr1 = ATTR1_X(dimitri.x - hOff) | ATTR1_MEDIUM;
  shadowOAM[30].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(7 + dimitri.frame * 2, 0) | ATTR2_PRIORITY(0);
}
