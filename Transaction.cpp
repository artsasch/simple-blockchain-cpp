#include "Transaction.h"

Transaction::Transaction(const std::string &sender, const std::string &recipient, double amt, const std::string &data)
  : senderAddress(sender), recipientAddress(recipient), amount(amt), data(data) {}

std::string Transaction::getSenderAddress() const {
  return senderAddress;
}

std::string Transaction::getRecipientAddress() const {
  return recipientAddress;
}

double Transaction::getAmount() const {
  return amount;
}

std::string Transaction::getData() const {
  return data;
}