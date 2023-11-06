#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Transaction.h"

class Wallet {
private:
  std::string privateKey;
  std::string publicKey;
  std::string address;
  double balance;

  std::string generatePrivateKey() const;
  std::string generatePublicKey(const std::string& privateKey) const;
  std::string generateAddress(const std::string& publicKey) const;

public:
  Wallet();

  void signTransaction(Transaction& transaction);
  double getBalance() const;
  std::string getAddress() const;
  std::string getPublicKey() const;
};

#endif
