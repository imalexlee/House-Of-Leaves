
//{{BLOCK(Instructions)

//======================================================================
//
//	Instructions, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 314 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 10048 + 2048 = 12608
//
//	Time-stamp: 2023-05-03, 17:20:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_INSTRUCTIONS_H
#define GRIT_INSTRUCTIONS_H

#define InstructionsTilesLen 10048
extern const unsigned short InstructionsTiles[5024];

#define InstructionsMapLen 2048
extern const unsigned short InstructionsMap[1024];

#define InstructionsPalLen 512
extern const unsigned short InstructionsPal[256];

#endif // GRIT_INSTRUCTIONS_H

//}}BLOCK(Instructions)
