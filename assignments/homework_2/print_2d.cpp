// Given
int k = 0;
for (int i = 0; i < 15; i++)
{   for( int j = 0; j < 15; j++)
    { Nums[i][j] = k;
      k++;
    }
}

// Answer
for (int i = 0; i < 15; i++)
{   for ( int j = 0; j < 15; j++)
    { cout << Nums[j][i] << " ";
    }
    cout << '\n';
}
