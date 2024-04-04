#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
//#include <tgmath.h> // this header contains both math.h and complex.h and has been made to fit most mathematical needs

#define DEG_RAD acos(-1)/180

long RSAbrk(long long *pq, int *p, int *q)
{
  double tmp_q=0,sqrt_pq=sqrt((long double)(*pq));
  long remainder=1;
  int n=2,m=round((trunc(log10l(*pq))-2)/2);
  double px=pow(10,-m),x=0; //cos_px=cos(px),sin_px=sin(px);

  for(n=1; n>=0 && remainder ; n--)
    {
      for(x=0; x<90 && remainder ; x=x+px)
	{
	  tmp_q=sqrt_pq*sqrt(exp((double)n)*exp(sin(x*DEG_RAD))); 
	  if((long)trunc(tmp_q)!=(*pq) || (long)round(tmp_q)!=(*pq))
	    {
	      remainder=(*pq)%(long)trunc(tmp_q);
	    }
			 
	  fprintf(stdout,"n=%d x=%lf tmp_q=%ld px=%lf m=%d log_pq=%Lf\n",n,x,(long)trunc(tmp_q),px,m,log10l(*pq));
	}
    }
  if(!remainder)
    {
      *q=trunc(tmp_q);
      *p=(*pq)/(*q);
    }
  
  return remainder;
}
