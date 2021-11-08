#include <boot.h>
#include <fmt.h>



void	boot	(void)
{
	clean();
	print((char*)__FUNCTION__);	
	while(1);
}
