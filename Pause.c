
//{{BLOCK(Pause)

//======================================================================
//
//	Pause, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 22 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 704 + 2048 = 3264
//
//	Time-stamp: 2023-05-03, 16:53:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short PauseTiles[352] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
	0x2222,0x2222,0x1111,0x2211,0x1111,0x2111,0x2211,0x1112,
	0x2211,0x1122,0x2211,0x1122,0x2211,0x1122,0x2211,0x1112,

	0x2222,0x2222,0x2222,0x1122,0x2222,0x1122,0x2222,0x2112,
	0x2222,0x2112,0x2222,0x2112,0x2222,0x2211,0x2222,0x2211,
	0x2222,0x2222,0x2221,0x2222,0x2221,0x2222,0x2211,0x2222,
	0x2211,0x2222,0x2211,0x2222,0x2112,0x2222,0x2112,0x2222,
	0x2222,0x2222,0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,
	0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,
	0x2222,0x2222,0x2211,0x1222,0x2211,0x1122,0x2211,0x1112,
	0x2211,0x2112,0x2211,0x2112,0x2211,0x1112,0x2211,0x1122,

	0x2222,0x2222,0x1111,0x2211,0x1111,0x2111,0x2222,0x2122,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x1111,0x2221,
	0x2222,0x2222,0x1222,0x1111,0x1222,0x1111,0x1222,0x2221,
	0x1222,0x2221,0x1222,0x2221,0x1222,0x1111,0x1222,0x1111,
	0x2222,0x2222,0x1111,0x1222,0x1111,0x1222,0x2222,0x1222,
	0x2222,0x1222,0x2222,0x1222,0x1111,0x1222,0x1111,0x1222,
	0x2222,0x2222,0x1111,0x2111,0x1111,0x1111,0x2221,0x1122,
	0x2221,0x2222,0x2221,0x2222,0x2221,0x2222,0x2221,0x2222,

	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2211,0x2222,
	0x2211,0x2222,0x2111,0x2222,0x2112,0x2222,0x2112,0x2222,
	0x1111,0x2111,0x1111,0x2211,0x2211,0x2222,0x2211,0x2222,
	0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,0x2222,0x2222,
	0x1222,0x2221,0x1222,0x1111,0x1222,0x1111,0x1122,0x2222,
	0x1122,0x2222,0x1122,0x2222,0x2112,0x2222,0x2222,0x2222,
	0x1122,0x2222,0x1111,0x2222,0x1111,0x2222,0x1222,0x2221,
	0x1222,0x2221,0x1222,0x2221,0x2222,0x2211,0x2222,0x2222,

	0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,
	0x2112,0x1222,0x1112,0x1111,0x1122,0x1111,0x2222,0x2222,
	0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,0x2211,0x2222,
	0x2221,0x2112,0x2221,0x1112,0x2222,0x1122,0x2222,0x2222,
	0x1111,0x2111,0x2222,0x1112,0x2222,0x1122,0x2222,0x1122,
	0x2222,0x1112,0x1111,0x2111,0x1111,0x2221,0x2222,0x2222,
	0x1222,0x2221,0x1222,0x2221,0x1222,0x2221,0x1222,0x2221,
	0x1222,0x2221,0x1222,0x1111,0x1222,0x1111,0x2222,0x2222,

	0x2222,0x1222,0x2222,0x1222,0x2222,0x1222,0x2222,0x1222,
	0x2222,0x1222,0x1111,0x1222,0x1111,0x1222,0x2222,0x2222,
	0x2112,0x2222,0x2112,0x2222,0x2111,0x2222,0x2211,0x2222,
	0x2221,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
};

const unsigned short PauseMap[1024] __attribute__((aligned(4)))=
{
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
	0x0009,0x000A,0x000B,0x000C,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,
	0x0013,0x0014,0x080B,0x0015,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
	0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,

	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
	0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,
};

const unsigned short PausePal[256] __attribute__((aligned(4)))=
{
	0x601F,0x7FFF,0x0000,0x4147,0x306D,0x5C00,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

//}}BLOCK(Pause)