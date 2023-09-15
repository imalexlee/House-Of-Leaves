#include "gba.h"
#include "mode0.h"
#include "print.h"
#include "sprites.h"
#include "SplashScreen.h"
#include "game.h"
#include "Instructions.h"
#include "Awake1.h"
#include "Sleep1.h"
#include "Sleep2.h"
#include "Pause.h"
#include "Win.h"
#include "johnny.h"
#include "leaflets.h"
#include "tempSprite.h"
#include "InsideCTileMapUpdated.h"
#include "Bedroom.h"
#include "bedroomCollisionMap.h"
#include "johnnySprites.h"
#include "noteScreen1.h"
#include "livingRoom.h"
#include "livingRoomCollisionMap.h"
#include "sound.h"
#include "Endlessly.h"
#include "noteScreen2.h"
#include "frontYard.h"
#include "frontYardCollisionMap.h"
#include "noteScreen3.h"
#include "noteScreen4.h"
#include "monster.h"
#include "sleep1CollisionMap.h"
#include "noteScreen5.h"
#include "noteScreen6.h"
#include "noteScreen7.h"
#include "liminal1.h"
#include "doorForeground.h"
#include "basement.h"
#include "basementCollisionMap.h"
#include "noteScreen8.h"
#include "noteScreen9.h"
#include "noteScreen10.h"
#include "noteScreen11.h"
#include "dimitri.h"
#include "nightmareBG.h"
#include "nightmareFG.h"
#include "sound.h"

extern u8 *collisionMap;

SPRITE johnny;
SPRITE leaflets[LEAFLETSNUM];
void initialize();
void hideLeaflets();
void goToSplash();
void splashScreen();
void goToInstructions();
void instructions();
void goToAwake1();
void awake1();
void goToSleep1();
void sleep1();
void goToSleep2();
void sleep2();
void goToPause();
void pause();
void goToWin();
void win();
void goToNote1();
void note1();
void goToLivingRoom();
void livingRoom();
void playSong();
void interruptHandler();
void goToNote2();
void note2();
void goToFrontYard();
void frontYard();
void goToNote3();
void note3();
void goToNote4();
void note4();
void goToNote5();
void note5();
void goToNote6();
void note6();
void goToNote7();
void note7();
void goToNote8();
void note8();
void goToNote9();
void note9();
void goToNote10();
void note10();
void goToNote11();
void note11();
void goToLiminal1();
void liminal1();
void goToBasement();
void basement();
void showDoor();
void showCave();
void goToNightmare();
void nightmare();

unsigned int vBlankCount;
unsigned int songDuration;
unsigned int songLoops = 1;
int dur = 0;

