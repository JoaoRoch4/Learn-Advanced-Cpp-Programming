#include <iostream>
#include <list>
#include <locale>
#include <memory>
#include <string>
#include <print>

int main() {

	std::locale::global(std::locale("pt_BR.utf8"));

	std::wcout << L"author: João André Rocha. \n\n";

	auto ilsNumbers{std::make_unique<std::list<int>>()};

	ilsNumbers->push_back(1);
	ilsNumbers->push_back(2);
	ilsNumbers->push_back(3);
	ilsNumbers->push_front(0);

	auto ils_iterIt {std::make_unique<std::list<int>::iterator>(ilsNumbers->begin())};

	(*ils_iterIt)++;

	ilsNumbers->insert(*ils_iterIt, 100);

	std::cout << "Element: " << **ils_iterIt << "\n\n";

	auto ils_iterIt2 {std::make_unique<std::list<int>::iterator>(ilsNumbers->begin())};

	(*ils_iterIt2)++;

	*ils_iterIt2 = ilsNumbers->erase(*ils_iterIt2);

	std::cout << "Element: " << **ils_iterIt2 << "\n\n";
	
	auto it = ilsNumbers->begin();

	while (it != ilsNumbers->end()) {

		if (*it == 2) ilsNumbers->insert(it, 1234);
		
		if (*it == 1) it = ilsNumbers->erase(it);
		 else  it++;		
	}
	
	std::println("\n");

	for (auto& it : *ilsNumbers) std::cout << it << ' ';

	std::cin.get();
	return 0;
}

