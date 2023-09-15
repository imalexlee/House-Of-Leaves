
//{{BLOCK(basement)

//======================================================================
//
//	basement, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 113 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 7232 + 2048 = 9792
//
//	Time-stamp: 2023-05-02, 17:47:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BASEMENT_H
#define GRIT_BASEMENT_H

#define basementTilesLen 7232
extern const unsigned short basementTiles[3616];

#define basementMapLen 2048
extern const unsigned short basementMap[1024];

#define basementPalLen 512
extern const unsigned short basementPal[256];

#endif // GRIT_BASEMENT_H

//}}BLOCK(basement)
