#include "gba.h"
#include "mode0.h"
#include "sprites.h"
#include "game.h"
#include "leaflets.h"

extern SPRITE leaflets[LEAFLETSNUM];
OBJ_ATTR shadowOAM[128];

void initLeaflets()
{
  for (int i = 0; i < LEAFLETSNUM; i++)
  {
    leaflets[i].width = 8;
    leaflets[i].height = 8;
    leaflets[i].active = 1;
    leaflets[i].hide = 1;
  }
  leaflets[0].x = 100;
  leaflets[0].y = 120;
  leaflets[1].x = 170;
  leaflets[1].y = 110;
  leaflets[5].x = 100;
  leaflets[5].y = 120;
  leaflets[6].x = 120;
  leaflets[6].y = 120;
  leaflets[8].x = 100;
  leaflets[8].y = 120;
}

void drawLeaflets()
{

  // if (leaflet.timeUntilNextFrame > 0)
  // {
  //   leaflet.timeUntilNextFrame--;
  // }
  // else
  // {
  //   leaflet.frame = ++leaflet.frame % leaflet.numOfFrames;
  //   leaflet.timeUntilNextFrame = 10;
  // }
  for (int i = 0; i < LEAFLETSNUM; i++)
  {
    if (!leaflets[i].hide)
    {
      if (leaflets[i].y - vOff > -leaflets[i].height && leaflets[i].y - vOff < SCREENHEIGHT && leaflets[i].x - hOff > -leaflets[i].width && leaflets[i].x - hOff < SCREENWIDTH)
      {
        shadowOAM[1 + i].attr0 = ATTR0_Y(leaflets[i].y - vOff) | ATTR0_SQUARE;
        shadowOAM[1 + i].attr1 = ATTR1_X(leaflets[i].x - hOff) | ATTR1_TINY;
        shadowOAM[1 + i].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(6, 0) | ATTR2_PRIORITY(0);
      }
      else
      {
        shadowOAM[1 + i].attr0 = ATTR0_HIDE;
      }
    }
    else
    {
      shadowOAM[1 + i].attr0 = ATTR0_HIDE;
    }
  }
}
