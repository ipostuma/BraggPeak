#include <iostream>
#include <stdlib.h>
#include "Transport.hh"
// x root
#include "TApplication.h"
#include "TCanvas.h"
#include "TNtuple.h"
#include "TH1F.h"

int main(int argc, char **argv) {
  float ProjectileEnergy=1e8;
  float precision=0.0001;
  if (argc>2) {
    ProjectileEnergy=atof(argv[1]);
    precision=atof(argv[2]);
  }

  const float ProtonMass = 1.67e-27; //kg
  Transport T(ProjectileEnergy,1,ProtonMass,6,12,2e6);
  T.Run(precision);

  //root app init
  TApplication myApp("BraggPeak",&argc,argv);
  //canvas interface
  TCanvas* screen = new TCanvas("Screen","Draw",0,0,800,600);
  //ntuople Draw
  TNtuple* nt = T.GetNTuple();
  nt->Draw("x:y");
  TH1F *h = (TH1F*)gPad->GetPrimitive("htemp");
  h->SetTitle("basic Bragg Peak");
  h->SetXTitle("Depth (m)");
  h->SetYTitle("Stopping Power (Mev g cm^{-2})");
  h->SetTitleOffset(1.5,"y");
  //run app
  myApp.Run();

  return 0;
}
