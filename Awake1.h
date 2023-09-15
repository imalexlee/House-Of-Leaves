
//{{BLOCK(Awake1)

//======================================================================
//
//	Awake1, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 64 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 2048 + 8192 = 10752
//
//	Time-stamp: 2023-04-02, 19:31:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AWAKE1_H
#define GRIT_AWAKE1_H

#define Awake1TilesLen 2048
extern const unsigned short Awake1Tiles[1024];

#define Awake1MapLen 8192
extern const unsigned short Awake1Map[4096];

#define Awake1PalLen 512
extern const unsigned short Awake1Pal[256];

#endif // GRIT_AWAKE1_H

//}}BLOCK(Awake1)
