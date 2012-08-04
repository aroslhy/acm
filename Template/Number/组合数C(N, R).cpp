int com(int n, int r)
{// return C(n, r)
    if (n-r > r) r = n-r; // C(n, r) = C(n, n-r)
    int s = 1;
    for (int i = 0, j = 1; i < r; i++)
    {
        s *= (n-i);
        for(; j <= r && s%j == 0; j++)
            s /= j;
    }
    return s;
}
