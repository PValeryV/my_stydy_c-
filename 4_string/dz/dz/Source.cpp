#include<iostream>

//14.� ������� ����� ����� ����� ���������� ���������, ������� ������� �� �������� ����� ��� �������

void newMas(int n, int* prt_mas);		// ��������� ���������� ���������� ������������ ������
int findKolElement(int findN, const int* arr, int size); // ������� ���������� ���������, ������� ������� �� �������� ����� ��� �������

int main() {
	setlocale(LC_ALL, "Russian");

	const int SIZE_ARR = 7;

	int sizeDinamicArr = 0;
	int findN = 0;

	std::cout << "������� ���������� ��������� � ������������ ������� - ";
	std::cin >> sizeDinamicArr;

	int* ptr_mas = new int[sizeDinamicArr];
	newMas(sizeDinamicArr, ptr_mas);
	int arr1[SIZE_ARR] = { 20,13,14,15,16,17,18 };
	int arr2[SIZE_ARR] = { 14,15,11,12,31,72,91 };
	int arr3[SIZE_ARR] = { 63,82,34,52,41,63,80 };

	std::cout << "������� ������ ��� ������ ���������� �������� � ������� ��������� �� ���� ��� �������: ";
	std::cin >> findN;

	std::cout << "dinamic arr - " << findKolElement(findN, ptr_mas, sizeDinamicArr) << "\n";
	std::cout << "arr1 - " << findKolElement(findN, arr1, SIZE_ARR) << "\n";
	std::cout << "arr2 - " << findKolElement(findN, arr2, SIZE_ARR) << "\n";
	std::cout << "arr3 - " << findKolElement(findN, arr3, SIZE_ARR) << "\n";
	delete[] ptr_mas;
	return 0;
}

void newMas(int size, int* ptr_mas) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		ptr_mas[i] = 10 + rand() % 20;
	}

	std::cout << "�������� ������������� �������";
	for (int i = 0; i < size; i++) {
		std::cout << ptr_mas[i] << " ";
	}
	std::cout << "\n";
}
int findKolElement(int findN, const int* arr, int size) {
	int i = 0;
	int result = 0;
	while (i < size) {
		if (arr[i] % findN == 0) {
			result += 1;
		}
		i++;
	}
	return result;
}