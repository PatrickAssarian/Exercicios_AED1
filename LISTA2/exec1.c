/*
a)
int soma = 0;
for (int i=0; i<n; i++) {
    soma += i;
}
printf("%d", soma);

Equação T(n): T(n) = c1 + c2*n + c3
Notação O: O(n)


b)
for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
        printf("%d %d\n", i, j);
    }
}

Equação T(n): T(n) = c1 * n * n = c1*n^2
Notação O: O(n^2)


c)
for (int i=0; i<n; i++) {
    for (int j=0; j<10; j++) {
        printf("%d\n", i*j);
    }
}

Equação T(n): T(n) = c1 * n * 10 = 10*c1*n
Notação O: O(n)


d)
int i=n;
while (i>1) {
    i=i/2;
}
printf("%d\n", i);

Equação T(n): T(n) = c1 + c2*log2(n) + c3
Notação O: O(log n)


e)
for (int i=0; i<n; i++) {
    printf("%d\n", i);
}
for (int j=0; j<n; j++) {
    for (int k=0; k<n; k++) {
        printf("%d %d\n", j, k);
    }
}

Equação T(n): T(n) = c1*n + c2*(n * n) = c1*n + c2*n^2
Notação O: O(n^2)
*/
