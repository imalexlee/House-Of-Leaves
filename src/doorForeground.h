
//{{BLOCK(doorForeground)

//======================================================================
//
//	doorForeground, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 160 + 2048 = 2720
//
//	Time-stamp: 2023-05-02, 13:32:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DOORFOREGROUND_H
#define GRIT_DOORFOREGROUND_H

#define doorForegroundTilesLen 160
extern const unsigned short doorForegroundTiles[80];

#define doorForegroundMapLen 2048
extern const unsigned short doorForegroundMap[1024];

#define doorForegroundPalLen 512
extern const unsigned short doorForegroundPal[256];

#endif // GRIT_DOORFOREGROUND_H

//}}BLOCK(doorForeground)
