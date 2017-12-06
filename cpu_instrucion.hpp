 #ifndef _CPU_INSTRUTION_
 #define _CPU_INSTRUTION_
 
 #include "type.hpp"
 #include "utility.hpp"
 
 class MOS_6205;
 
 
 class INSTRUCTION
 {
	public:
		INSTRUCTION();
		~INSTRUCTION();
	
		/*ALU instruction*/
		void _cpu_ora (OPVALUE opValue);
		void _cpu_and (OPVALUE opValue);
		void _cpu_eor (OPVALUE opValue);
		void _cpu_asl (OPVALUE opValue);
		void _cpu_asla(OPVALUE opValue);
		void _cpu_rol (OPVALUE opValue);
		void _cpu_rola(OPVALUE opValue);
		void _cpu_ror (OPVALUE opValue);
		void _cpu_rora(OPVALUE opValue);
		void _cpu_lsr (OPVALUE opValue);
		void _cpu_lsra(OPVALUE opValue);
		void _cpu_adc (OPVALUE opValue);
		void _cpu_sbc (OPVALUE opValue);
		
		/*Branching*/
		void _cpu_bmi(void);
		void _cpu_bcs(void); 
		void _cpu_beq(void);
		void _cpu_bvs(void); 
		
		/*Compare*/
		void _cpu_bit(OPVALUE opValue);
		void _cpu_cmp(OPVALUE opValue);
		void _cpu_cpx(OPVALUE opValue);
		void _cpu_cpy(OPVALUE opValue);
		
		/*Increament and Decreament*/
		void _cpu_dec(void);
		void _cpu_dex(void);
		void _cpu_inc(void);
		void _cpu_inx(void);
		
		/*Load and Store*/
		void _cpu_lda(OPVALUE opValue);
		void _cpu_ldx(OPVALUE opValue);
		void _cpu_ldy(OPVALUE opValue);
		void _cpu_sda(OPVALUE opValue);
		void _cpu_stx(OPVALUE opValue);
		void _cpu_sty(OPVALUE opValue);
		
		/*NOP*/
		void _cpu_nop(void);
		
		/*Stack Operations*/
		void _cpu_pusha(void);
		void _cpu_pushp(void);
		void _cpu_popla(void);
		void _cpu_poplp(void);
		void _cpu_popw (void);
		void _cpu_popb (void);
		
		/*Jump Operations*/
		void _cpu_jmp(void);
		void _cpu_jsr(void);
		void _cpu_brk(void);
		
		/*Transfer*/
		void _cpu_tax(void);
		void _cpu_tay(void);
		void _cpu_txa(void);
		void _cpu_tya(void);
		void _cpu_tsx(void);
		void _cpu_txs(void);
		
		
	private:
		MOS_6205*     mCpuCore;
		MEMORY*   	  mMemory;
		MEMORYADDRESS memoryAddress;
 };
  
 #endif
 