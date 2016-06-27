#include <iostream>
#include <stdlib.h>
#include "Transport.hh"

int main(int argc, char const *argv[]) {
  float ProjectileEnergy=1e8;
  float precision=0.0001;
  if (argc>2) {
    ProjectileEnergy=atof(argv[1]);
    precision=atof(argv[2]);
  }

  const float ProtonMass = 1.67e-27; //kg
  Transport T(ProjectileEnergy,1,ProtonMass,6,12,2e6);
  T.Run(precision);

  return 0;
}
