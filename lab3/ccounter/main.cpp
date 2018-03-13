#include "CCounter.h"
using ccounter::Counter;

int main() {
    std::unique_ptr<Counter> newStruct = ccounter::Init();
    return 0;
}
