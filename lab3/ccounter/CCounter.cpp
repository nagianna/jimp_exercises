#include "CCounter.h"
using ccounter::Counter;

std::unique_ptr<Counter> ccounter::Init() {
    std::unique_ptr<Counter> newStructPointer = std::make_unique<Counter>();
    return newStructPointer;
}

void ccounter::Inc (std::string key, std::unique_ptr<Counter>* counter) {
    std::cout << counter;
}

int ccounter::Counts(const std::unique_ptr<Counter> &counter, std::string key) {

}

void ccounter::SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {

}