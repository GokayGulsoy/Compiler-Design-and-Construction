int is_prime(int n) {
    // Handle special cases for small integers
    if (n <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }

    // Check for divisibility by numbers from 2 to n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // n is divisible by i, hence not a prime number
        }
    }

    return 1; // n is a prime number
}
