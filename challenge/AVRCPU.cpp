#include "AVRCPU.h"
#include <fstream>

namespace CPU {
	CPUFlash::CPUFlash() {

	}

	CPUFlash::~CPUFlash() {

	}

	Word& CPUFlash::operator[](const Word& i_addr) {
		return PROGMEM[i_addr];
	}

	AVRCPU::AVRCPU() : shutDownCPU(false) {
		
	}
	AVRCPU::~AVRCPU() {

	}

	void AVRCPU::setProgram(const CPUFlash& i_PROGMEM, const std::string& filePath) {
		std::ifstream programFile(filePath, std::ios::in|std::ios::binary);
		unsigned int counter = 0;
		while (programFile.peek() != EOF) {
			Word byteStream;
			programFile >> byteStream;
			PROGMEM[counter] = byteStream;
			counter++;
		}
	}
	void AVRCPU::executeCPUInstruction(const Word& i_memAddr) {
		switch (CPUFlash::PROGMEM[i_memAddr]) {
		case NOP:
			PC++;
			break;
		case SLEEP:
			shutDownCPU = true;
			break;
		}
	}
	void AVRCPU::runCPUProgram() {
		executeCPUInstruction(CPUFlash::PROGMEM[PC]);
	}
}
