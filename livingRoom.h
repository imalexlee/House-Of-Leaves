
//{{BLOCK(livingRoom)

//======================================================================
//
//	livingRoom, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 205 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 13120 + 8192 = 21824
//
//	Time-stamp: 2023-05-02, 16:37:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LIVINGROOM_H
#define GRIT_LIVINGROOM_H

#define livingRoomTilesLen 13120
extern const unsigned short livingRoomTiles[6560];

#define livingRoomMapLen 8192
extern const unsigned short livingRoomMap[4096];

#define livingRoomPalLen 512
extern const unsigned short livingRoomPal[256];

#endif // GRIT_LIVINGROOM_H

//}}BLOCK(livingRoom)
