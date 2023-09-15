
//{{BLOCK(Bedroom)

//======================================================================
//
//	Bedroom, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 245 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 15680 + 8192 = 24384
//
//	Time-stamp: 2023-05-02, 15:01:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BEDROOM_H
#define GRIT_BEDROOM_H

#define BedroomTilesLen 15680
extern const unsigned short BedroomTiles[7840];

#define BedroomMapLen 8192
extern const unsigned short BedroomMap[4096];

#define BedroomPalLen 512
extern const unsigned short BedroomPal[256];

#endif // GRIT_BEDROOM_H

//}}BLOCK(Bedroom)
