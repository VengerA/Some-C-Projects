#include<stdio.h>
#include<math.h>


double func(double l, double n, double p, double E){
    return pow(E, n) * l - (pow(E, n) - 1) * p / (E - 1);
}
  
double deriv(double l, double n, double p, double E){
    return n * pow(E, n-1) * l - (n * pow(E, n-1) * p * (E-1) - (pow(E, n) - 1) * p) /  pow(E - 1, 2);
}

int main(){
  int tasknumber;
  double l, n, p, r, E, Enew, diff; 

 

  scanf("%d", &tasknumber );
  if (tasknumber == 1) {
    /* FINDING L */
    scanf("%lf %lf %lf ", &n, &p, &r);
    E = 1 + r;
    l = (pow(E, n) - 1) * p / (r * pow(E, n));
    printf("%lf", l) ;
  }
  else if (tasknumber == 2){
    /* FINDING N */
    scanf("%lf %lf %lf", &l, &p, &r);
    E = 1 + r;
    n = log(p / (p - r * l)) / log(E);
    printf("%.1lf", n);
  }
  else if ( tasknumber == 3) {
    /* FINDING P  */
    scanf("%lf %lf %lf", &l, &n, &r);
    E = r + 1;
    p = l * pow(E, n) * r / (pow(E, n) - 1) ;
    printf ("%lf", p);
  }
  else if (tasknumber == 4 ){
    /* finding R */
    scanf("%lf %lf %lf", &l, &n, &p);
    E = 2;
    diff = 1;
    while (fabs(diff) > 0.00001){
      Enew = E - func(l, n, p, E) / deriv(l, n, p, E);
      diff = Enew - E;
      E = Enew;
    }
    r = E - 1;
    printf("%lf", r);
  }
  return 0;
}
