#include "Vector.h";

int main() {

	Vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	if (vec.empty())
		vec.push_back(4);

	for (size_t i = 0; i < vec.getSize(); i++) {
		cout << vec[i];
	}
	cout << endl;

	Vector<int> vec2;

	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);

	vec2 = vec;

	for (size_t i = 0; i < vec2.getSize(); i++) {
		cout << vec2[i];
	}
	cout << endl;

	Vector<int> vec3(vec2);

	for (Vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}