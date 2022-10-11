#include <stdio.h>
#include <stdlib.h>
int W, n;
int main()
{
     int w, i, l = 0, p, j;
     printf("Enter number of objects \n");
     scanf("%d", &n);
     printf("Enter maximum weight, knapsack can carry \n");
     scanf("%d", &W);
     int k[n + 1][W + 1], a[W], v[W], ks[W];
     printf("Enter weights of objects \n");
     a[0] = 0;
     for (i = 1; i < n + 1; i++)
     {
          printf("w[%d] = ", i);
          scanf("%d", &a[i]);
     }
     printf("Enter profits/values of objects \n");
     v[0] = 0;
     for (i = 1; i < n + 1; i++)
     {
          printf("p[%d] = ", i);
          scanf("%d", &v[i]);
     }
     k[0][0] = 0;
     for (w = 1; w <= W; w++)
          k[0][w] = 0;
     for (i = 1; i <= n + 1; i++)
          k[i][0] = 0;
     for (i = 1; i <= n; i++)
     {
          for (w = 1; w <= W; w++)
          {
               if (a[i] <= w)
               {
                    if (v[i] + k[i - 1][w - a[i]] > k[i - 1][w])
                    {
                         k[i][w] = v[i] + k[i - 1][w - a[i]];
                    }
                    else
                    {
                         k[i][w] = k[i - 1][w];
                    }
               }
               else
               {
                    k[i][w] = k[i - 1][w];
               }
          }
     }
     printf("\n\nP  W  i     \t0  ");
     for (i = 1; i <= W; i++)
     {
          printf("%d  ", i);
     }
     printf("\n_________________________________________________________\n");
     for (i = 0; i < n + 1; i++)
     {
          printf("%d  %d  %d |\t", v[i], a[i], i);
          for (j = 0; j <= W; j++)
          {
               printf("%d  ", k[i][j]);
          }
          printf("\n");
     }
     i = n;
     p = W;
     int u = 0, x = 0;
     while (i >= 0 && p >= 0)
     {
          if (k[i][W] != k[i - 1][W])
          {
               ks[++l] = i;
               p = p - a[i];
               u = u + i;
               x += v[i];
               i = i - 1;
          }
          else
               i = i - 1;
     }

     ks[++l] = '\0';
     l = 1;
     printf("\nThe individual weights are   ");
     while (ks[l] != '\0')
     {
          printf("%d    ", ks[l]);
          l++;
     }
     printf("\n\nTotal weight to be carried in knapsack is  %d \n\n", u);
     printf("Total profit in knapsack is  %d \n\n", x);
}
