import std;

void test(int value) {

    std::cout << "Hello\n" << value;
}

int main() {

    void (*pTest)(int) { &test };

    (*pTest)(std::numeric_limits<int>::max());

    std::cin.get();
    return 0;

}


// hello
