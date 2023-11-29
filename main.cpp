#include "CommandHandler.h"
#include "Transaction.h"
#include "Wallet.h"
#include "Block.h"
#include "Blockchain.h"
#include <iterator>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string& str) {
  std::istringstream iss(str);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
  return results;
}

int main() {
    std::string input;
    Blockchain* chain = Blockchain::getInstance();
    Wallet* w = nullptr;
    Block* b = nullptr;
    Transaction* t = nullptr;

    while (true) {
      std::cout << "> ";
      std::getline(std::cin, input);
      std::vector<std::string> commands = split(input);

      if (commands.empty())
        continue;

      if (commands[0] == "exit")
        break;

      if (commands[0] == "cw")
        handleCreateWallet(w, commands);

      if (commands[0] == "pw")
        handlePrintWallet(w);

      if (commands[0] == "cb")
        handleCreateBlock(b);

      if (commands[0] == "ct")
        handleCreateTransaction(w, b, t, commands);

      if (commands[0] == "pbt")
        handlePrintBlockTransactions(b);

      if (commands[0] == "abib")              //haha abib)
        handleAddBlockInBlockchain(chain, b, 3);

      if (commands[0] == "pc")
        handlePrintBlockchainBlocks(chain);
    }

    delete chain;
    delete w;
    delete b;
    delete t;
}