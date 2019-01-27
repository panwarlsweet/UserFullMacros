#include <vector>
#include <string>
#include "TStyle.h"

using namespace std;

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  gROOT->SetStyle("Plain");
  gROOT->ForceStyle();

  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadBorderMode(0);

  //tdrStyle->SetFrameColor(0);
  tdrStyle->SetPadColor(0);
  tdrStyle->SetCanvasColor(0);
  tdrStyle->SetStatColor(0);
  tdrStyle->SetFillColor(0);

  tdrStyle->SetPaperSize(20,26);
  //tdrStyle->SetPadTopMargin(0.08);
  //tdrStyle->SetPadBottomMargin(0.14);
  tdrStyle->SetPadRightMargin(0.04);
  tdrStyle->SetPadLeftMargin(0.16);
  //tdrStyle->SetCanvasDefH(800);
  //tdrStyle->SetCanvasDefW(800);
  //tdrStyle->SetPadGridX(1);
  //tdrStyle->SetPadGridY(1);
  tdrStyle->SetPadTickX(1);
  tdrStyle->SetPadTickY(1);

  tdrStyle->SetTextFont(42); //132
  tdrStyle->SetTextSize(0.09);
  tdrStyle->SetLabelFont(42,"xyz");
  tdrStyle->SetTitleFont(42,"xyz");
  tdrStyle->SetLabelSize(0.045,"xyz"); //0.035
  tdrStyle->SetTitleSize(0.045,"xyz");
  tdrStyle->SetTitleOffset(1.5,"y");
    
  tdrStyle->SetTitleX(0.16);
  tdrStyle->SetTitleY(0.93);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(0);
  tdrStyle->SetTitleBorderSize(1);
  tdrStyle->SetTitleFontSize(0.04);
  //tdrStyle->SetPadTopMargin(0.05);
  //tdrStyle->SetPadBottomMargin(0.13);
  //tdrStyle->SetPadLeftMargin(0.14);
  //tdrStyle->SetPadRightMargin(0.02);

  // use bold lines and markers
  tdrStyle->SetMarkerStyle(8);
  tdrStyle->SetHistLineWidth(3);
  tdrStyle->SetLineWidth(1);
  
  //tdrStyle->SetOptTitle(kFALSE);
  tdrStyle->SetOptStat(0);

  tdrStyle->cd();
}

