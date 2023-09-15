
//{{BLOCK(Win)

//======================================================================
//
//	Win, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 77 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 2464 + 2048 = 5024
//
//	Time-stamp: 2023-05-03, 17:01:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WIN_H
#define GRIT_WIN_H

#define WinTilesLen 2464
extern const unsigned short WinTiles[1232];

#define WinMapLen 2048
extern const unsigned short WinMap[1024];

#define WinPalLen 512
extern const unsigned short WinPal[256];

#endif // GRIT_WIN_H

//}}BLOCK(Win)
