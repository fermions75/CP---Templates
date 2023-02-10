bool isEqual(double a, double b)
{
    return abs(a - b) <= EPS;
}

bool isGreater(double a, double b)   // is a greater than b
{
    return a > (b + EPS);
}

bool isSmaller(double a, double b)   // is a smaller than b
{
    //return isGreater(b, a);
    return (a + EPS) < b;
}
