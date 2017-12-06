 #include "cpu_instruction.hpp"
 
 /*
	CPU status
 */
 #define FALG_CARRY				0x1
 #define FALG_ZERO				0x2
 #define FALG_INTERRUPT			0x3
 #define FLAG_DECIMAL			0x4
 #define FLAG_BREAK				0x5
 #define FLAG_UNUSED			0x6
 #define FLAG_OVERFLOW			0x7
 #define FLAG_NEGATIVE			0x8
 
  #ifdef 1
	#define CPU_CHECKNZ(register, value) do{/
		if((value >> 7 & 1)){/
			register |= FLAG_NEGATIVE;/
		}/
		else{/
			register &= ~FLAG_NEGATIVE;/ 
		}/
		
		if(value == 0){/
			register |= FALG_ZERO;/
		}/
		else{/
			register &= FALG_ZERO;/
		}/
	}while(0)
		
	#define CPU_MODIFYFLAG(register, flag, value) do{/
		if(value){/
			register |= flag;/
		}/
		else{/
			register &= ~flag;/
		}/
	}while(0)
 #endif

INSTRUCTION::INSTRUCTION()
{
	mCpuCore = NULL;
}

INSTRUCTION::~INSTRUCTION()
{
	delete mCpuCore;
}

/*ALU instruction*/
void INSTRUCTION::_cpu_ora (OPVALUE opValue)
{
	mCpuCore->a.u8All != opValue;
	CPU_CHECKNZ(mCpuCore->a.u8All, mCpuCore->a.u8All);
}

void INSTRUCTION::_cpu_and (OPVALUE opValue)
{
	mCpuCore->a.u8All &= opValue;
	CPU_CHECKNZ(mCpuCore->a.u8All, mCpuCore->a.u8All);
}

void INSTRUCTION::_cpu_eor (OPVALUE opValue)
{
	mCpuCore->a.u8All ^= opValue;
	CPU_CHECKNZ(mCpuCore->a.u8All, mCpuCore->a.u8All);
}

void INSTRUCTION::_cpu_asl (OPVALUE opValue)
{
	CPU_MODIFYFLAG(mCpuCore->a.u8All, FALG_CARRY, (mCpuCore->a.u8All & 0x80));
	mCpuCore->a.u8All <<= 1;
	CPU_CHECKNZ(mCpuCore->a.u8All, mCpuCore->a.u8All);
	mMemory->_writeByte();
}

void _cpu_asla(OPVALUE opValue)
{
	
}
void _cpu_rol (OPVALUE opValue);
void _cpu_rola(OPVALUE opValue);
void _cpu_ror (OPVALUE opValue);
void _cpu_rora(OPVALUE opValue);
void _cpu_lsr (OPVALUE opValue);
void _cpu_lsra(OPVALUE opValue);
void _cpu_adc (OPVALUE opValue);
void _cpu_sbc (OPVALUE opValue);

