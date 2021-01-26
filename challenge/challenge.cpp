#include <stdio.h>
#include <stdlib.h>

class memory {
public:
    memory() {};
    ~memory() {};
};

class AVRCPU {
public:
    AVRCPU(memory& i_memBloc) : m_memBloc(i_memBloc) {};
    ~AVRCPU() {};

    void executeInstructions() {};
private:
    memory& m_memBloc;
};

int main()
{
    

    return 0;
}
