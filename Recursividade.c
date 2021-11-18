#include <stdio.h>
#include <string.h>

#define swap( _a, _b ) do{ int _tmp = _a; _a = _b; _b = _tmp; } while(0)

void quicksort( int array[], int start, int end )
{
    if( start < end )
    {
        int l = start + 1;
        int r = end;
        int p = array[start];

        while( l < r )
        {
            if( array[l] <= p )
            {
                l++;
            }
            else if( array[r] >= p )
            {
                r--;
            }
            else
            {
                swap( array[l], array[r] );
            }
        }

        if( array[l] < p )
        {
            swap( array[l], array[start] );
            l--;
        }
        else
        {
            l--;
            swap( array[l], array[start] );
        }

        quicksort( array, start, l );
        quicksort( array, r, end );
    }
}

void exibir( int array[], int tam )
{
    int i = 0;

    for( i = 0; i < tam; i++ )
        printf( "%s%d", (i>0)?", ":"", array[i] );

    printf("\n");
}


int main( int argc, char * argv[] )
{
    int numeros[10] = {7, 3, -1, 8,  2, 1, -3,  9, -8, 0 };

    printf("Array Original: ");
    exibir( numeros, 10 );

    quicksort( numeros, 0, 10 );

    printf("Array Ordenada: ");
    exibir( numeros, 10 );

    return 0;
}