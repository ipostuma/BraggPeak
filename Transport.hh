#include "TNtuple.h"

class Transport{
public:
  Transport(float E,int z, float m, int Z, int A, float p){m_E=E;m_x=0;m_z=z;m_m=m;m_Z=Z;m_A=A;m_p=p;};
  ~Transport(){
    delete[] m_nt;
  };

  void Run(float precision);
private:
  //Projectile information
  float m_E;
  float m_x;
  int m_z;
  float m_m;
  //Target informations
  int m_Z;
  int m_A;
  float m_p;
  //costanti
  const float m_Mu = 1; //molar mas constant 1g/mol
  const float m_Na = 6.022e23; //Avogadro's number
  const float m_c = 3e8; // speed of light (m/s)
  const float m_e0 = 8.854e-12; //Vacuum permittivity (F/m)
  const float m_e = 1.6021766e-19; //Elementary charge (coulmbs)
  const float m_me = 9.11e-31; // Electron mass (kg)
  //traccia
  TNtuple* m_nt = new TNtuple("Bragg Peak","Bragg Peak","x:y");
};
