/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

char solve(long long A, long long B) {
  // insert your code here

  return '+';
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int T;
    assert(1 == scanf("%d", &T));

    for (int i=0; i<T; i++) {
        long long A, B;
        assert(2 == scanf("%d%d", &A, &B));
        printf("%c\n", solve(A, B));
    }

    return 0;
}
