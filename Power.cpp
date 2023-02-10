ll pow(long base, long exp)   // O(log(exp))
{
    if(exp == 0) return 1;
    if(exp % 2 == 1)
    {
        return base * pow(base, exp - 1);
    }
    else
    {
        long half = pow(base, exp / 2);
        return half * half;
    }
}


ll pow(long base, long exp)   // base ^ exp // O(exp)--> Order of exp
{
    long res = 1;
    for(long i = 1; i <= exp; i++)
    {
        res *= base;
    }
    return res;
}
