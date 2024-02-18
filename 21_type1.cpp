#include "iostream"

bool playNextTurn(int heap1, int heap2, int turn) {
	if ((turn == 3 || turn == 5) && heap1 + heap2 <= 20) return true;
	else if (turn == 5 && heap1 + heap2 > 20) return false;//If the game won't end at this point or end prematurely
	else if (turn !=3 && turn != 5 && heap1 + heap2 <= 20) return false;//Then this value don't fit
	else if (turn % 2 != 1) return
			   playNextTurn(heap1 - 1, heap2, turn + 1) 
			|| playNextTurn(heap1, heap2 - 1, turn + 1)
			|| playNextTurn(heap1 / 2 + heap1 % 1, heap2, turn + 1)
			|| playNextTurn(heap1, heap2 / 2 + heap2 % 1, turn + 1);

	return
		   playNextTurn(heap1 - 1, heap2, turn + 1)
		&& playNextTurn(heap1, heap2 - 1, turn + 1)
		&& playNextTurn(heap1 / 2 + heap1 % 1, heap2, turn + 1)
		&& playNextTurn(heap1, heap2 / 2 + heap2 % 1, turn + 1);
}

int main() {
	for (int i = 11; i < 1000; i++) {
		if (playNextTurn(i, 10, 1)) std::cout << i << '\n';
	}
}
