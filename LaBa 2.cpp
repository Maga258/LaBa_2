#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


// Проверка на прростое число 
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}


// Проверка на степень двойки
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}


int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "rus");
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }

    // Ввод последовательности чисел 
    int number;
    if(isHuman) cout << "Введите последовательность чисел N: ";
    cin >> number;

    while (number <= 0) {
        if(isHuman) cout << "Вы ввели число меньше или равное нулю. Пожалуйста введите снова: ";
        cin >> number;
    }

    if (isHuman) cout << "Введите " << number << " чисел: " << endl;

    int min = INT_MAX; // минимальное число 
    int max = INT_MIN; // максимальное число 
    int amoutprimecount = 0; // сумма количество простых чисел
    int countDivBy5 = 0; // количество чисел кратных 5
    int st2num = 0; // степень двойки
    int primeCount = 0; // количество простых чисел
    int primemin = INT_MAX; // простое минимальное число 
    int primemax = INT_MIN; // простое макимальное число 
    int countExceedingSum = 0; // счетчик 
    int prev1 = 0;  // Последние числа
    int prev2 = 0; // Последние числа
    int sum = 0;

    // Вывод простое ли число или нет 
    for (int i = 0; i < number; i++) {
        int num;
        cin >> num;
        sum += num;

        // Проверка на простоту 
        if (isPrime(num)) {
            cout << num;
            if (isHuman) cout << " - Простое";
            cout << endl;
            amoutprimecount += num;
            primeCount++;
            if (num < primemin) primemin = num;
            if (num > primemax) primemax = num;
        }
        

        if (i >= 2 && num > prev1 + prev2) {
            countExceedingSum++;

        }
        
        prev2 = prev1;
        prev1 = num;
        if (isPowerOfTwo(num)) {
            st2num++;

        }
        // Обновление максимума и минимума 
        if (num > max) max = num;
        if (num < min) min = num;

        if (num % 5 == 0) countDivBy5++;
    }
    // Плоды работы моей программы 
    if (isHuman) cout << "Среднее арифметическое: "; 
    cout << fixed << setprecision(2) << static_cast<float>(sum) / number << endl;
    if (isHuman) cout << "Разница между макс и мин: ";
    cout << max - min << endl;
    if (isHuman) cout << "Количество чисел кратных 5: " 
    cout << countDivBy5 << endl;
    if (isHuman) cout << "Количество чисел, являющихся степенью двойки: ";
    cout << st2num << endl;
    if (isHuman) cout << "Количество чисел, превышающих сумму двух предшествующих: ";
    cout << countExceedingSum << endl;
    
    return 0;
}


