#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

class ScientificCalculator {
private:
    double memory = 0.0;
    
public:
    // Display menu
    void displayMenu() {
        std::cout << "\n========== SCIENTIFIC CALCULATOR ==========\n";
        std::cout << "1.  Addition (+)\n";
        std::cout << "2.  Subtraction (-)\n";
        std::cout << "3.  Multiplication (*)\n";
        std::cout << "4.  Division (/)\n";
        std::cout << "5.  Power (x^y)\n";
        std::cout << "6.  Square Root (√x)\n";
        std::cout << "7.  Cube Root (∛x)\n";
        std::cout << "8.  Sine (sin)\n";
        std::cout << "9.  Cosine (cos)\n";
        std::cout << "10. Tangent (tan)\n";
        std::cout << "11. Arc Sine (asin)\n";
        std::cout << "12. Arc Cosine (acos)\n";
        std::cout << "13. Arc Tangent (atan)\n";
        std::cout << "14. Natural Logarithm (ln)\n";
        std::cout << "15. Base-10 Logarithm (log)\n";
        std::cout << "16. Exponential (e^x)\n";
        std::cout << "17. Factorial (n!)\n";
        std::cout << "18. Absolute Value (|x|)\n";
        std::cout << "19. Memory Store (MS)\n";
        std::cout << "20. Memory Recall (MR)\n";
        std::cout << "21. Memory Clear (MC)\n";
        std::cout << "22. Convert Degrees to Radians\n";
        std::cout << "23. Convert Radians to Degrees\n";
        std::cout << "0.  Exit\n";
        std::cout << "==========================================\n";
        std::cout << "Memory: " << memory << std::endl;
        std::cout << "Choose operation: ";
    }
    