extern enum STATE {
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
int currScreen = SPLASH;

int tempHOff = 0;
int tempVOff = 0;

extern int state = SPLASH;
SPRITE johnny;
SPRITE dimitri;

unsigned short oldButtons;
unsigned short buttons;

int main()
{
    initialize();

    while (1)
    {
        switch (state)
        {
        case SPLASH:
            splashScreen();
            break;
        case INSTRUCTIONS:
            instructions();
            break;
        case AWAKE1:
            awake1();
            break;
        case LIVINGROOM:
            livingRoom();
            break;
        case FRONTYARD:
            frontYard();
            break;
        case NOTE1:
            note1();
            break;
        case NOTE2:
            note2();
            break;
        case NOTE3:
            note3();
            break;
        case NOTE4:
            note4();
            break;
        case NOTE5:
            note5();
            break;
        case NOTE6:
            note6();
            break;
        case NOTE7:
            note7();
            break;
        case NOTE8:
            note8();
            break;
        case NOTE9:
            note9();
            break;
        case NOTE10:
            note10();
            break;
        case NOTE11:
            note11();
            break;
        case BASEMENT:
            basement();
            break;
        case LIMINAL1:
            liminal1();
            break;
        case SLEEP1:
            sleep1();
            break;
        case SLEEP2:
            sleep2();
            break;
        case PAUSE:
            pause();
            break;
        case NIGHTMARE:
            nightmare();
            break;
        case WIN:
            win();
            break;
        default:
            break;
        }

        oldButtons = buttons;
        buttons = REG_BUTTONS;
    }
}

void initialize()
{
    initJohnny();
    initLeaflets();
    initDimitri();
    initMonster();
    hideSprites();
    timer = 0;
    DMANow(3, shadowOAM, OAM, 512);
    score = 0;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    MAPWIDTH = 256;
    MAPHEIGHT = 256;

    REG_SOUNDCNT_X = SND_ENABLED;
    REG_SOUNDCNT_L = DMG_VOL_LEFT(5) |
                     DMG_VOL_RIGHT(5) |
                     DMG_SND1_LEFT |
                     DMG_SND1_RIGHT |
                     DMG_SND2_LEFT |
                     DMG_SND2_RIGHT |
                     DMG_SND3_LEFT |
                     DMG_SND3_RIGHT |
                     DMG_SND4_LEFT |
                     DMG_SND4_RIGHT;
    // REG_SOUNDCNT_H = DMG_MASTER_VOL(2);

    REG_SOUNDCNT_H = DSA_OUTPUT_TO_BOTH | DSA_TIMER0 | DSA_FIFO_RESET | DSA_OUTPUT_RATIO_100 | DMG_MASTER_VOL(2);
    REG_SND2CNT = DMG_ENV_VOL(5) | DMG_STEP_TIME(7);
    playSong();
    goToSplash();
}

void goToSplash()
{
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, SplashScreenTiles, &CHARBLOCK[0], SplashScreenTilesLen / 2);
    DMANow(3, SplashScreenPal, PALETTE, 256);
    DMANow(3, SplashScreenMap, &SCREENBLOCK[31], SplashScreenMapLen / 2);
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;

    state = SPLASH;
}

void splashScreen()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToAwake1();
    }
    if (BUTTON_PRESSED(BUTTON_SELECT))
    {
        goToInstructions();
    }
}

void goToInstructions()
{
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, InstructionsTiles, &CHARBLOCK[0], InstructionsTilesLen / 2);
    DMANow(3, InstructionsPal, PALETTE, 256);
    DMANow(3, InstructionsMap, &SCREENBLOCK[31], InstructionsMapLen / 2);

    state = INSTRUCTIONS;
}

void instructions()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToAwake1();
    }
    if (BUTTON_PRESSED(BUTTON_SELECT))
    {
        goToSplash();
    }
}

void goToAwake1()
{

    currScreen = AWAKE1;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(27) | BG_SIZE_LARGE | BG_8BPP;
    collisionMap = (unsigned char *)bedroomCollisionMapBitmap;
    DMANow(3, BedroomTiles, &CHARBLOCK[0], BedroomTilesLen / 2);
    DMANow(3, BedroomPal, PALETTE, 256);
    DMANow(3, BedroomMap, &SCREENBLOCK[27], BedroomMapLen / 2);

    DMANow(3, johnnySpritesTiles, &CHARBLOCK[4], johnnySpritesTilesLen / 2);
    DMANow(3, johnnySpritesPal, SPRITEPALETTE, johnnySpritesPalLen / 2);
    // if its active and its hidden, unhide it
    if (TotalCompleted >= NOTE6)
    {
        showDoor();
    }

    hideLeaflets();
    if (leaflets[0].active && leaflets[0].hide)
    {
        leaflets[0].hide = 0;
    }

    if (progressNum == NOTE5 && leaflets[5].active && leaflets[5].hide)
    {
        leaflets[5].hide = 0;
    }
    state = AWAKE1;
}

void awake1()
{
    updateGame();
    drawGame();

    if (progressNum == NOTE1)
    {
        goToNote1();
    }
    if (progressNum == NOTE6)
    {
        goToNote6();
    }
    // after first dream state. colides to go into empty black room
    if (TotalCompleted >= NOTE6 && collision(johnny.x, johnny.y + johnny.height - 5, johnny.width, 6, 73, 109, 20, 2))
    {
        johnny.x = 120;
        johnny.y = 208;
        goToLiminal1();
    }

    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 50, 180, 25, 5))
    {
        johnny.x = 58;
        johnny.y = 60;
        goToLivingRoom();
    }
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 175, 127, 3, 25) && johnny.sleepy && TotalCompleted >= NOTE6)
    {
        johnny.x = 58;
        johnny.y = 60;
        goToSleep2();
    }
    else if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 175, 127, 3, 25) && johnny.sleepy)
    {
        johnny.x = 58;
        johnny.y = 60;
        goToSleep1();
    }
}

