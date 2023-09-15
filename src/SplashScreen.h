
//{{BLOCK(SplashScreen)

//======================================================================
//
//	SplashScreen, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 476 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 15232 + 2048 = 17792
//
//	Time-stamp: 2023-05-03, 16:56:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPLASHSCREEN_H
#define GRIT_SPLASHSCREEN_H

#define SplashScreenTilesLen 15232
extern const unsigned short SplashScreenTiles[7616];

#define SplashScreenMapLen 2048
extern const unsigned short SplashScreenMap[1024];

#define SplashScreenPalLen 512
extern const unsigned short SplashScreenPal[256];

#endif // GRIT_SPLASHSCREEN_H

//}}BLOCK(SplashScreen)