    // Basic arithmetic operations
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) {
            throw std::runtime_error("Error: Division by zero!");
        }
        return a / b;
    }
    
    // Advanced operations
    double power(double base, double exp) { return std::pow(base, exp); }
    double squareRoot(double x) {
        if (x < 0) {
            throw std::runtime_error("Error: Square root of negative number!");
        }
        return std::sqrt(x);
    }
    double cubeRoot(double x) { return std::cbrt(x); }
    
    // Trigonometric functions (input in radians)
    double sine(double x) { return std::sin(x); }
    double cosine(double x) { return std::cos(x); }
    double tangent(double x) { return std::tan(x); }
    double arcSine(double x) {
        if (x < -1 || x > 1) {
            throw std::runtime_error("Error: asin domain error! Input must be between -1 and 1");
        }
        return std::asin(x);
    }
    double arcCosine(double x) {
        if (x < -1 || x > 1) {
            throw std::runtime_error("Error: acos domain error! Input must be between -1 and 1");
        }
        return std::acos(x);
    }
    double arcTangent(double x) { return std::atan(x); }
    
    // Logarithmic functions
    double naturalLog(double x) {
        if (x <= 0) {
            throw std::runtime_error("Error: Logarithm of non-positive number!");
        }
        return std::log(x);
    }
    double log10(double x) {
        if (x <= 0) {
            throw std::runtime_error("Error: Logarithm of non-positive number!");
        }
        return std::log10(x);
    }
    double exponential(double x) { return std::exp(x); }
    
    // Factorial function
    long long factorial(int n) {
        if (n < 0) {
            throw std::runtime_error("Error: Factorial of negative number!");
        }
        if (n > 20) {
            throw std::runtime_error("Error: Factorial too large (overflow)!");
        }
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    
    // Other functions
    double absoluteValue(double x) { return std::abs(x); }
    double degreesToRadians(double degrees) { return degrees * M_PI / 180.0; }
    double radiansToDegrees(double radians) { return radians * 180.0 / M_PI; }
    
    // Memory functions
    void memoryStore(double value) { memory = value; }
    double memoryRecall() { return memory; }
    void memoryClear() { memory = 0.0; }
    
    // Get input from user
    double getInput(const std::string& prompt) {
        double value;
        std::cout << prompt;
        while (!(std::cin >> value)) {
            std::cout << "Invalid input! Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        return value;
    }
    
    // Main calculator loop
    void run() {
        int choice;
        double num1, num2, result;
        
        std::cout << std::fixed << std::setprecision(6);
        
        while (true) {
            displayMenu();
            std::cin >> choice;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            
            try {
                switch (choice) {
                    case 0:
                        std::cout << "Thank you for using Scientific Calculator!\n";
                        return;
                        
                    case 1: // Addition
                        num1 = getInput("Enter first number: ");
                        num2 = getInput("Enter second number: ");
                        result = add(num1, num2);
                        std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
                        break;
                        
                    case 2: // Subtraction
                        num1 = getInput("Enter first number: ");
                        num2 = getInput("Enter second number: ");
                        result = subtract(num1, num2);
                        std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
                        break;
                        
                    case 3: // Multiplication
                        num1 = getInput("Enter first number: ");
                        num2 = getInput("Enter second number: ");
                        result = multiply(num1, num2);
                        std::cout << "Result: " << num1 << " × " << num2 << " = " << result << std::endl;
                        break;
                        
                    case 4: // Division
                        num1 = getInput("Enter dividend: ");
                        num2 = getInput("Enter divisor: ");
                        result = divide(num1, num2);
                        std::cout << "Result: " << num1 << " ÷ " << num2 << " = " << result << std::endl;
                        break;
                        
                    case 5: // Power
                        num1 = getInput("Enter base: ");
                        num2 = getInput("Enter exponent: ");
                        result = power(num1, num2);
                        std::cout << "Result: " << num1 << "^" << num2 << " = " << result << std::endl;
                        break;
                        
                    case 6: // Square Root
                        num1 = getInput("Enter number: ");
                        result = squareRoot(num1);
                        std::cout << "Result: √" << num1 << " = " << result << std::endl;
                        break;
                        
                    case 7: // Cube Root
                        num1 = getInput("Enter number: ");
                        result = cubeRoot(num1);
                        std::cout << "Result: ∛" << num1 << " = " << result << std::endl;
                        break;
                        
                    case 8: // Sine
                        num1 = getInput("Enter angle in radians: ");
                        result = sine(num1);
                        std::cout << "Result: sin(" << num1 << ") = " << result << std::endl;
                        break;
                        
                    case 9: // Cosine
                        num1 = getInput("Enter angle in radians: ");
                        result = cosine(num1);
                        std::cout << "Result: cos(" << num1 << ") = " << result << std::endl;
                        break;
                        
                    case 10: // Tangent
                        num1 = getInput("Enter angle in radians: ");
                        result = tangent(num1);
                        std::cout << "Result: tan(" << num1 << ") = " << result << std::endl;
                        break;
                        
                    case 11: // Arc Sine
                        num1 = getInput("Enter value (-1 to 1): ");
                        result = arcSine(num1);
                        std::cout << "Result: asin(" << num1 << ") = " << result << " radians" << std::endl;
                        break;
                        
                    case 12: // Arc Cosine
                        num1 = getInput("Enter value (-1 to 1): ");
                        result = arcCosine(num1);
                        std::cout << "Result: acos(" << num1 << ") = " << result << " radians" << std::endl;
                        break;
                        
                    case 13: // Arc Tangent
                        num1 = getInput("Enter value: ");
                        result = arcTangent(num1);
                        std::cout << "Result: atan(" << num1 << ") = " << result << " radians" << std::endl;
                        break;
                        
                    case 14: // Natural Logarithm
                        num1 = getInput("Enter positive number: ");
                        result = naturalLog(num1);
                        std::cout << "Result: ln(" << num1 << ") = " << result << std::endl;
                        break;
                        
                    case 15: // Base-10 Logarithm
                        num1 = getInput("Enter positive number: ");
                        result = log10(num1);
                        std::cout << "Result: log₁₀(" << num1 << ") = " << result << std::endl;
                        break;
                        
                    case 16: // Exponential
                        num1 = getInput("Enter exponent: ");
                        result = exponential(num1);
                        std::cout << "Result: e^" << num1 << " = " << result << std::endl;
                        break;
                        
                    case 17: // Factorial
                        {
                            int n = static_cast<int>(getInput("Enter non-negative integer: "));
                            long long factResult = factorial(n);
                            std::cout << "Result: " << n << "! = " << factResult << std::endl;
                        }
                        break;
                        
                    case 18: // Absolute Value
                        num1 = getInput("Enter number: ");
                        result = absoluteValue(num1);
                        std::cout << "Result: |" << num1 << "| = " << result << std::endl;
                        break;
                        
                    case 19: // Memory Store
                        num1 = getInput("Enter value to store: ");
                        memoryStore(num1);
                        std::cout << "Value " << num1 << " stored in memory." << std::endl;
                        break;
                        
                    case 20: // Memory Recall
                        std::cout << "Memory value: " << memoryRecall() << std::endl;
                        break;
                        
                    case 21: // Memory Clear
                        memoryClear();
                        std::cout << "Memory cleared." << std::endl;
                        break;
                        
                    case 22: // Degrees to Radians
                        num1 = getInput("Enter angle in degrees: ");
                        result = degreesToRadians(num1);
                        std::cout << "Result: " << num1 << "° = " << result << " radians" << std::endl;
                        break;
                        
                    case 23: // Radians to Degrees
                        num1 = getInput("Enter angle in radians: ");
                        result = radiansToDegrees(num1);
                        std::cout << "Result: " << num1 << " radians = " << result << "°" << std::endl;
                        break;
                        
                    default:
                        std::cout << "Invalid choice! Please select 0-23." << std::endl;
                        break;
                }
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    }
};

int main() {
    ScientificCalculator calculator;
    calculator.run();
    return 0;
}