void goToSleep1()
{
    currScreen = SLEEP1;
    collisionMap = (unsigned char *)sleep1CollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(27) | BG_SIZE_LARGE | BG_4BPP;
    DMANow(3, Sleep1Tiles, &CHARBLOCK[0], Sleep1TilesLen / 2);
    DMANow(3, Sleep1Pal, PALETTE, 256);
    DMANow(3, Sleep1Map, &SCREENBLOCK[27], Sleep1MapLen / 2);
    state = SLEEP1;
    progressNum = SLEEP1;
    MAPWIDTH = 512;
    MAPHEIGHT = 512;
}

void sleep1()
{

    updateGame();
    drawGame();
    if (progressNum == NOTE5)
    {
        goToNote5();
    }
    if (BUTTON_PRESSED(BUTTON_SELECT))
    {
        goToPause();
    }
}

void goToSleep2()
{
    currScreen = SLEEP2;

    collisionMap = (unsigned char *)frontYardCollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | BG_ENABLE(1) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(27) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, Sleep2Tiles, &CHARBLOCK[0], Sleep2TilesLen / 2);
    DMANow(3, Sleep2Pal, PALETTE, 256);
    DMANow(3, Sleep2Map, &SCREENBLOCK[27], Sleep2MapLen / 2);

    state = SLEEP2;
}

void sleep2()
{
    updateGame();
    drawGame();
    dur = timer % 100;
    if (dur > 50)
    {
        DMANow(3, BedroomPal, PALETTE, 256);
    }
    else
    {
        DMANow(3, Sleep2Pal, PALETTE, 256);
    }

    if (BUTTON_PRESSED(BUTTON_SELECT))
    {
        goToPause();
    }
    if (progressNum == NOTE10)
    {
        goToNote10();
    }
}

void goToPause()
{
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, PauseTiles, &CHARBLOCK[0], PauseTilesLen / 2);
    DMANow(3, PausePal, PALETTE, 256);
    DMANow(3, PauseMap, &SCREENBLOCK[31], PauseMapLen / 2);
    state = PAUSE;
}

void pause()
{
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;

    if (BUTTON_PRESSED(BUTTON_SELECT))
    {
        switch (currScreen)
        {
        case SPLASH:
            goToSplash();
            break;
        case AWAKE1:
            goToAwake1();
            break;
        case SLEEP1:
            goToSleep1();
            break;
        case SLEEP2:
            goToSleep2();
            break;
        case NOTE1:
            goToNote1();
            break;
        case NOTE2:
            goToNote2();
            break;
        case NOTE3:
            goToNote3();
            break;
        case NOTE4:
            goToNote4();
            break;
        case NOTE5:
            goToNote5();
            break;
        case NOTE6:
            goToNote6();
            break;
        case NOTE7:
            goToNote7();
            break;
        case NOTE8:
            goToNote8();
            break;
        case NOTE9:
            goToNote9();
            break;
        case NOTE10:
            goToNote10();
            break;
        case NOTE11:
            goToNote11();
            break;
        case LIMINAL1:
            goToLiminal1();
            break;
        case BASEMENT:
            goToBasement();
            break;
        case LIVINGROOM:
            goToLivingRoom();
            break;
        case NIGHTMARE:
            goToNightmare();
            break;
        case WIN:
            goToWin();
            break;
        case INSTRUCTIONS:
            goToInstructions();
            break;
        case FRONTYARD:
            goToFrontYard();
            break;
        default:
            break;
        }
    }
}

void goToWin()
{

    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, WinTiles, &CHARBLOCK[0], WinTilesLen / 2);
    DMANow(3, WinPal, PALETTE, 256);
    DMANow(3, WinMap, &SCREENBLOCK[31], WinMapLen / 2);

    state = WIN;
}

void win()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToSplash();
    }
}

