#include <fmt.h>


uint16_t	cursor_pos = 0;
uint8_t 	attr = 0x07;
FmtChar* const vidbuf = (FmtChar*)0x0b8000;

uint8_t	gen_attr	(COLOR bg, COLOR fg);

void	putch	(char c)
{
	if (isprint(c))
	{
		vidbuf[cursor_pos].Attr = attr;
		vidbuf[cursor_pos].Char = c;		
	}
	cursor_pos ++;
}

void	print	(char* s)
{
	while(s[0] != '\0')
	{
		putch(s[0]);
		s++;
	}
}

uint8_t	isprint 	(char c)
{
	return 32 <= c && c <= 126;	

}


void	clean	(void)
{
	cursor_pos = 0;
	for(int i = 0; i < 1920; i++)
	{
		vidbuf[i].Char = 0;
		vidbuf[i].Attr = 0;
	}
}
