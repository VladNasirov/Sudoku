#include "Tablet.h"
#include <iostream>
grid::grid()
{
   collumn=new int[9];

   row=new int[9];

   area=new int*[3];
   for(int i = 0; i < 3; i++)
   {
           area[i] = new int[3];
   }

   cells=new int*[9];
   for(int i = 0; i < 9; i++)
   {
           cells[i] = new int[9];
   }

   for(int i=0; i<9; i++)
   {
      for(int j=0; j<9; j++)
      {
         cells[i][j]=j+1;
      }
   }
   for(int i=0;i<9;i++)
   {
       if(i<3)
       {
           row_shift(i, i*3);
       }
       if(i>=3&&i<6)
       {
           {
               row_shift(i, 1);
               row_shift(i, i*3);
           }
       }
       if(i>=6)
       {
           {
               row_shift(i, 2);
               row_shift(i, i*3);
           }
       }
   }
   Print();
}

grid::~grid()
{
   for (int i = 0; i < 3; i++)
   {
       delete [] area[i];
   }
   delete [] area;

   for (int i = 0; i < 9; i++)
   {
       delete [] cells[i];
   }
   delete [] cells;

   delete[] row;

   delete[] collumn;
}

int* grid::get_row(int r)
{
    for(int i=0; i<9; i++)
    {
        row[i]=cells[r][i];
    }
    return row;
}

void grid::set_row(int* r, int n)
{

            for(int j=0; j<9; j++)
            {
              cells[n][j]=r[j];
            }
}

int* grid::get_collumn(int c)
{
    for(int i=0; i<9; i++)
    {
        collumn[i]=cells[i][c];
    }
    return collumn;
}

void grid::set_collumn(int* c, int n)
{

            for(int j=0; j<9; j++)
            {
              cells[j][n]=c[j];
            }
}

int** grid::get_area(int a)
{
    for(int i=3*a, k=0; i<3*(1+a), k<3; i++, k++)
    {
        for(int j=3*a, l=0; j<3*(1+a), l<3; j++, l++)
        {
            area[k][l]=cells[i][j];
        }
    }
    return area;
}

void grid::collumn_shift(int c, int n)
{
    collumn=get_collumn(c);
    int* arr=new int[n];
    int j=n-1;
        for (int i = 8; i > 0; i--)
        {
            if(i>=n)
            {
                if(i+n>8)
                {
                    arr[j--]=collumn[i];
                }
                collumn[i] = collumn[i - n];
            }
            else
            {
                if(j>=0)
                {
                arr[j--]=collumn[i];
                }
            }
        }
   for(int i=0; i<n; i++)
        {
            collumn[i]=arr[i];
        }
   delete[] arr;
   set_collumn(collumn, c);
}

void grid::row_shift(int r, int n)
{
    row=get_row(r);
    while(n>=9)
    {
        n-=8;
    }
    int* arr=new int[n];
    int j=n-1;
    for (int i = 8; i > 0; i--)
        {
            if(i>=n)
            {
                if(i+n>8)
                {
                    arr[j--]=row[i];
                }
                row[i] = row[i - n];
            }
            else
            {
                if(j>=0)
                {
                arr[j--]=row[i];
                }
            }
        }


   for(int i=0; i<n; i++)
        {
            row[i]=arr[i];
        }
    delete[] arr;
   set_row(row, r);
}

void grid::TransposeTable()
{
   int** res = new int*[9];
   for(int i = 0; i < 9; ++i)
         res[i] = new int[9];

   for(int i = 0; i < 9; ++i)
      for(int j = 0; j < 9; ++j)
     res[j][i] = cells[i][j];

   for(int i = 0; i < 9; ++i)
      for(int j = 0; j < 9; ++j)
     cells[j][i]=res[j][i];

   for(int i = 0; i < 9; ++i)
         delete[] res[i];
      delete[] res;
}
/*
void grid::shuffle()
{

}
*/
void grid::Print()
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::cout<<cells[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}