void goToNote1()
{
    currScreen = NOTE1;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen1Tiles, &CHARBLOCK[0], noteScreen1TilesLen / 2);
    DMANow(3, noteScreen1Pal, PALETTE, 256);
    DMANow(3, noteScreen1Map, &SCREENBLOCK[31], noteScreen1MapLen / 2);
    state = NOTE1;
}

void note1()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        progressNum = AWAKE1;

        goToAwake1();
    }
}

void goToLivingRoom()
{
    currScreen = LIVINGROOM;
    collisionMap = (unsigned char *)livingRoomCollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(27) | BG_SIZE_LARGE | BG_8BPP;

    DMANow(3, livingRoomTiles, &CHARBLOCK[0], livingRoomTilesLen / 2);
    DMANow(3, livingRoomPal, PALETTE, 256);
    DMANow(3, livingRoomMap, &SCREENBLOCK[27], livingRoomMapLen / 2);
    // if leaflet 1 is active and hidden, unhide it
    hideLeaflets();
    if (leaflets[1].active && leaflets[1].hide)
    {
        leaflets[1].hide = 0;
    }
    progressNum = LIVINGROOM;
    state = LIVINGROOM;
}

void livingRoom()
{
    updateGame();
    drawGame();
    if (TotalCompleted >= NOTE6)
    {
        showCave();
        if (collision(johnny.x, johnny.y + johnny.height - 2, johnny.width, 2, 183, 96, 25, 2))
        {
            johnny.x = 120;
            johnny.y = 185;
            goToBasement();
        }
    }
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 52, 45, 25, 3))
    {
        progressNum = AWAKE1;
        johnny.x = 58;
        johnny.y = 140;
        goToAwake1();
    }
    if (progressNum == NOTE2)
    {
        goToNote2();
    }
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 80, 218, 30, 3))
    {
        progressNum = FRONTYARD;
        johnny.x = 128;
        johnny.y = 27;
        leaflets[1].hide = 1;
        if (TotalCompleted == NOTE10)
        {
            goToNightmare();
        }
        else
        {
            goToFrontYard();
        }
    }
}

void playSong()
{
    // ~~~ DMA ~~~
    // Turn DMA channel 1 off
    dma[1].cnt = 0;

    // DMA
    DMANow(1, Endlessly_data, REG_FIFO_A, DMA_DESTINATION_FIXED | DMA_AT_REFRESH | DMA_REPEAT);

    // ~~~ Timer ~~~
    // Turn timer 0  off
    REG_TM0CNT = 0;

    // Calculate how many ticks our song has
    int ticks = (PROCESSOR_CYCLES_PER_SECOND / Endlessly_sampleRate);

    // Set timer 0's initial value
    REG_TM0D = 65536 - ticks;

    // Turn timer 0 on
    REG_TM0CNT = TIMER_ON;

    // ~~~ Interrupts ~~~
    // Disable all interrupts in REG_IME
    REG_IME = 0;

    // Set interrupt handler in REG_INTERRUPT
    REG_INTERRUPT = interruptHandler;

    // Enable VBlank interrupt detection in REG_IE
    REG_IE = IRQ_VBLANK;

    // Make display generate VBlank interrupts in REG_DISPSTAT
    REG_DISPSTAT = DISPSTAT_VBLANK_IRQ;

    // Enable all interrupts in REG_IME
    REG_IME = 1;
    // Set vBlankCount
    vBlankCount = 0;

    // Set songDuration
    songDuration = VBLANK_FREQ * Endlessly_length / Endlessly_sampleRate;
}

void interruptHandler(void)
{
    REG_IME = 0; // Disable interrupts
    if (REG_IF & IRQ_VBLANK)
    { // If there's been a vBlank interrupt
        // Increment vBlankCount
        vBlankCount++;

        // If our song is done
        if (vBlankCount >= songDuration)
        {
            // If the song loops, play it again. Otherwise, turn it off!
            if (songLoops)
            {
                playSong();
            }
            else
            {
                // Turn DMA channel 1 off
                dma[1].cnt = 0;

                // Turn timer 0 off
                REG_TM0CNT = 0;
            }
        }
    }
    REG_IF = REG_IF; // Reset REG_IF
    REG_IME = 1;     // Enable interrupts
}

