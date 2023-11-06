#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
  std::string senderAddress;
  std::string recipientAddress;
  double amount;
  std::string data;

public:
  Transaction(const std::string& sender, const std::string& recipient, double amt, const std::string& data);

  std::string getSenderAddress() const;
  std::string getRecipientAddress() const;
  double getAmount() const;
  std::string getData() const;
};

#endif
