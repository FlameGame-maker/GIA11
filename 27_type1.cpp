#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"


class Element {
public:
	Element(unsigned int a_value, unsigned int a_index) : value(a_value), index(a_index) {}

	inline bool operator < (const Element& arg) const {
		return value < arg.value;
	}

public:
	unsigned int value;
	unsigned int index;
};


void solution() {
	std::ifstream reader;
	reader.open("27-B_1.txt");

	unsigned int  n;
	reader >> n;
	std::vector<Element> input;
	input.reserve(n * 2);

	unsigned int index = 0;
	while (reader >> n) {
		input.push_back(Element(n, index / 2));
		index++;
	}

	
	std::sort(input.begin(), input.end());
	std::reverse(input.begin(), input.end());/To change sorting order

	unsigned long sum = 0;

	std::vector<Element> usedElements;
	usedElements.reserve(input.size() / 2);
	for (unsigned int i = 0; i < input.size() / 2; i++) usedElements.push_back(Element(0, -1));

	for (unsigned int i = 0; i < input.size(); i++) {
		if (usedElements[input[i].index].index == -1) usedElements[input[i].index] = (Element(input[i].value, i));//Checking if one element of pair was already used
	}

	for (unsigned int i = 0; i < input.size() / 2; i++) sum += usedElements[i].value;

	unsigned int lastCheckpoint = 0;
	while (sum % 3 == 0) {
		sum = 0;
		for (int i = lastCheckpoint; i < input.size(); i++) {
			if (usedElements[input[i].index].value != input[i].value) {
				usedElements[input[i].index].value = input[i].value;
				lastCheckpoint = i + 1;
				i = input.size();//To quit for() loop
			}
		}
	}
	
	std::cout << sum;

	reader.close();
}
