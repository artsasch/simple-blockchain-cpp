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
    Blockchain* chain = Blockchain::getInstance();

    std::string input;
    Wallet* w = nullptr;
    Block* b = nullptr;
    Transaction* t = nullptr;
    std::string prevBlockHash;

    while (true) {
      std::cout << "> ";
      std::getline(std::cin, input);
      std::vector<std::string> commands = split(input);

      if (commands.empty()) continue;

      if (commands[0] == "exit") {
        break;
      }

      if (commands[0] == "createwallet") {
        handleCreateWallet(w, commands);
      }

      if (commands[0] == "printwallet") {
        handlePrintWallet(w);
      }

      if (commands[0] == "createblock") {
        if (b != nullptr) {
          prevBlockHash = b->getHash();
          delete b;
          b = new Block(prevBlockHash);
        } else {
          delete b;
          b = new Block();
        }
        std::cout << "Block created." << std::endl;
      }

      if (commands[0] == "createtr") {
        delete t;
        std::string transactionSender = commands[1];
        std::string transactionRecipient = commands[2];
        int transactionAmount = std::stoi(commands[3]);
        std::string transactionData = commands[4];
        t = new Transaction(transactionSender, transactionRecipient, transactionAmount, transactionData);
        b->addTransaction(*t);
        std::cout << "Transaction created and added to block." << std::endl;
      }

      if (commands[0] == "printblocktrs") {
        b->printBlockTransactions();
      }

      if (commands[0] == "addblockinblockchain") {
        chain->addBlock(*b);
        std::cout << "Block added in blockchain." << std::endl;
      }

      if (commands[0] == "printchain") {
        chain->printBlockchainBlocks();
      }

    }
    delete w;
    delete b;
    delete t;


//    Wallet w(100.0);
//
//    w.printWallet();
//
//    Transaction t1{"sender1", "recipient1", 15.0, "transaction1"};
//    Transaction t2{"sender2", "recipient2", 25.0, "transaction2"};
//
//    Block b1;
//    b1.addTransaction(t1);
//    chain->addBlock(b1);
//
//    Block b2(b1.getHash());
//    b2.addTransaction(t2);
//    chain->addBlock(b2);
//
//    chain->printBlockchainBlocks();
}