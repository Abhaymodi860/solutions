#include <iostream>
#include <queue>

using namespace std;

int lastRemainingCard(int num_of_card) {
    queue<int> cards;

    for (int i = 1; i <= num_of_card; ++i) {
        cards.push(i);
    }

    // Process the cards until only one remains
    while (cards.size() > 1) {
        // Move the top card to the bottom
        int topCard = cards.front();
        cards.pop();
        cards.push(topCard);

        // Remove the next top card
        cards.pop();
    }

    // The last remaining card
    return cards.front();
}

int main() {
    int num_of_card;
    cout << "Enter the number of cards: ";
    cin >> num_of_card;
    cout << endl;
    int result = lastRemainingCard(num_of_card);
    cout << "The last remaining card is: " << result << endl;

    return 0;
}
