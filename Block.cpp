#include "Block.h"

Block::Block(long long timestamp, const std::vector<Transaction> &transactions, const std::string &previousHash)
  : timestamp(timestamp), transactions(transactions), previousHash(previousHash), hash(calculateHash()), nonce(calculateNonce()) {}

