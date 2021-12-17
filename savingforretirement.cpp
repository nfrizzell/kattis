
#include <iostream>

int main()
{
    int B, Br, Bs, A, As;

    std::cin >> B >> Br >> Bs >> A >> As;

    int bob_money = (Br - B) * Bs;
    int alice_money = 0;

    while (alice_money <= bob_money)
    {
        alice_money += As;
        A++;
    }

    std::cout << A;
}
