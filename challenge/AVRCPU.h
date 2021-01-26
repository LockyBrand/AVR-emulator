#pragma once
#include <unordered_map>

namespace CPU {
	using Byte = unsigned char;
	using Byte16 = unsigned short;

	struct instructions {
		Byte16 NOP = 0x0;
		
	};

	struct CPUFlash {
		Byte PROGMEM[256000];
	};

	struct CPUREG {
		Byte REG[32];
	};

	struct CPUDATASRAM {
		Byte SRAM[8192];

		Byte operator[] (const Byte16& addr); 
	};

	class AVRCPU {
	public:
		AVRCPU(CPUFlash& i_flashMem, CPUREG& i_RAM);
		~AVRCPU();

		void executeCPUInstruction(const instructions& i_instruction);
	private:
		CPUFlash& m_flash; //program memory
		CPUREG& m_REG; //SRAM of CPU

		// status register - SREG
		Byte C : 1; // Carry Flag
		Byte Z : 1; // Zero Flag
		Byte N : 1; // Negative Flag
		Byte V : 1; // Two's complement overflow Flag
		Byte S : 1; // N ^ V Flag, for signed tests
		Byte H : 1; // Half Carry Flag
		Byte T : 1; // Transfer bit used by BLD and BST instructions
		Byte I : 1; // Global Interrupt Enable/Disable Flag


	};
}