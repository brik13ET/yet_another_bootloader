#ifndef FMT_H
#define FMT_H

#include <stdint.h>

typedef enum
{
	black	= 0x0,
	blue	= 0x1,
	green	= 0x2,
	cyan	= 0x3,
	red	= 0x4,
	magenta	= 0x5,
	brown	= 0x6,
	dark	= 0x7,
	gray	= 0x8,
	l_blue	= 0x9,
	l_green	= 0xA,
	l_cyan	= 0xB,
	l_red	= 0xC,
	l_magenta	= 0xD,
	yellow	= 0xE,
	white	= 0xF
} COLOR;

struct FmtChar
{
	
	uint8_t Attr;
	uint8_t Char;
} __attribute__((packed));

typedef struct FmtChar FmtChar;

extern FmtChar* const vidbuf;

extern	uint16_t	cursor_pos;
extern	uint8_t 	attr;

uint8_t	isprint 	(char);
uint8_t	gen_attr	(COLOR bg, COLOR fg);
void	putch	(char);
void	print	(char*);
void	clean	(void);

#endif