void DrawAll(bool plotEff=false, bool plotDisc=false, bool plotEffDisc=false)
{
  
  //style setting
  setTDRStyle();
  
  //+++++++++++++++++++++++++++++++++++++++++++//
  //+++++++++++++++++++++++++++++++++++++++++++//

  //TFile *_file1 = TFile::Open("DQM_RelVal-200evts.root");
  //TFile *_file1 = TFile::Open("DQM_RelValTTbar-100K.root");
  //TFile *_file1 = TFile::Open("DQM_RelValTTbar-50Kone.root");

  /*
  TFile *_file1 = TFile::Open("DQM_RelValTTbar-1K.root");
  TFile *_file2 = TFile::Open("DQM_Phase1_1K.root");

  TFile *_file1 = TFile::Open("DQM_RelValTTbar-10K.root");
  TFile *_file2 = TFile::Open("DQM_Phase1_10K.root");

  TFile *_file1 = TFile::Open("DQM_RelValTTbar-50Kone.root");
  TFile *_file2 = TFile::Open("DQM_Phase1_50Kone.root");
  */

  TFile *_file1 = TFile::Open("DQM_RelValTTbar-100K.root");
  TFile *_file2 = TFile::Open("DQM_Phase1_100K.root");

  //+++++++++++++++++++++++++++++++++++++++++++//
  //+++++++++++++++++++++++++++++++++++++++++++//

  Double_t xrange=0.35;

  if(plotEff) {

    //*********************************//
    //*********************************//

    //----------//
    TPaveText *pt1 = new TPaveText(0.15,0.85,0.6,0.9,"brNDC");   
    pt1->SetBorderSize(0);     pt1->SetFillStyle(0);  
    pt1->SetTextAlign(13);     pt1->SetTextFont(42);   
    pt1->SetTextSize(0.03);    pt1->SetTextColor(4);
    TText *text = pt1->AddText("TTbarRelVal100K-910pre2-CATrack");

    TPaveText *pt2 = new TPaveText(0.15,0.8,0.6,0.85,"brNDC");   
    pt2->SetBorderSize(0);     pt2->SetFillStyle(0);  
    pt2->SetTextAlign(13);     pt2->SetTextFont(42);   
    pt2->SetTextSize(0.03);    pt2->SetTextColor(6);   
    TText *text = pt2->AddText("Phase1TTbar100K-81X-DefTrack");
    //----------//

    TCanvas * c1 = new TCanvas("c1","non-b vs b eff",700,700);
    c1->SetGridy();  
    c1->SetGridx();  
    c1->SetLogy();  
    c1->cd();
  
    _file1->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h1 = FlavEffVsBEff_DUSG_discr_CSVv2_GLOBAL->Clone("h1");
    h1->SetMarkerColor(4);
    h1->SetAxisRange(xrange, 1.0,"X");
    h1->Draw("lpe");

    TH1F *h1c = FlavEffVsBEff_C_discr_CSVv2_GLOBAL->Clone("h1c");
    h1c->SetMarkerColor(4);
    h1c->Draw("lpesame");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h2 = FlavEffVsBEff_DUSG_discr_CSVv2_GLOBAL->Clone("h2");
    h2->SetMarkerColor(6);
    h2->Draw("lpesame");

    TH1F *h2c = FlavEffVsBEff_C_discr_CSVv2_GLOBAL->Clone("h2c");
    h2c->SetMarkerColor(6);
    h2c->Draw("lpesame");

    pt1->Draw();
    pt2->Draw();

    c1->Update();

    c1->Print("plots/nonbVSb_CSVv2.png");

    //*********************************//
    // DeepCSV : probb
    //*********************************//
    TCanvas * c2 = new TCanvas("c2","non-b vs b eff",700,700);
    c2->SetGridy();  
    c2->SetGridx();  
    c2->SetLogy();  
    c2->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h1bcdeepcsv = FlavEffVsBEff_DUSG_discr_deepCSV_probb_GLOBAL->Clone("h1bcdeepcsv");
    h1bcdeepcsv->SetMarkerColor(4);     h1bcdeepcsv->SetLineColor(4);
    h1bcdeepcsv->SetAxisRange(0.0, 1.0,"X");
    h1bcdeepcsv->Draw("lpe");

    TH1F *h1bldeepcsv = FlavEffVsBEff_C_discr_deepCSV_probb_GLOBAL->Clone("h1bldeepcsv");
    h1bldeepcsv->SetMarkerColor(4);    h1bldeepcsv->SetLineColor(4);     h1bldeepcsv->SetLineStyle(2);
    h1bldeepcsv->Draw("lpe same");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h2bcdeepcsv = FlavEffVsBEff_DUSG_discr_deepCSV_probb_GLOBAL->Clone("h2bcdeepcsv");
    h2bcdeepcsv->SetMarkerColor(6);    h2bcdeepcsv->SetLineColor(6);
    h2bcdeepcsv->Draw("lpe same");

    TH1F *h2bldeepcsv = FlavEffVsBEff_C_discr_deepCSV_probb_GLOBAL->Clone("h2bldeepcsv");
    h2bldeepcsv->SetMarkerColor(6);    h2bldeepcsv->SetLineColor(6);     h2bldeepcsv->SetLineStyle(2);
    h2bldeepcsv->Draw("lpe same");
    
    pt1->Draw();
    pt2->Draw();

    c2->Update();
    c2->Print("plots/nonbVSb_deepCSVprobb.png");

    //*********************************//
    // DeepCSV : probbb
    //*********************************//
    TCanvas * c3 = new TCanvas("c3","non-b vs b eff",700,700);
    c3->SetGridy();  
    c3->SetGridx();  
    c3->SetLogy();  
    c3->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h1bbcdeepcsv = FlavEffVsBEff_DUSG_discr_deepCSV_probbb_GLOBAL->Clone("h1bbcdeepcsv");
    h1bbcdeepcsv->SetMarkerColor(4);     h1bbcdeepcsv->SetLineColor(4);
    h1bbcdeepcsv->SetAxisRange(0.0, 1.0,"X");
    h1bbcdeepcsv->Draw("lpe");

    TH1F *h1bbldeepcsv = FlavEffVsBEff_C_discr_deepCSV_probbb_GLOBAL->Clone("h1bbldeepcsv");
    h1bbldeepcsv->SetMarkerColor(4);    h1bbldeepcsv->SetLineColor(4);     h1bbldeepcsv->SetLineStyle(2);
    h1bbldeepcsv->Draw("lpe same");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h2bbcdeepcsv = FlavEffVsBEff_DUSG_discr_deepCSV_probbb_GLOBAL->Clone("h2bbcdeepcsv");
    h2bbcdeepcsv->SetMarkerColor(6);    h2bbcdeepcsv->SetLineColor(6);
    h2bbcdeepcsv->Draw("lpe same");

    TH1F *h2bbldeepcsv = FlavEffVsBEff_C_discr_deepCSV_probbb_GLOBAL->Clone("h2bbldeepcsv");
    h2bbldeepcsv->SetMarkerColor(6);    h2bbldeepcsv->SetLineColor(6);     h2bbldeepcsv->SetLineStyle(2);
    h2bbldeepcsv->Draw("lpe same");
    
    pt1->Draw();
    pt2->Draw();

    c3->Update();
    c3->Print("plots/nonbVSb_deepCSVprobbb.png");

   //*********************************//
    // SimpleInclusiveSecondaryVertexHighEff :: SISVHE
    //*********************************//
    TCanvas * c4 = new TCanvas("c4","non-b vs b eff",700,700);
    c4->SetGridy();  
    c4->SetGridx();  
    c4->SetLogy();  
    c4->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/SISVHE_GLOBAL");
    TH1F *h1svc = FlavEffVsBEff_C_discr_SISVHE_GLOBAL->Clone("h1svc");
    h1svc->SetMarkerColor(4);
    h1svc->SetAxisRange(0.0, 1.0,"X");
    h1svc->Draw("lpe");

    TH1F *h1sv = FlavEffVsBEff_DUSG_discr_SISVHE_GLOBAL->Clone("h1sv");
    h1sv->SetMarkerColor(4);
    h1sv->Draw("lpesame");

    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/SISVHE_GLOBAL");
    TH1F *h2sv = FlavEffVsBEff_DUSG_discr_SISVHE_GLOBAL->Clone("h2sv");
    h2sv->SetMarkerColor(6);
    h2sv->Draw("lpesame");

    TH1F *h2svc = FlavEffVsBEff_C_discr_SISVHE_GLOBAL->Clone("h2svc");
    h2svc->SetMarkerColor(6);
    h2svc->Draw("lpesame");

    pt1->Draw();
    pt2->Draw();

    c4->Update();

    c4->Print("plots/nonbVSb_SISVHE.png");


    //*********************************//
    // cMVAv2
    //*********************************//
    TCanvas * c5 = new TCanvas("c5","non-b vs b eff",700,700);
    c5->SetGridy();  
    c5->SetGridx();  
    c5->SetLogy();  
    c5->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/combMVAv2_GLOBAL");
    TH1F *h1combMVAv2 = FlavEffVsBEff_DUSG_discr_combMVAv2_GLOBAL->Clone("h1combMVAv2");
    h1combMVAv2->SetMarkerColor(4);
    h1combMVAv2->SetAxisRange(xrange, 1.0,"X");
    h1combMVAv2->Draw("lpe");

    TH1F *h1combMVAv2c = FlavEffVsBEff_C_discr_combMVAv2_GLOBAL->Clone("h1combMVAv2c");
    h1combMVAv2c->SetMarkerColor(4);
    h1combMVAv2c->Draw("lpesame");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/combMVAv2_GLOBAL");
    TH1F *h2combMVAv2 = FlavEffVsBEff_DUSG_discr_combMVAv2_GLOBAL->Clone("h2combMVAv2");
    h2combMVAv2->SetMarkerColor(6);
    h2combMVAv2->Draw("lpesame");

    TH1F *h2combMVAv2c = FlavEffVsBEff_C_discr_combMVAv2_GLOBAL->Clone("h2combMVAv2c");
    h2combMVAv2c->SetMarkerColor(6);
    h2combMVAv2c->Draw("lpesame");

    pt1->Draw();
    pt2->Draw();
    
    c5->Update();

    c5->Print("plots/nonbVSb_cMVAv2.png");

  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  if(plotEffDisc) {

    //*********************************//
    //*********************************//
    
    //----------//
    TPaveText *pt1 = new TPaveText(0.45,0.85,0.9,0.9,"brNDC");   
    pt1->SetBorderSize(0);     pt1->SetFillStyle(0);  
    pt1->SetTextAlign(13);     pt1->SetTextFont(42);   
    pt1->SetTextSize(0.025);   pt1->SetTextColor(2);
    TText *text = pt1->AddText("Closed: TTbarRelVal100K-910pre2-CATrack");
    
    TPaveText *pt2 = new TPaveText(0.45,0.8,0.9,0.85,"brNDC");   
    pt2->SetBorderSize(0);     pt2->SetFillStyle(0);  
    pt2->SetTextAlign(13);     pt2->SetTextFont(42);   
    pt2->SetTextSize(0.025);   pt2->SetTextColor(1);   
    TText *text = pt2->AddText("Open: Phase1TTbar100K-81X-DefTrack");

    TPaveText *pt3 = new TPaveText(0.8,0.75,0.9,0.8,"brNDC");   
    pt3->SetBorderSize(0);     pt3->SetFillStyle(0);  
    pt3->SetTextAlign(13);     pt3->SetTextFont(42);   
    pt3->SetTextSize(0.025);   pt3->SetTextColor(2);   
    TText *text = pt3->AddText("b-jets");

    TPaveText *pt4 = new TPaveText(0.8,0.7,0.9,0.75,"brNDC");   
    pt4->SetBorderSize(0);     pt4->SetFillStyle(0);  
    pt4->SetTextAlign(13);     pt4->SetTextFont(42);   
    pt4->SetTextSize(0.025);   pt4->SetTextColor(8);   
    TText *text = pt4->AddText("c-jets");

    TPaveText *pt5 = new TPaveText(0.8,0.65,0.9,0.7,"brNDC");   
    pt5->SetBorderSize(0);     pt5->SetFillStyle(0);  
    pt5->SetTextAlign(13);     pt5->SetTextFont(42);   
    pt5->SetTextSize(0.025);   pt5->SetTextColor(4);   
    TText *text = pt5->AddText("light-jets");

    //----------//

    //*********************************//
    // DeepCSV : probb
    //*********************************//
    TCanvas * c2 = new TCanvas("c2","DeepCSV probbb Eff vs Discr",700,700);
    c2->SetGridy();  
    c2->SetGridx();  
    //c2->SetLogy();  
    c2->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h1bdeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALB->Clone("h1bdeepcsv");
    h1bdeepcsv->SetTitle("");
    h1bdeepcsv->SetXTitle("DeepCSV probb");
    h1bdeepcsv->SetYTitle("Efficiency");
    h1bdeepcsv->SetMarkerColor(2);
    h1bdeepcsv->Draw("pe");

    TH1F *h1cdeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALC->Clone("h1cdeepcsv");
    h1cdeepcsv->SetMarkerColor(8);
    h1cdeepcsv->Draw("pesame");

    TH1F *h1ldeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALDUSG->Clone("h1ldeepcsv");
    h1ldeepcsv->SetMarkerColor(4);
    h1ldeepcsv->Draw("pesame");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h2bdeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALB->Clone("h2bdeepcsv");
    h2bdeepcsv->SetMarkerStyle(24);    h2bdeepcsv->SetMarkerColor(2);
    h2bdeepcsv->Draw("pesame");

    TH1F *h2cdeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALC->Clone("h2cdeepcsv");
    h2cdeepcsv->SetMarkerStyle(24);    h2cdeepcsv->SetMarkerColor(8);
    h2cdeepcsv->Draw("pesame");

    TH1F *h2ldeepcsv = effVsDiscrCut_discr_deepCSV_probb_GLOBALDUSG->Clone("h2ldeepcsv");
    h2ldeepcsv->SetMarkerStyle(24);    h2ldeepcsv->SetMarkerColor(4);
    h2ldeepcsv->Draw("pesame");
    
    pt1->Draw();
    pt2->Draw();
    pt3->Draw();    pt4->Draw();    pt5->Draw();

    c2->Update();
    //c2->BuildLegend(0.65,0.7,0.95,0.9,"");
    c2->Print("plots/EffvsDiscrCut_deepCSVprobb.png");

    //*********************************//
    // DeepCSV : probbb
    //*********************************//
    TCanvas * c3 = new TCanvas("c3","DeepCSV probbb Eff vs Discr",700,700);
    c3->SetGridy();  
    c3->SetGridx();  
    c3->SetLogy();  
    c3->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h1bbdeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALB->Clone("h1bbdeepcsv");
    h1bbdeepcsv->SetTitle("");
    h1bbdeepcsv->SetXTitle("DeepCSV probbb");
    h1bbdeepcsv->SetYTitle("Efficiency");
    h1bbdeepcsv->SetMarkerColor(2);
    h1bbdeepcsv->Draw("pe");

    TH1F *h1bcdeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALC->Clone("h1bcdeepcsv");
    h1bcdeepcsv->SetMarkerColor(8);
    h1bcdeepcsv->Draw("pesame");

    TH1F *h1bldeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALDUSG->Clone("h1bldeepcsv");
    h1bldeepcsv->SetMarkerColor(4);
    h1bldeepcsv->Draw("pesame");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h2bbdeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALB->Clone("h2bbdeepcsv");
    h2bbdeepcsv->SetMarkerStyle(24);    h2bbdeepcsv->SetMarkerColor(2);
    h2bbdeepcsv->Draw("pesame");

    TH1F *h2bcdeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALC->Clone("h2bcdeepcsv");
    h2bcdeepcsv->SetMarkerStyle(24);    h2bcdeepcsv->SetMarkerColor(8);
    h2bcdeepcsv->Draw("pesame");

    TH1F *h2bldeepcsv = effVsDiscrCut_discr_deepCSV_probbb_GLOBALDUSG->Clone("h2bldeepcsv");
    h2bldeepcsv->SetMarkerStyle(24);    h2bldeepcsv->SetMarkerColor(4);
    h2bldeepcsv->Draw("pesame");
    
    pt1->Draw();
    pt2->Draw();
    pt3->Draw();    pt4->Draw();    pt5->Draw();

    c3->Update();
    //c3->BuildLegend(0.65,0.7,0.95,0.9,"");
    c3->Print("plots/EffvsDiscrCut_deepCSVprobbb.png");

    //*********************************//
    // CSVv2
    //*********************************//
    TCanvas * c4 = new TCanvas("c4","CSVv2 Eff vs Discr",700,700);
    c4->SetGridy();  
    c4->SetGridx();  
    //c4->SetLogy();  
    c4->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h1bbcsv = effVsDiscrCut_discr_CSVv2_GLOBALB->Clone("h1bbcsv");
    h1bbcsv->SetTitle("");
    h1bbcsv->SetXTitle("CSVv2");
    h1bbcsv->SetYTitle("Efficiency");
    h1bbcsv->SetMarkerColor(2);
    h1bbcsv->Draw("pe");

    TH1F *h1bccsv = effVsDiscrCut_discr_CSVv2_GLOBALC->Clone("h1bccsv");
    h1bccsv->SetMarkerColor(8);
    h1bccsv->Draw("pesame");

    TH1F *h1blcsv = effVsDiscrCut_discr_CSVv2_GLOBALDUSG->Clone("h1blcsv");
    h1blcsv->SetMarkerColor(4);
    h1blcsv->Draw("pesame");
    //
    _file2->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h2bbcsv = effVsDiscrCut_discr_CSVv2_GLOBALB->Clone("h2bbcsv");
    h2bbcsv->SetMarkerStyle(24);    h2bbcsv->SetMarkerColor(2);
    h2bbcsv->Draw("pesame");

    TH1F *h2bccsv = effVsDiscrCut_discr_CSVv2_GLOBALC->Clone("h2bccsv");
    h2bccsv->SetMarkerStyle(24);    h2bccsv->SetMarkerColor(8);
    h2bccsv->Draw("pesame");

    TH1F *h2blcsv = effVsDiscrCut_discr_CSVv2_GLOBALDUSG->Clone("h2blcsv");
    h2blcsv->SetMarkerStyle(24);    h2blcsv->SetMarkerColor(4);
    h2blcsv->Draw("pesame");
    
    pt1->Draw();
    pt2->Draw();
    pt3->Draw();    pt4->Draw();    pt5->Draw();

    c4->Update();
    //c4->BuildLegend(0.65,0.7,0.95,0.9,"");
    c4->Print("plots/EffvsDiscrCut_CSVv2.png");

  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  if(plotDisc) {

    //*********************************//
    //*********************************//

    //----------//
    TPaveText *pt1 = new TPaveText(0.15,0.85,0.6,0.9,"brNDC");   
    pt1->SetBorderSize(0);     pt1->SetFillStyle(0);  
    pt1->SetTextAlign(13);     pt1->SetTextFont(42);   
    pt1->SetTextSize(0.03);    pt1->SetTextColor(4);
    TText *text = pt1->AddText("TTbarRelVal100K-910pre2-CATrack");
    
    TPaveText *pt2 = new TPaveText(0.15,0.8,0.6,0.85,"brNDC");   
    pt2->SetBorderSize(0);     pt2->SetFillStyle(0);  
    pt2->SetTextAlign(13);     pt2->SetTextFont(42);   
    pt2->SetTextSize(0.03);    pt2->SetTextColor(6);   
    TText *text = pt2->AddText("Phase1TTbar100K-81X-DefTrack");
    //----------//


    ///// DeepCSV
    TCanvas * c11 = new TCanvas("c11","Discriminator",700,700);
    c11->SetGridy();  
    c11->SetGridx();  
    c11->SetLogy();
    c11->cd();
  
    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h1pb = discr_deepCSV_probb_GLOBALALL->Clone("h1pb");
    h1pb->SetXTitle("DeepCSV-probb");
    h1pb->SetLineColor(4);
    h1pb->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probb_GLOBAL");
    TH1F *h2pb = discr_deepCSV_probb_GLOBALALL->Clone("h2pb");
    h2pb->SetLineColor(6);
    h2pb->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c11->Update();

    c11->Print("plots/deepCSV-probb.png");

    //////
    TCanvas * c12 = new TCanvas("c12","Discriminator",700,700);
    c12->SetGridy();  
    c12->SetGridx();  
    c12->SetLogy();
    c12->cd();
  
    _file1->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h1pbb = discr_deepCSV_probbb_GLOBALALL->Clone("h1pbb");
    h1pbb->SetXTitle("DeepCSV-probbb");
    h1pbb->SetLineColor(4);
    h1pbb->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/deepCSV_probbb_GLOBAL");
    TH1F *h2pbb = discr_deepCSV_probbb_GLOBALALL->Clone("h2pbb");
    h2pbb->SetLineColor(6);
    h2pbb->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c12->Update();

    c12->Print("plots/deepCSV-probbb.png");


    //////////
    TCanvas * c1 = new TCanvas("c1","Discriminator",700,700);
    c1->SetGridy();  
    c1->SetGridx();  
    c1->SetLogy();
    c1->cd();
  
    _file1->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h1 = discr_CSVv2_GLOBALALL->Clone("h1");
    h1->SetXTitle("CSVv2");
    h1->SetLineColor(4);
    h1->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/CSVv2_GLOBAL");
    TH1F *h2 = discr_CSVv2_GLOBALALL->Clone("h2");
    h2->SetLineColor(6);
    h2->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c1->Update();

    c1->Print("plots/CSVv2.png");

    //*********************************//
    // SimpleSecondaryVertexHighEff :: SSVHE
    //*********************************//
    TCanvas * c2 = new TCanvas("c2","Discriminator",700,700);
    c2->SetGridy();  
    c2->SetGridx();  
    c2->SetLogy();
    c2->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/SSVHE_GLOBAL");
    TH1F *h1ssv = discr_SSVHE_GLOBALALL->Clone("h1ssv");
    h1ssv->SetLineColor(4);
    h1ssv->SetXTitle("SSHHE");
    h1ssv->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/SSVHE_GLOBAL");
    TH1F *h2ssv = discr_SSVHE_GLOBALALL->Clone("h2ssv");
    h2ssv->SetLineColor(6);
    h2ssv->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c2->Update();

    c2->Print("plots/SSVHE.png");

    //*********************************//
    // SimpleInclusiveSecondaryVertexHighEff :: SISVHE
    //*********************************//
    TCanvas * c4 = new TCanvas("c4","Discriminator",700,700);
    c4->SetGridy();  
    c4->SetGridx();  
    c4->SetLogy();
    c4->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/SISVHE_GLOBAL");
    TH1F *h1sv = discr_SISVHE_GLOBALALL->Clone("h1sv");
    h1sv->SetLineColor(4);
    h1sv->SetXTitle("SISVHE");
    h1sv->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/SISVHE_GLOBAL");
    TH1F *h2sv = discr_SISVHE_GLOBALALL->Clone("h2sv");
    h2sv->SetLineColor(6);
    h2sv->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c4->Update();

    c4->Print("plots/SISVHE.png");


    //*********************************//
    // cMVAv2
    //*********************************//
    TCanvas * c5 = new TCanvas("c5","Discriminator",700,700);
    c5->SetGridy();  
    c5->SetGridx();  
    c5->SetLogy();
    c5->cd();

    _file1->cd("/DQMData/Run 1/Btag/Run summary/combMVAv2_GLOBAL");
    TH1F *h1combMVAv2 = discr_combMVAv2_GLOBALALL->Clone("h1combMVAv2");
    h1combMVAv2->SetLineColor(4);
    h1combMVAv2->SetXTitle("cMVAv2");
    h1combMVAv2->Draw("hist");

    _file2->cd("/DQMData/Run 1/Btag/Run summary/combMVAv2_GLOBAL");
    TH1F *h2combMVAv2 = discr_combMVAv2_GLOBALALL->Clone("h2combMVAv2");
    h2combMVAv2->SetLineColor(6);
    h2combMVAv2->Draw("hist same");

    pt1->Draw();
    pt2->Draw();

    c5->Update();

    c5->Print("plots/cMVAv2.png");

  }

}




