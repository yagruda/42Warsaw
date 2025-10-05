#include <stdio.h>
#include <stdlib.h>

int ft_abs(int x)
{
    return (x < 0 ? -x : x);
}

int is_safe(int *b, int c, int r)
{
    for (int i = 0; i < c; i++)
        if (b[i] == r || ft_abs(b[i] - r) == ft_abs(i - c))
            return (0);
    return (1);
}

void solve(int *b, int n, int c)
{
    if (c == n)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(stdout, "%d", b[i]);
            if (i < n - 1) fprintf(stdout, " ");
        }
        fprintf(stdout, "\n");
        return;
    }
    for (int r = 0; r < n; r++)
        if (is_safe(b, c, r))
        {
            b[c] = r;
            solve(b, n, c + 1);
        }
}

int main(int ac, char **av)
{
    if (ac != 2) return (0);
    int n = atoi(av[1]);
    if (n <= 0) return (0);
    int *b = malloc(sizeof(int) * n);
    if (!b) return (1);
    solve(b, n, 0);
    free(b);
    return (0);
}
