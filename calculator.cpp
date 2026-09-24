#include <iostream>

class Calculator {

public:
  int num1;
  int num2;
  int opc;
  int result;
  Calculator(int o, int a, int b) {
    opc = o;
    num1 = a;
    num2 = b;
  };
  void calculate() {
    switch (opc) {
    case 1:
      result = num1 + num2;
      std::cout << "El resultado de la suma es:" << result << std::endl;
      break;
    case 2:
      result = num1 - num2;
      std::cout << "El resultado de la resta es:" << result << std::endl;
      break;
    case 3:
      result = num1 * num2;
      std::cout << "El resultado de la multiplicación es:" << result
                << std::endl;
      break;
    case 4:
      result = num1 / num2;
      std::cout << "El resultado de la division es:" << result << std::endl;
      break;
    }
  };
};

int main() {

  Calculator c(1, 20, 50), c1(2, 20, 5), c2(3, 10, 30), c3(4, 100, 20);
  c.calculate();
  c1.calculate();
  c2.calculate();
  c3.calculate();

  return 0;
}
