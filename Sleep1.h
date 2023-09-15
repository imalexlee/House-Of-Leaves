
//{{BLOCK(Sleep1)

//======================================================================
//
//	Sleep1, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 60 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 1920 + 8192 = 10624
//
//	Time-stamp: 2023-04-25, 20:42:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SLEEP1_H
#define GRIT_SLEEP1_H

#define Sleep1TilesLen 1920
extern const unsigned short Sleep1Tiles[960];

#define Sleep1MapLen 8192
extern const unsigned short Sleep1Map[4096];

#define Sleep1PalLen 512
extern const unsigned short Sleep1Pal[256];

#endif // GRIT_SLEEP1_H

//}}BLOCK(Sleep1)
