class BetheBloch{
public:
  BetheBloch(int z, float v, float E, int Z, int A, float p){
    m_z=z;m_v=v;m_E=E*m_e;
    m_Z=Z;m_A=A;m_p=p;
    SetExcitationPotential();
  };
  ~BetheBloch(){};

  float Beta(){return m_v/m_c;};
  float dEdx();
private:
  void SetExcitationPotential(){m_I=10*m_e*m_Z;};
  //particella proiettile
  int m_z; //charge (multiple of e-)
  float m_v; //particle speed
  float m_E; //particle energy
  //Atomo bersaglio
  int m_Z; //Atomic number
  int m_A; //Atomic mass
  float m_p; //density
  float m_I; //excitation potential (eV)
  //costanti
  const float m_Mu = 1; //molar mas constant 1g/mol
  const float m_Na = 6.022e23; //Avogadro's number
  const float m_c = 3e8; // speed of light (m/s)
  const float m_e0 = 8.854e-12; //Vacuum permittivity (F/m)
  const float m_e = 1.6021766e-19; //Elementary charge (coulmbs)
  const float m_me = 9.11e-31; // Electron mass (kg)
};
