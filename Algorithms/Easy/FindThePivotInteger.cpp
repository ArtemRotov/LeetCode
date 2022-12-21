int pivotInteger(int n)
{
    /*
    sum 1..n = n*(n+1)/2
    sum 1..x = x*(x+1)/2
    sum x..n = n*(n+1)/2 - x*(x+1)/2 + x

    >   x*(x+1)/2 = n*(n+1)/2 - x*(x+1)/2 + x
    >   n*(n+1)/2 = x*(x+1)/2 + x*(x+1)/2 - x
    >   n*(n+1)/2 = x^2
    >   x = sqrt(n*(n+1)/2)
    */

    int sum = n*(n+1)/2;
    int x = sqrt(sum);

    return (x*x == sum) ? x : -1;
}
