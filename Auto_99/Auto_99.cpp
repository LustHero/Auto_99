#include <iostream>

using namespace std;


bool _Prov_(int* chislComp, int chisl) {
	for (int i = 0; i < 4; i++){ if (chislComp[i] == chisl) { return false; } }
	return true;
}


int Prov(int* chislComp, int index) {
	int buff = rand() % 9 + 0;
	if (_Prov_(chislComp, buff))
	{
		return buff;
	}
	else
	{
		return Prov(chislComp, index);
	}
}


char _Per_(int* chislComp, int* chislPlay, int index) {
	if (chislComp[index] == chislPlay[index]) { return '+'; }
	else if (!_Prov_(chislComp, chislPlay[index])) { return '-'; }
}

int Per(int* chislComp, int* chislPlay) {
	int schet_plus = 0, schet_min = 0;
	for (int index = 0; index < 4; index++) {
		if (_Per_(chislComp, chislPlay, index) == '+') { schet_plus++; }
		else if (_Per_(chislComp, chislPlay, index) == '-') { schet_min++; }
	}
	cout << "+:  " << schet_plus << " | -:  " << schet_min << endl;
	return schet_plus;
}


int main() {
	setlocale(LC_ALL, "Rus");
	string vvod, result;
	int chislComp[4], chislPlay[4];
	srand(time(NULL));

	for (int index = 0; index < 4; index++) { chislComp[index] = Prov(chislComp, index);}

	do {
		cout << "Введите строку из четырёх чисел:  "; cin >> vvod;
		for (int index = 0; index < 4; index++) {chislPlay[index] = vvod[index] - 48;}
	} while (Per(chislComp, chislPlay) != 4);
}