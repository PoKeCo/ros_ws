#include <stdio.h>
#include <iostream>

typedef struct _dat{
  int x;
  int y;
  int z;
} dat;

typedef dat* dat_ptr;

void add( int &ans, int &x, int &y ){
  ans = x + y ;
}

void add( dat& d ){
  d.z = d.x + d.y ;
}

void add( dat_ptr& d ){
  d->z = d->x + d->y ;
}

int main(int argc, char *argv[] ){
  int x, y, z ;
  dat d;
  dat_ptr dp = (&d);
  d.x = x = 10;
  d.y = y = 20;
  d.z = z = 0;
  printf("%d = %d + %d \n", z, x, y );
  add( z, x, y );
  printf("%d = %d + %d \n", z, x, y );
  add( d );
  printf("%d = %d + %d \n", d.z, d.x, d.y );
  add( dp );
  printf("%d = %d + %d \n", dp->z, dp->x, dp->y );
  return 0;
}
