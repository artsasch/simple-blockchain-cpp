#include "Blockchain.h"
#include "Block.h"

Blockchain* Blockchain::instance = nullptr;

void Blockchain::addBlock(const Block &block) {
  chain.push_back(block);
}

void Blockchain::printBlockchainBlocks() const {
  std::cout << "--------------------------" << std::endl;
  for (const Block& block : chain) {
    block.printBlock();
    std::cout << "--------------------------" << std::endl;
  }
}

Blockchain* Blockchain::getInstance() {
  if (instance == nullptr) {
    instance = new Blockchain();
  }
  return instance;
}