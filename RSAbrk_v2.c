#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

//#include <tgmath.h> // this header contains both math.h and complex.h and has been made to fit most mathematical needs

#define DEG_RAD acos(-1)/180

long RSAbrk(long long *pq, int *p, int *q)
{
  double tmp_q=0,sqrt_pq=sqrt((long double)(*pq));
  long remainder=1;
  int n=0,m=trunc((trunc(log10l(*pq))-2)/2);
  double px=pow(10,-m),n_max=round(0.5*sqrt_pq*fabsl(9-px)/sqrt(fabsl(8-px))-1); //n_ref=(*pq-pow(10,2m+2))/;

  for(n=0; n<=(int)n_max && remainder ; n++)
    {
      tmp_q=sqrt(*pq+pow(n+1,2))+n+1;
      remainder=*pq%(long long)tmp_q;

      fprintf(stdout,"n=%d tmp_q=%lf m=%d n_max=%lf a=%d\n",((int)tmp_q%2==0)?n:-1,tmp_q,m,n_max,2*(n+1));
      
    }
  if(!remainder)
    {
      *q=trunc(tmp_q);
      *p=(*pq)/(*q);
    }
  
  return remainder;
}
