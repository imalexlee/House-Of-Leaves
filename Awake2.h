
//{{BLOCK(Awake2)

//======================================================================
//
//	Awake2, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 72 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 2304 + 8192 = 11008
//
//	Time-stamp: 2023-04-02, 19:32:04
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AWAKE2_H
#define GRIT_AWAKE2_H

#define Awake2TilesLen 2304
extern const unsigned short Awake2Tiles[1152];

#define Awake2MapLen 8192
extern const unsigned short Awake2Map[4096];

#define Awake2PalLen 512
extern const unsigned short Awake2Pal[256];

#endif // GRIT_AWAKE2_H

//}}BLOCK(Awake2)
