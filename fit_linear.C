#include <iostream>
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPaveLabel.h"
#include "TPave.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TLatex.h"
#include "TF1.h"

void fit_linear(){
  TGraph *gr1 = new TGraph("IvsV.txt", "%lg %lg","\t");
  gr1->SetMarkerStyle(21);
  gr1->SetMarkerColor(1);
  gr1->SetLineColor(0);
  gr1->SetTitle("I_{mon} vs V;V in kV;I_{mon} in mA");
  TCanvas* c20 = new TCanvas("c20","Fit",800,800) ;
  c20->SetGrid();
  TF1 *f2 = new TF1("f2", "[0]*x+[1]", 0., 2.7);
  f2->SetParLimits(0,0.,10000);
  gr1->Draw();
  gr1->Fit("f2");
  gStyle->SetOptFit(1111);

}
