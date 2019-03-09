#include<stdio.h>
void
sort (int val[], int bid[], int l)	//Bubble sort
{
  int c, d, swap, swap1;
  for (c = 0; c < l - 1; c++)
    {
      for (d = 0; d < l - c - 1; d++)
	{
	  if (val[d] < val[d + 1])
	    {
	      swap = val[d];
	      val[d] = val[d + 1];
	      val[d + 1] = swap;

	      swap1 = bid[d];
	      bid[d] = bid[d + 1];
	      bid[d + 1] = swap1;
	    }
	}
    }
}

void
main ()
{
  int n, k, i, j, l, x = 0;
  FILE *fp;
  printf ("Enter the number of items\n");	// Get the input
  scanf ("%d", &k);
  printf ("Enter the number of bidders\n");
  scanf ("%d", &n);
  int mat[n][k];
  int val[k * n], bid[n * k];
  fp = fopen ("textFile.txt", "r");	//A file with numbers only
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < k; j++)
	{
	  fscanf (fp, "%d", &mat[i][j]);	// Read the file
	}
    }
  l = n * k;
  printf ("\n");
  for (int i = 0; i < n; i++)	// Make the Matrix
    {
      for (int j = 0; j < k; j++)
	{
	  printf ("%d   ", mat[i][j]);
	  val[x] = mat[i][j];
	  bid[x] = i;
	  x++;
	}
      printf ("\n");
    }
  printf ("\n----------------------\n");	// Convert Matrix to Vector
  printf ("Bids\t|Bidder Number\n");
  printf ("----------------------\n");
  for (i = 0; i < k * n; i++)
    printf ("%d\t|\t%d\n", val[i], bid[i]);

  printf ("\nAfter sorting \n\n");
  sort (val, bid, l);		//Bubble sort Vector
  printf ("----------------------\n");	// Print Sorted Vector
  printf ("Bids\t|Bidder Number\n");
  printf ("----------------------\n");
  for (i = 0; i < k * n; i++)
    {
      if (i == k)
	printf ("______________________\n");
      printf ("%d\t|\t%d\n", val[i], bid[i]);
    }

  int revenue[k], snn = 0, sn = 0, mm = k, winner[k];	//Calculate the revenue
  while (sn < k)
    {
      while (snn != -1)
	{
	  snn--;
	  if (bid[sn] == bid[snn])
	    {
	      mm++;
	      break;
	    }
	}
      while (bid[sn] == bid[mm])
	{
	  mm++;
	}
      revenue[sn] = val[mm];
      winner[sn] = bid[sn];
      sn++;
      snn = sn;
      mm = k;
    }
  printf ("\n----------------------\n");	//Print Revenue with Bidder Number
  printf ("Revenue\t|Bidder Number\n");
  printf ("----------------------\n");
  for (i = 0; i < k; i++)
    printf ("%d\t|\t%d\n", revenue[i], winner[i]);
  int sum = 0;
  printf ("----------------------\n");	// Calculate and print the Total Revenue
  printf ("Total Revenue\n");
  printf ("----------------------\n");
  for (i = 0; i < k; i++)
    {
      sum += revenue[i];
    }
  printf ("\t%d\n", sum);

  fclose (fp);
}
