
//{{BLOCK(Pause)

//======================================================================
//
//	Pause, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 22 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 704 + 2048 = 3264
//
//	Time-stamp: 2023-05-03, 16:53:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSE_H
#define GRIT_PAUSE_H

#define PauseTilesLen 704
extern const unsigned short PauseTiles[352];

#define PauseMapLen 2048
extern const unsigned short PauseMap[1024];

#define PausePalLen 512
extern const unsigned short PausePal[256];

#endif // GRIT_PAUSE_H

//}}BLOCK(Pause)