void goToNote2()
{
    currScreen = NOTE2;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen2Tiles, &CHARBLOCK[0], noteScreen2TilesLen / 2);
    DMANow(3, noteScreen2Pal, PALETTE, 256);
    DMANow(3, noteScreen2Map, &SCREENBLOCK[31], noteScreen2MapLen / 2);

    progressNum = NOTE2;
    state = NOTE2;
}

void note2()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        progressNum = LIVINGROOM;
        goToLivingRoom();
    }
}

void goToFrontYard()
{
    currScreen = FRONTYARD;
    collisionMap = (unsigned char *)frontYardCollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;

    DMANow(3, frontYardTiles, &CHARBLOCK[0], frontYardTilesLen / 2);
    DMANow(3, frontYardPal, PALETTE, 256);
    DMANow(3, frontYardMap, &SCREENBLOCK[31], frontYardMapLen / 2);
    hideLeaflets();
    if (leaflets[8].active && leaflets[8].hide && TotalCompleted >= NOTE6)
    {
        leaflets[8].hide = 0;
    }
    progressNum = FRONTYARD;
    state = FRONTYARD;
}

void frontYard()
{
    updateGame();
    drawGame();
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 10, 0, 160, 2))
    {
        johnny.x = 90;
        johnny.y = 180;
        if (TotalCompleted == NOTE3 || johnny.sleepy)
        {
            goToNote4();
        }
        else
        {
            goToLivingRoom();
        }
    }

    if (progressNum == NOTE3)
    {
        goToNote3();
    }
    if (progressNum == NOTE9)
    {
        goToNote9();
    }
}

void goToNote3()
{
    currScreen = NOTE3;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen3Tiles, &CHARBLOCK[0], noteScreen3TilesLen / 2);
    DMANow(3, noteScreen3Pal, PALETTE, 256);
    DMANow(3, noteScreen3Map, &SCREENBLOCK[31], noteScreen3MapLen / 2);

    progressNum = NOTE3;
    state = NOTE3;
}

void note3()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        if (TotalCompleted < NOTE3)
            TotalCompleted = NOTE3;
        goToFrontYard();
    }
}

void goToNote4()
{
    currScreen = NOTE4;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen4Tiles, &CHARBLOCK[0], noteScreen4TilesLen / 2);
    DMANow(3, noteScreen4Pal, PALETTE, 256);
    DMANow(3, noteScreen4Map, &SCREENBLOCK[31], noteScreen4MapLen / 2);
    johnny.sleepy = 1;

    state = NOTE4;
}

void note4()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        if (TotalCompleted < NOTE4)
            TotalCompleted = NOTE4;
        goToLivingRoom();
    }
}

void hideLeaflets()
{
    for (int i = 0; i < LEAFLETSNUM; i++)
    {
        leaflets[i].hide = 1;
    }
}

void goToNote5()
{
    currScreen = NOTE5;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen5Tiles, &CHARBLOCK[0], noteScreen5TilesLen / 2);
    DMANow(3, noteScreen5Pal, PALETTE, 256);
    DMANow(3, noteScreen5Map, &SCREENBLOCK[31], noteScreen5MapLen / 2);

    progressNum = NOTE5;
    state = NOTE5;
}

void note5()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        if (TotalCompleted < NOTE5)
            TotalCompleted = NOTE5;
        johnny.x = 120;
        johnny.y = 150;
        johnny.sleepy = 0;
        leaflets[5].hide = 0;
        leaflets[5].active = 1;
        MAPHEIGHT = 256;
        MAPWIDTH = 256;
        goToAwake1();
    }
}

void goToNote6()
{
    currScreen = NOTE6;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen6Tiles, &CHARBLOCK[0], noteScreen6TilesLen / 2);
    DMANow(3, noteScreen6Pal, PALETTE, 256);
    DMANow(3, noteScreen6Map, &SCREENBLOCK[31], noteScreen6MapLen / 2);

    progressNum = AWAKE1;
    state = NOTE6;
}

void note6()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        if (TotalCompleted < NOTE6)
            TotalCompleted = NOTE6;
        goToAwake1();
    }
}

