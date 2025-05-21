#include  <iostream>

int main() {
	int number { 0 };
	int term {}; // fibo numb to the nth term
	int prev_a {0};
	int prev_b {0};
	std::cout << "enter the term to reach\n";
	std::cin >> term;
	
	std::cout << number << '\n';
	for(int n = 0; n < term; n++) {
		if(n < 1) {
			prev_b = 0;
			prev_a = 1;
			number = prev_a + prev_b;

			std::cout << number << '\n';
			continue;
		}

		number = prev_a + prev_b;
		prev_b = prev_a;
		prev_a = number;

		std::cout << number << '\n';

	}
}
