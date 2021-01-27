#include "AVRCPU.h"

namespace CPU {
	CPUFlash::CPUFlash() : PROGMEM{NOP} {

	}

	CPUFlash::~CPUFlash() {

	}

	Byte CPUFlash::operator[](const Word& i_addr) {
		return PROGMEM[i_addr];
	}


}
