#include <stdio.h>
#include <stdlib.h>
#include "AVRCPU.h"

int main()
{
    CPU::CPUFlash flash;
    CPU::AVRCPU avrcpu;

    avrcpu.setProgram(flash, "Source Files/assemblyPrograms/program1.assembly");

    while (!avrcpu.shutDownCPU) {
        avrcpu.executeCPUInstruction();
    }

    return 0;
}
