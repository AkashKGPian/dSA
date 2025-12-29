#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is a palindrome
bool is_palindrome(int a) {
    string s = to_string(a);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// Function to generate prime numbers up to max_n using Sieve of Eratosthenes
vector<bool> generate_primes(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    // Generate primes up to b
    vector<bool> is_prime = generate_primes(b);

    // Precompute count of palindromic primes up to i
    vector<int> palin_prime_count(b + 1, 0);
    for (int i = 2; i <= b; i++) {
        palin_prime_count[i] = palin_prime_count[i - 1];
        if (is_prime[i] && is_palindrome(i)) {
            palin_prime_count[i]++;
        }
    }

    // Final result: number of palindromic primes in [a, b]
    int result = palin_prime_count[b] - (a > 1 ? palin_prime_count[a - 1] : 0);
    cout << result << '\n';

    return 0;
}

