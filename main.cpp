#include "Transaction.h"
#include "Wallet.h"
#include "Block.h"
#include "Blockchain.h"
#include <iostream>
#include <string>

int main() {
    Blockchain* chain = Blockchain::getInstance();
    Wallet w(100.0);

    std::string privateKey = w.getPrivateKey();
    std::string publicKey = w.getPublicKey();
    std::string address = w.getAddress();
    double balance = w.getBalance();

    std::cout << "Wallet privateKey: " << privateKey << std::endl;
    std::cout << "Wallet publicKey: " << publicKey << std::endl;
    std::cout << "Wallet address: " << address << std::endl;
    std::cout << "Wallet balance: " << balance << std::endl;

    Transaction t1{"sender1", "recipient1", 15.0, "transaction1)"};
    Transaction t2{"sender2", "recipient2", 25.0, "transaction2)"};

    Block b;
    b.addTransaction(t1);
    b.addTransaction(t2);
    b.printBlockTransactions();

    chain->addBlock(b);
    chain->printBlockchainBlocks();
}