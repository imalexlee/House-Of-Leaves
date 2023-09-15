#include "game.h"
#include "sprites.h"
#include "gba.h"
#include "mode0.h"
#include "johnny.h"
#include "mode0.h"
#include "leaflets.h"
#include "dimitri.h"
#include "monster.h"
#include "sound.h"

void updatejohnny();
void updateLeaflets();
void updateDimitri();
void updateMonster();
int ezSpriteCollision(SPRITE s1, SPRITE s2);
int dimitriConvo = 1;

enum STATE
{
  SPLASH,
  INSTRUCTIONS,
  AWAKE1,
  NOTE1,
  NOTE2,
  NOTE3,
  NOTE4,
  NOTE5,
  FRONTYARD,
  NOTE6,
  LIMINAL1,
  NOTE7,
  BASEMENT,
  NOTE8,
  LIVINGROOM,
  NOTE9,
  AWAKE2,
  NOTE10,
  AWAKE3,
  SLEEP1,
  SLEEP2,
  PAUSE,
  NIGHTMARE,
  NOTE11,
  WIN,
};

int progressNum = AWAKE1;
int state;
int monsterWaitTime = 600;

u8 *collisionMap;

SPRITE johnny;
SPRITE dimitri;
SPRITE monster;
SPRITE leaflets[LEAFLETSNUM];

// TODO: make the width dynamic based on the size of the map
inline unsigned char colorAt(int x, int y)
{
  return collisionMap[OFFSET(x, y, 256)];
}

int canMoveLeft()
{

  int left = johnny.x;
  // int right = johnny.x + johnny.width + 1;
  int top = johnny.y + johnny.height - 3;
  int bottom = johnny.y + johnny.height - 1;
  // return 1;
  return colorAt(left - johnny.dx, top) && colorAt(left - johnny.dx, bottom);
}

int canMoveRight()
{

  // int left = johnny.x;
  int right = johnny.x + johnny.width - 1;
  int top = johnny.y + johnny.height - 3;
  int bottom = johnny.y + johnny.height - 1;
  // return 1;
  return colorAt(right + johnny.dx, top) && colorAt(right + johnny.dx, bottom);
}

int canMoveUp()
{
  int left = johnny.x;
  int right = johnny.x + johnny.width - 1;
  int top = johnny.y + johnny.height - 3;
  // int bottom = johnny.y + johnny.height - 1;
  //  return 1;
  return colorAt(left, top - johnny.dy) && colorAt(right, top - johnny.dy);
}

int canMoveDown()
{
  int left = johnny.x;
  int right = johnny.x + johnny.width - 1;
  // int top = johnny.y + johnny.height - 3;
  int bottom = johnny.y + johnny.height - 1;
  // return 1;
  return colorAt(right, bottom + johnny.dy) && colorAt(left, bottom + johnny.dy);
}

void drawGame()
{
  drawJohnny();
  drawLeaflets();
  drawDimitri();
  drawMonster();
  timer++;
  waitForVBlank();
  DMANow(3, shadowOAM, OAM, 512);
  REG_BG0HOFF = hOff;
  REG_BG0VOFF = vOff;
}

void updateGame()
{
  updatejohnny();
  updateDimitri();
  updateLeaflets();
  updateMonster();
  if (BUTTON_PRESSED(BUTTON_SELECT))
  {
    goToPause();
  }
}

void updatejohnny()
{
  johnny.isMoving = 0;
  if (BUTTON_HELD(BUTTON_UP) && canMoveUp())
  {
    johnny.y -= johnny.dy;
    johnny.direction = UP;
    johnny.isMoving = 1;
  }
  if (BUTTON_HELD(BUTTON_DOWN) && canMoveDown())
  {
    johnny.y += johnny.dy;
    johnny.direction = DOWN;
    johnny.isMoving = 1;
  }
  if (BUTTON_HELD(BUTTON_LEFT) && canMoveLeft())
  {
    johnny.x -= johnny.dx;
    johnny.direction = LEFT;
    johnny.isMoving = 1;
  }
  if (BUTTON_HELD(BUTTON_RIGHT) && canMoveRight())
  {
    johnny.x += johnny.dx;
    johnny.direction = RIGHT;
    johnny.isMoving = 1;
  }

  hOff = johnny.x - (SCREENWIDTH - johnny.width) / 2;
  vOff = johnny.y - (SCREENHEIGHT - johnny.height) / 2;

  if (johnny.x < 0)
    johnny.x = 0;
  if (johnny.y < 0)
    johnny.y = 0;
  if (johnny.x > 512 - johnny.width)
    johnny.x = 512 - johnny.width;
  if (johnny.y > 512 - johnny.height)
    johnny.y = 512 - johnny.height;
  if (hOff < 0)
    hOff = 0;
  if (vOff < 0)
    vOff = 0;
  if (hOff > MAPWIDTH - SCREENWIDTH)
    hOff = MAPWIDTH - SCREENWIDTH;
  if (vOff > MAPHEIGHT - SCREENHEIGHT)
    vOff = MAPHEIGHT - SCREENHEIGHT;
}

