# Kinga Molik C++ 
***
## Kod
```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h> 

using namespace std;

double c, eps;
 
void F(vector<double> vec)
{
	int F = vec.size();
	switch(F)
	{
	case 1:
		cout << "punkt: " << vec[0] <<endl<< "wartość: " << pow(vec[0], 4) - 4 * pow(vec[0], 2) + 4 << endl;
		break;
	case 2:
		cout << "punkty: " << vec[0] << ", " << vec[1] <<endl<< "wartość: " << 3 * pow(vec[0], 4) + 4 * pow(vec[0], 3) - 12 * pow(vec[0], 2) + 12 * pow(vec[1], 2) - 24 * vec[1] << endl;
		break;
	case 3:
		cout << "punkty: " << vec[0] <<", " << vec[1] << ", "<< vec[2] <<endl<< "wartość: " << 2 * pow(vec[0], 2) + 2 * pow(vec[1], 2) + pow(vec[2], 2) - 2 * vec[0] * vec[1] - 2 * vec[1] * vec[2] - 2 * vec[0] + 3<<endl;
		break;
	}
}


double Derivative(vector<double> vec, int x)
{
	int F = vec.size();
	switch (F)
	{
	case(1):
		return 4 * pow(vec[0], 3) - 8 * vec[0];

	case(2):
		switch (x)
		{
		case 1:
			return 12 * vec[0] * (pow(vec[0], 2) + vec[0] - 2);
		case 2:
			return 24 * (vec[1] - 1);
		}

	case(3):
		switch (x)
		{
		case 1:
			return 4 * vec[0] - 2 * (vec[1] + 1);
		case 2:
			return -2 * (vec[0] - 2 * vec[1] + vec[2]);
		case 3:
			return 2 * vec[2] - 2 * vec[1];
		}
	}
}

vector<double> createVectorNew(int n, vector<double> input)
{	
	vector<double> vectorNew;

	for (int i = 0; i < n; i++) {
		vectorNew.push_back(0.0);
	}

	for (int i = 0; i < n; i++) {
		vectorNew[i] = input[i] - c * Derivative(input, i + 1);
	}

	return vectorNew;
}

vector<double> gradientMethod(vector<double> input) {
	vector<double> vectorNew;
	double max;
	int n = input.size();
	int it = 0;

	while (true) {
		it = it + 1;
		vectorNew = createVectorNew(n, input);
		max = 0.0;
		for (int i = 0; i < n; i++) {

			if (fabs(vectorNew[i] - input[i]) > max) {
				max = fabs(vectorNew[i] - input[i]);
			}			
		}
		if (max < eps) {
			cout << "iteracje: " << it<<endl;
			return vectorNew;
		}
		input = vectorNew;

	}
}

int main(int argc, char** argv) {

	srand(time(NULL));
	vector<double> vector1, vector2, vector3, vecNew;
	c = 0.1;
	eps = 0.0000001;
	
	cout << "(i) Dowolnie wybrany wektor poczatkowy." << endl;

	//F1
	vector1.push_back(-1.0);
	vecNew = gradientMethod(vector1);
	F(vecNew);
	vector1.clear();
	vecNew.clear();
	cout << endl << endl;	

	//F2
	vector2.push_back(1.0);
	vector2.push_back(1.0);
	vecNew = gradientMethod(vector2);
	F(vecNew);
	vector2.clear();
	vecNew.clear();
	cout << endl << endl;

	//F3
	vector3.push_back(1.0);
	vector3.push_back(1.0);
	vector3.push_back(1.0);
	vecNew = gradientMethod(vector3);
	F(vecNew);
	vector3.clear();
	vecNew.clear();
	cout << endl << endl;

	cout << "(ii) Losowy wektor poczatkowy." << endl;

	int N = 2;

	//F1
	vector1.push_back((double)(rand() % N) - N);
	vecNew = gradientMethod(vector1);
	F(vecNew);
	vector1.clear();
	vecNew.clear();
	cout << endl << endl;

	//F2
	vector2.push_back((double)(rand() % N) - N);
	vector2.push_back((double)(rand() % N) - N);
	vecNew = gradientMethod(vector2);
	F(vecNew);
	vector2.clear();
	vecNew.clear();
	cout << endl << endl;

	//F3
	vector3.push_back((double)(rand() % N) - N);
	vector3.push_back((double)(rand() % N) - N);
	vector3.push_back((double)(rand() % N) - N);
	vecNew = gradientMethod(vector3);
	F(vecNew);
	vector3.clear();
	vecNew.clear();
	cout << endl << endl;

	return 0;
}

```
***
## ANALIZA

