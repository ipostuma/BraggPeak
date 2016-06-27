#include "Transport.hh"
#include "BetheBloch.hh"
#include "math.h"
#include <iostream>
#include "TNtuple.h"

void Transport::Run(float precision){
  while (m_E>0) {
    float v=m_c*sqrt(1-pow((m_m*pow(m_c,2.))/((m_E*m_e)+m_m*pow(m_c,2.)),2.));
    BetheBloch C(m_z,v,m_E,m_Z,m_A,m_p);
    std::cout<<m_E/1e6<<"MeV \t "<<(C.dEdx()/m_e)/2/1e6<<"MeV g / cm^2 \t "<<m_x<<" m"<<std::endl;
    m_nt->Fill((C.dEdx()/m_e)/2/1e6,m_x);
    m_E-=(C.dEdx()/m_e)*precision;
    m_x+=precision;
  }
  m_nt->Fill(0,m_x);
}