void updateLeaflets()
{
  if (ezSpriteCollision(johnny, leaflets[0]) && leaflets[0].hide == 0 && leaflets[0].active && progressNum == AWAKE1)
  {
    progressNum = NOTE1;
    REG_SND2FREQ = NOTE_CS2 | SND_RESET;
    leaflets[0].active = 0;
    leaflets[0].hide = 1;
  }
  if (ezSpriteCollision(johnny, leaflets[1]) && leaflets[1].hide == 0 && leaflets[1].active && progressNum == LIVINGROOM)
  {
    REG_SND2FREQ = NOTE_CS2 | SND_RESET;
    progressNum = NOTE2;
    leaflets[1].active = 0;
    leaflets[1].hide = 1;
  }
  if (ezSpriteCollision(johnny, leaflets[5]) && leaflets[5].hide == 0 && leaflets[5].active && progressNum == NOTE5)
  {
    REG_SND2FREQ = NOTE_CS2 | SND_RESET;
    progressNum = NOTE6;
    leaflets[5].active = 0;
    leaflets[5].hide = 1;
  }
  if (ezSpriteCollision(johnny, leaflets[6]) && leaflets[6].hide == 0 && leaflets[6].active && progressNum == LIMINAL1)
  {
    REG_SND2FREQ = NOTE_CS2 | SND_RESET;
    progressNum = NOTE7;
    leaflets[6].active = 0;
    leaflets[6].hide = 1;
  }
  if (ezSpriteCollision(johnny, leaflets[8]) && leaflets[8].hide == 0 && leaflets[8].active && progressNum == FRONTYARD)
  {
    REG_SND2FREQ = NOTE_CS2 | SND_RESET;
    progressNum = NOTE9;
    leaflets[8].active = 0;
    leaflets[8].hide = 1;
  }
}

void updateDimitri()
{
  if (state == FRONTYARD && TotalCompleted < NOTE6)
  {
    dimitri.hide = 0;
  }
  else if (state == BASEMENT && TotalCompleted < NOTE8)
  {
    dimitri.hide = 0;
    dimitri.active = 1;
    dimitri.x = 128;
    dimitri.y = 110;
  }
  else if (state == BASEMENT && TotalCompleted == NOTE8)
  {
    dimitri.hide = 0;
  }
  else
  {
    dimitri.hide = 1;
  }
  if (ezSpriteCollision(johnny, dimitri) && state == FRONTYARD && dimitri.active)
  {
    progressNum = NOTE3;
    dimitri.active = 0;
  }
  if (ezSpriteCollision(johnny, dimitri) && state == BASEMENT && dimitri.active)
  {
    progressNum = NOTE8;
    TotalCompleted = NOTE8;
    dimitri.active = 0;
  }
}

void updateMonster()
{
  if (state == SLEEP1)
  {
    monsterWaitTime--;
    if (monsterWaitTime <= 0)
    {
      monsterWaitTime = 0;
      monster.hide = 0;
      monster.active = 1;
    }
  }
  else
  {
    monster.hide = 1;
    // monster.active = 0;
  }
  if (ezSpriteCollision(johnny, monster) && state == SLEEP1 && monster.active)
  {
    progressNum = NOTE5;
  }

  if (monster.active)
  {
    if (timer % 3 == 0)
    {
      {
        monster.dx = 1;
        monster.dy = 1;
      }
      if (johnny.x < monster.x)
      {
        monster.x -= monster.dx;
      }
      if (johnny.x > monster.x)
      {
        monster.x += monster.dx;
      }
      if (johnny.y < monster.y)
      {
        monster.y -= monster.dy;
      }
      if (johnny.y > monster.y)
      {
        monster.y += monster.dy;
      }
    }
  }
  if (state == SLEEP2)
  {
    monster.x = 120;
    monster.y = 120;
    monster.hide = 0;
    if (ezSpriteCollision(johnny, monster) && state == SLEEP2 && monster.active)
    {
      progressNum = NOTE10;
    }
  }
  if (state == NIGHTMARE)
  {
    monster.x = 96;
    monster.y = 184;
    monster.hide = 0;
    if (ezSpriteCollision(johnny, monster) && state == NIGHTMARE && monster.active)
    {
      progressNum = NOTE11;
    }
  }
}