void generateNOD()   // O(NlogN)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j += i)
        {
            NOD[j] += 1;
        }
    }
}
