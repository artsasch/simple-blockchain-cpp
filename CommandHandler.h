#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "Wallet.h"
#include "Block.h"
#include "Transaction.h"
#include "Blockchain.h"
#include <vector>
#include <string>

void handleCreateWallet(Wallet*& w, const std::vector<std::string>& commands);
void handlePrintWallet(Wallet* w);
void handleCreateBlock(Block*& b);
void handleCreateTransaction(Wallet*& w, Block*& b, Transaction*& t, const std::vector<std::string>& commands);
void handlePrintBlockTransactions(Block*& b);
void handleAddBlockInBlockchain(Blockchain*& chain, Block*& b, const int& difficulty);
void handlePrintBlockchainBlocks(Blockchain*& chain);

#endif