Moją analizę dzielę na poszczególne funkcje podane w zadaniu, ponieważ mogą one różnie zachowywać się względem różnych parametrów c i eps.
Przyjęłam oznaczenie dla funkcji: **F(i)**, gdzie *i* to ilość niewiadomych w fukcji.
***
### 1.	F(1) = x^4 – 4 * x^2 + 4
* c = 0.01	eps = 0.000001
  * dla wektora początkowego [-1.0]:  
    ```
    iteracje: 69
    punkt: -1.4142089
    ```
    Dla [1.0] otrzymamy drugie minimum globalne, czyli 1.41421 (z tą samą iloscią iteracji i wartością)
  * dla wektora początkowego [-2.0]:  
    ```
    iteracje: 64
    punkt: -1.4142181
    ```
***
* c = 0.001	eps = 0.000001
  * dla wektora początkowego [1.0]:  
    ```
    iteracje: 581
    punkt: 1.4141529
    ```
    Widać, że 10-krotne zmniejszenie parametru c spowalnia prace algorytmu.
***
* c = 0.2	eps = 0.000001
  * dla wektora początkowego [0.1]:  
    ```
    iteracje: 512359
    punkt: -5.1197197e-07
    ```
    Przy większej wartości c liczba iteracji jest już liczona w tysiącach, a minimum ma kompletnie inną wartość niż powinno.
***
* c = 0.01	eps = 0.001   
  * dla wektora początkowego [2.0]
    ```
    iteracje: 24
    punkt: -1.4190996
    ```
* c = 0.1	eps = 0.001 
  * dla wektora początkowego [1.0]
    ```
    iteracje: 9
    punkt: 1.4139811
    ```
    Zwiększenie wartości eps zmniejsza dokładność wyszukiwanego minimum, ale zwraca tą wartość szybciej (mniej iteracji).
* c = 0.01 eps = 0.00000001
  * dla wektora początkowego [0.1]
    ```
    iteracje: 129
    punkt: 1.4142135
    ```
    Analogicznie zmniejszenie eps (zwiększenie dokładności) skutkuje dłuższą pracą algorytmu, ale dokładniejszym wynikiem.
*** 

### 2. F(2) = 3 * x^4 + 4 * x^3 - 12 * x^2 + 12 * y^2 - 24 * y
* c = 0.01	eps = 0.000001
  * dla wektora początkowego [1.0, 1.0]:      
    ```
    iteracje: 1
    punkty: 1, 1
    ```
  * dla wektora początkowego [-1.0, 1.0]: 
    ```
    iteracje: 15
    punkty: -1.9999999, 1
    ```
    Widać, że algorytm bardzo szybko znajduje minimum globalne (-2,1) dla funcji F(2) i dla odpowiednich wartości wektora początkowego znajduje również minimum lokalne (1,1).
***
* c = 0.1	eps = 0.000001
  * dla wektora początkowego [-1.0, 1.0]:      
    ```
    iteracje: 8
    punkty: -nan(ind), 1
    ```    
    Przy zwiększeniu parametru c algorytm nie zwraca prawidłowego wyniku.
***
* c = 0.001	eps = 0.000001
  * dla wektora początkowego [-1.0, 1.0]:      
    ```
    iteracje: 169
    punkty: -1.9999872, 1
    ```    
    Przy zmniejszeniu c, zwiększa się kilkukrotnie ilość iteracji.
***
* c = 0.01	eps = 0.001
  * dla wektora początkowego [-1.0, 1.0]:      
    ```
    iteracje: 9
    punkty: -1.9996981, 1
    ```      
    Dla małego eps mamy stosunkowo małą ilosć iteracji i dokładny wynik.
***
### 3. F(3) = 2 * x^2 + 2 * y^2 + z^2 - 2 * x * y - 2 * y * z - 2 * x + 3
* c = 0.01	eps = 0.000001
  * dla wektora początkowego [-1.0, -1.0, -1.0]: 
    ```
    iteracje: 2314
    punkty: 0.99988853, 0.99979914, 0.99974953
    ```
    Algorytm, by znaleźć minimum globalne (1,1,1) potrzebuje wykonać bardo dużo iteracji.
***
* c = 0.001	eps = 0.000001
  * dla wektora początkowego [-0.1 -0.1 -0.1]: 
      ```      
      iteracje: 15842
      punkty: 0.99887698, 0.99797639, 0.99747661
    ```
    Przy małym c, uzyskujemy mniej dokładne wyniki oraz algorytm wykonuje bardzo dużo iteracji.
***
* c = 0.3	eps = 0.000001
  * dla wektora początkowego [-1.0, 1.0, 1.0]: 
    ```
    iteracje: 271
    punkty: 1.0000004, 0.99999952, 1.0000002
    ```
    Najmniej iteracji i największą preyzję mamy dla stosunkowo dużego c.
***
* c = 0.3	eps = 0.00000001
  * dla wektora początkowego [-1.0, -1.0, -1.0]: 
    ```
    iteracje: 336
    punkty: 1, 1, 1
    ```
    Najbardziej precyzyjny wynik otrzymujemy dla dużego c i małego eps.




    
