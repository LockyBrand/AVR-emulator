#pragma once
#include <string>

namespace CPU {
	using Byte = unsigned char;
	using Word = unsigned short;

	class CPUFlash {
	public:
		CPUFlash();
		~CPUFlash();
	protected:
		static Word PROGMEM[256000];
		Word& operator[] (const Word& i_addr); // addressed by 16-bit words for the purpose of getting CPU instructions

		// instruction list
		Word NOP = 0x0000;
		Word SLEEP = 0x9588;
	};

	class CPUREG {
	protected:
		Byte GPREG[32];
	};

	class CPUDATASRAM {
	protected:
		Byte SRAM[8192];
	};

	class AVRCPU : private CPUFlash, private CPUREG, private CPUDATASRAM {
	public:
		AVRCPU();
		~AVRCPU();

		void executeCPUInstruction(const Word& i_memAddr);
		void setProgram(const CPUFlash& i_PROGMEM, const std::string& filePath);
		bool CPUIsRunning();

		bool shutDownCPU;
	private:

		// status bits - SREG
		Byte C : 1; // Carry Flag
		Byte Z : 1; // Zero Flag
		Byte N : 1; // Negative Flag
		Byte V : 1; // Two's complement overflow Flag
		Byte S : 1; // N ^ V Flag, for signed tests
		Byte H : 1; // Half Carry Flag
		Byte T : 1; // Transfer bit used by BLD and BST instructions
		Byte I : 1; // Global Interrupt Enable/Disable Flag

		Word PC; // program counter
		Word SP; // stack pointer

		// segment registers to prepend and address 16 bit and 24 bit addresses
		Byte RAMPX;
		Byte RAMPY;
		Byte RAMPZ;
		Byte RAMPD;
		Byte EIND;
	};
}