#include <stdio.h>
#include <stdlib.h>
#include "AVRCPU.h"

int main()
{
    CPU::CPUFlash flash;
    CPU::AVRCPU avrcpu;

    avrcpu.setProgram(flash, "Source Files/assemblyPrograms/programTest.emulatedAssembly");

    while (!avrcpu.shutDownCPU) {
        avrcpu.runCPUProgram();
    }

    return 0;
}
