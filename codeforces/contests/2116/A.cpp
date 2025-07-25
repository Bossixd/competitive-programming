#include <iostream>

using namespace std;

void run() {
    int gelly, flower, gellyKnight, flowerKnight;
    cin >> gelly >> flower >> gellyKnight >> flowerKnight;

    int gellyMoves, flowerMoves;

    gellyMoves = min(flower, flowerKnight);
    flowerMoves = min(gelly, gellyKnight);

    if (gellyMoves <= flowerMoves) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int main() {
    int N;
    cin >> N;
    while (N--)
        run();
}

/*

My HP  : 2
My Kni : 1

Th HP  : 2
Th Kni : 1

I will kill the knight asap, so if their knight < my hp or my kni, I win.
If I can kill them definitely before they kill me, so they < my hp or my kni, I win.

My HP  : 10
My Kni : 2

Th HP  : 2
Th Kni : 5

*/

