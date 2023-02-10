void primeFactorize(int n)   // generate all primes till sqrt(n). So, N = sqrt(n) + 1
{
    int idx = 0;
    for(int i = 0; i < x; i++)   // x = length of primes array
    {
        int p = primes[i];
        if((long) p * p > n)   // p > sqrt(n)
        {
            break;
        }
        if(n % p == 0)
        {
            int occ = 0;
            while(n % p == 0)
            {
                n /= p;
                occ++;
            }
            primeFactors[idx] = p;
            occurrences[idx] = occ;
            idx++;
        }
    }
    if(n > 1)
    {
        primeFactors[idx] = n;
        occurrences[idx] = 1;
        idx++;
    }
}
