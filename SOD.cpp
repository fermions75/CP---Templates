void generateSOD()   // O(NlogN)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j += i)
        {
            SOD[j] += i;
        }
    }
}
