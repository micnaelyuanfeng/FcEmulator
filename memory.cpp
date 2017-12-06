 #include "memory.hpp"
 
 void MEMORY::_memory_init()
 {
	 
 }
 
 void MEMORY::_memory_read_byte(MEMADDRESS memAddress)
 {
	if(memAddress > -1)
	{
		ASSERT("Error: Memory Access Failed");
	}
	
	__memory_read_byte(memAddress);
	
 }
 
 void MEMORY::__memory_read_byte(MEMADDRESS memAddress)
 {
	switch(memAddress >> 13)
	{
		case MEM_RAM_REGION:
			return gpRam[memAddress];
			break;
		case MEM_PPU_REGION:
			
			break;
		case MEM_APU_REGION:
			
			break;
		case MEM_SAV_REGION:
			
			break;
		case MEM_ROM_REGION:
			
			break;
		default:
			
			break;
	} 
 }