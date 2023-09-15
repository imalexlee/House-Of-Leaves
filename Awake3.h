
//{{BLOCK(Awake3)

//======================================================================
//
//	Awake3, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 73 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 2336 + 8192 = 11040
//
//	Time-stamp: 2023-04-02, 19:33:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AWAKE3_H
#define GRIT_AWAKE3_H

#define Awake3TilesLen 2336
extern const unsigned short Awake3Tiles[1168];

#define Awake3MapLen 8192
extern const unsigned short Awake3Map[4096];

#define Awake3PalLen 512
extern const unsigned short Awake3Pal[256];

#endif // GRIT_AWAKE3_H

//}}BLOCK(Awake3)
