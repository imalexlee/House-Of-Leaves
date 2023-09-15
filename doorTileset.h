
//{{BLOCK(doorTileset)

//======================================================================
//
//	doorTileset, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 160 + 2048 = 2720
//
//	Time-stamp: 2023-05-02, 13:25:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DOORTILESET_H
#define GRIT_DOORTILESET_H

#define doorTilesetTilesLen 160
extern const unsigned short doorTilesetTiles[80];

#define doorTilesetMapLen 2048
extern const unsigned short doorTilesetMap[1024];

#define doorTilesetPalLen 512
extern const unsigned short doorTilesetPal[256];

#endif // GRIT_DOORTILESET_H

//}}BLOCK(doorTileset)
