#include "BetheBloch.hh"
#include "math.h"

float BetheBloch::dEdx(){
  float b = Beta();
  float n = (m_Na*m_Z*m_p)/(m_A*m_Mu);
  float dEdx = (4*M_PI*n*pow(m_z,2.))/(m_me*pow(m_c,2.)*pow(b,2.))*pow(m_e,4.)/(16*pow(M_PI,2.)*pow(m_e0,2.));
  dEdx *= (log((2*m_me*pow(m_c,2.)*pow(b,2.))/(m_I*(1-pow(b,2.))))-pow(b,2.));
  return dEdx;
}
