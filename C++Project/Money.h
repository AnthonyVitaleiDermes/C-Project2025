#include <iostream>

class Money
{
private:
	float moneyAmt;

public:
    Money(float moneyAmount = 0.0) : moneyAmt(moneyAmount) {}

    void setAmount(float moneyAmount) {
        moneyAmt = moneyAmount;
    }

     float getAmount() const {
        return moneyAmt;
    }

    void display() const {
        std::cout << "$" << moneyAmt << std::endl;
    }
};



