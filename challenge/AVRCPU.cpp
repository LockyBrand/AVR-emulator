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

	bool AVRCPU::CPUIsRunning() {
		
	}
	void AVRCPU::setProgram(const CPUFlash& i_PROGMEM, const std::string& filePath) {
		std::ifstream programFile(filePath);
		std::getline(programFile, )
	}
}