void goToNote7()
{
    currScreen = NOTE7;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen7Tiles, &CHARBLOCK[0], noteScreen7TilesLen / 2);
    DMANow(3, noteScreen7Pal, PALETTE, 256);
    DMANow(3, noteScreen7Map, &SCREENBLOCK[31], noteScreen7MapLen / 2);

    progressNum = NOTE7;
    state = NOTE7;
}

void note7()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        if (TotalCompleted < NOTE7)
            TotalCompleted = NOTE7;
        goToLiminal1();
    }
}

void goToLiminal1()
{
    currScreen = LIMINAL1;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    collisionMap = (unsigned char *)sleep1CollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, liminal1Tiles, &CHARBLOCK[0], liminal1TilesLen / 2);
    DMANow(3, liminal1Pal, PALETTE, 256);
    DMANow(3, liminal1Map, &SCREENBLOCK[31], liminal1MapLen / 2);

    progressNum = LIMINAL1;
    state = LIMINAL1;

    hideLeaflets();
    if (leaflets[6].active && leaflets[6].hide)
    {
        leaflets[6].hide = 0;
    }
}

void liminal1()
{
    updateGame();
    drawGame();
    if (progressNum == NOTE7)
    {
        goToNote7();
    }
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 111, 251, 30, 2))
    {
        johnny.x = 82;
        johnny.y = 95;
        goToAwake1();
    }
}

void goToBasement()
{
    currScreen = BASEMENT;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    collisionMap = (unsigned char *)basementCollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | SPRITE_ENABLE;
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_8BPP;
    DMANow(3, basementTiles, &CHARBLOCK[0], basementTilesLen / 2);
    DMANow(3, basementPal, PALETTE, 256);
    DMANow(3, basementMap, &SCREENBLOCK[31], basementMapLen / 2);

    progressNum = BASEMENT;
    state = BASEMENT;

    hideLeaflets();
}

void basement()
{
    updateGame();
    drawGame();
    if (collision(johnny.x, johnny.y, johnny.width, johnny.height, 112, 230, 30, 2))
    {
        johnny.x = 183;
        johnny.y = 85;
        goToLivingRoom();
    }

    if (progressNum == NOTE8)
    {
        goToNote8();
    }
}

void showDoor()
{
    // tilemap modification
    // left side of door
    SCREENBLOCK[27].tilemap[OFFSET(10, 10, 32)] = TMAP_ENTRY_TILEID(237);
    SCREENBLOCK[27].tilemap[OFFSET(10, 11, 32)] = TMAP_ENTRY_TILEID(239);
    SCREENBLOCK[27].tilemap[OFFSET(10, 12, 32)] = TMAP_ENTRY_TILEID(241);
    SCREENBLOCK[27].tilemap[OFFSET(10, 13, 32)] = TMAP_ENTRY_TILEID(243);
    // right side of door
    SCREENBLOCK[27].tilemap[OFFSET(11, 10, 32)] = TMAP_ENTRY_TILEID(238);
    SCREENBLOCK[27].tilemap[OFFSET(11, 11, 32)] = TMAP_ENTRY_TILEID(240);
    SCREENBLOCK[27].tilemap[OFFSET(11, 12, 32)] = TMAP_ENTRY_TILEID(242);
    SCREENBLOCK[27].tilemap[OFFSET(11, 13, 32)] = TMAP_ENTRY_TILEID(244);
}

void showCave()
{
    SCREENBLOCK[27].tilemap[OFFSET(22, 9, 32)] = TMAP_ENTRY_TILEID(193);
    SCREENBLOCK[27].tilemap[OFFSET(23, 9, 32)] = TMAP_ENTRY_TILEID(194);
    SCREENBLOCK[27].tilemap[OFFSET(24, 9, 32)] = TMAP_ENTRY_TILEID(195);
    SCREENBLOCK[27].tilemap[OFFSET(25, 9, 32)] = TMAP_ENTRY_TILEID(196);

    SCREENBLOCK[27].tilemap[OFFSET(22, 10, 32)] = TMAP_ENTRY_TILEID(197);
    SCREENBLOCK[27].tilemap[OFFSET(23, 10, 32)] = TMAP_ENTRY_TILEID(198);
    SCREENBLOCK[27].tilemap[OFFSET(24, 10, 32)] = TMAP_ENTRY_TILEID(199);
    SCREENBLOCK[27].tilemap[OFFSET(25, 10, 32)] = TMAP_ENTRY_TILEID(200);

    SCREENBLOCK[27].tilemap[OFFSET(22, 11, 32)] = TMAP_ENTRY_TILEID(201);
    SCREENBLOCK[27].tilemap[OFFSET(23, 11, 32)] = TMAP_ENTRY_TILEID(202);
    SCREENBLOCK[27].tilemap[OFFSET(24, 11, 32)] = TMAP_ENTRY_TILEID(203);
    SCREENBLOCK[27].tilemap[OFFSET(25, 11, 32)] = TMAP_ENTRY_TILEID(204);
}

