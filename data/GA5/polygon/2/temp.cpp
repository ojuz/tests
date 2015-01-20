#include<cstdio>

long long get(long long x)
{
  if(x<2)return 0;
  return (x/2)*(x/2+1)-2;
}

int main()
{
  long long a,b;
  scanf("%lld%lld",&a,&b);
  printf("%lld",get(b)-get(a-1));
}
