#include "Block.h"
#include "Transaction.h"
#include <iostream>
#include <Windows.h>

int main() {
    Transaction t1("sender1", "recipient1", 25.0, "hello) buy some shoes");
    Transaction t2("sender2", "recipient2", 35.0, "buy me burger pls");
    Transaction t3("sender3", "recipient3", 15.0, "for your work");

    Block b1({t1, t2, t3}, "0");

    Sleep(1000);

    Transaction t4("sender1", "recipient1", 25.0, "hello) buy some shoes");
    Transaction t5("sender2", "recipient2", 35.0, "buy me burger pls");
    Transaction t6("sender3", "recipient3", 15.0, "for your work");

    Block b2({t4, t5, t6}, b1.getHash());

    b1.printBlock();
    std::cout << "b1 Block transactions" << std::endl;
    b1.printBlockTransactions();
    std::cout << "--------------------------" << std::endl;
    b2.printBlock();
    std::cout << "b2 Block transactions" << std::endl;
    b2.printBlockTransactions();
}
