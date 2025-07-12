#include <iostream>
// #include"my_math/addition.h" // Disabled: header not available
// #include"my_math/division.h" // Disabled: header not available

int main() {

    float first_no, second_no, result_add, result_div;
    std::cout << "Enter 2 numbers\n";
    std::cin >> first_no >> second_no;
    // result_add = addition(first_no, second_no);  // Disabled: function not available
    // result_div = division(first_no, second_no);  // Disabled: function not available

    // Use dummy values for demonstration
    result_add = first_no + second_no;
    result_div = (second_no != 0) ? first_no / second_no : 0;

    std::cout << "Addition result:\t" << result_add << "\n"
              << "Division result:\t" << result_div << "\n";

    return 0;
}