void goToNote8()
{

    currScreen = NOTE8;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen8Tiles, &CHARBLOCK[0], noteScreen8TilesLen / 2);
    DMANow(3, noteScreen8Pal, PALETTE, 256);
    DMANow(3, noteScreen8Map, &SCREENBLOCK[31], noteScreen8MapLen / 2);
    progressNum = NOTE8;
    state = NOTE8;
}

void note8()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToBasement();
    }
}

void goToNote9()
{
    currScreen = NOTE9;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen9Tiles, &CHARBLOCK[0], noteScreen9TilesLen / 2);
    DMANow(3, noteScreen9Pal, PALETTE, 256);
    DMANow(3, noteScreen9Map, &SCREENBLOCK[31], noteScreen9MapLen / 2);
    johnny.sleepy = 1;
    progressNum = NOTE9;
    state = NOTE9;
}

void note9()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToFrontYard();
    }
}

void goToNote10()
{
    currScreen = NOTE10;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen10Tiles, &CHARBLOCK[0], noteScreen10TilesLen / 2);
    DMANow(3, noteScreen10Pal, PALETTE, 256);
    DMANow(3, noteScreen10Map, &SCREENBLOCK[31], noteScreen10MapLen / 2);
    progressNum = NOTE10;
    if (TotalCompleted < NOTE10)
        TotalCompleted = NOTE10;
    state = NOTE10;
}

void note10()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        johnny.x = 136;
        johnny.y = 136;
        goToAwake1();
    }
}

void goToNightmare()
{
    currScreen = NIGHTMARE;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    collisionMap = (unsigned char *)frontYardCollisionMapBitmap;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0) | BG_ENABLE(1) | SPRITE_ENABLE;
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    REG_BG0CNT = BG_CHARBLOCK(1) | BG_SCREENBLOCK(27) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, nightmareBGTiles, &CHARBLOCK[0], nightmareBGTilesLen / 2);
    DMANow(3, nightmareBGPal, PALETTE, 256);
    DMANow(3, nightmareBGMap, &SCREENBLOCK[31], nightmareFGMapLen / 2);

    DMANow(3, nightmareFGTiles, &CHARBLOCK[1], nightmareFGTilesLen / 2);
    DMANow(3, nightmareFGPal, PALETTE, 256);
    DMANow(3, nightmareFGMap, &SCREENBLOCK[27], nightmareFGMapLen / 2);
    progressNum = NIGHTMARE;
    state = NIGHTMARE;
}

void nightmare()
{
    updateGame();
    drawGame();
    if (progressNum == NOTE11)
    {
        goToNote11();
    }
}

void goToNote11()
{
    currScreen = NOTE11;
    REG_BG0HOFF = 0;
    REG_BG0VOFF = 0;
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);
    REG_BG0CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL | BG_4BPP;
    DMANow(3, noteScreen11Tiles, &CHARBLOCK[0], noteScreen11TilesLen / 2);
    DMANow(3, noteScreen11Pal, PALETTE, 256);
    DMANow(3, noteScreen11Map, &SCREENBLOCK[31], noteScreen11MapLen / 2);
    progressNum = NOTE11;
    if (TotalCompleted < NOTE11)
        TotalCompleted = NOTE11;
    state = NOTE11;
}

void note11()
{
    if (BUTTON_PRESSED(BUTTON_START))
    {
        goToWin();
    }
}