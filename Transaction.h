#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <openssl/rsa.h>

class Transaction {
private:
  std::string senderAddress;
  std::string recipientAddress;
  double amount;
  std::string signature;

public:
  Transaction(std::string sender, std::string recipient, double amt);
  std::string calculateHash() const;
  void signTransaction(RSA* privateKey);
  bool verifyTransaction() const;
  std::string getSenderAddress() const;
  std::string getRecipientAddress() const;
  double getAmount() const;
  std::string getSignature() const;
};

#endif
