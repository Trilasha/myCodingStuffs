BigInt first("12345");
    cout << "The number of digits"
         << " in first big integer = "
         << Length(first) << '\n';
    BigInt second(12345);
    if (first == second) {
        cout << "first and second are equal!\n";
    }
    else
        cout << "Not equal!\n";
    BigInt third("10000");
    BigInt fourth("100000");
    if (third < fourth) {
        cout << "third is smaller than fourth!\n";
    }
    BigInt fifth("10000000");
    if (fifth > fourth) {
        cout << "fifth is larger than fourth!\n";
    }
 
    // Printing all the numbers
    cout << "first = " << first << '\n';
    cout << "second = " << second << '\n';
    cout << "third = " << third << '\n';
    cout << "fourth = " << fourth<< '\n';
    cout << "fifth = " << fifth<< '\n';
 
    // Incrementing the value of first
    first++;
    cout << "After incrementing the"
         << " value of first is : ";
    cout << first << '\n';
    BigInt sum;
    sum = (fourth + fifth);
    cout << "Sum of fourth and fifth = "
         << sum << '\n';
    BigInt product;
    product = second * third;
    cout << "Product of second and third = "
         << product << '\n';
 
    // Print the fibonaccii number from 1 to 100
    cout << "-------------------------Fibonacci"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt Fib;
        Fib = NthFibonacci(i);
        cout << "Fibonacci " << i << " = " << Fib<<'\n';
    }
    cout << "-------------------------Catalan"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt Cat;
        Cat = NthCatalan(i);
        cout << "Catalan " << i << " = " << Cat<<'\n';
    }
 
    // Calculating factorial of from 1 to 100
    cout << "-------------------------Factorial"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt fact;
        fact = Factorial(i);
        cout << "Factorial of "
             << i << " = ";
        cout << fact << '\n';
    }
  // This code is contributed
  // by Gatea David
}