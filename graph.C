void graph() {
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun
   TFile *f = new TFile("phse2_3.0.root","recreate");
   TCanvas *c1 = new TCanvas("c1","SubJet_btagging_Phase2_vs_Run2",200,10,700,500);

   c1->SetFillColor(42);
   c1->SetGrid();

   const Int_t n = 20;
  // Double_t x[n], y[n];
    double  y[n]={
        1.0 ,
        0.381898262487 ,
        0.194821676299 ,
        0.123349113825 ,
        0.0839642419454 ,
        0.0599015844775 ,
        0.0434720399137 ,
        0.0314344902238 ,
        0.0229615482715 ,
        0.0169334419927 ,
        0.0129209254294 ,
        0.009623818796 ,
        0.00701101731292 ,
        0.00497676472967 ,
        0.00358949156127 ,
        0.00243239376163 ,
        0.00150547133072 ,
        0.000889596695428 ,
        0.000435466913846 ,
        0.00011819816233 ,
    };
    double  x[n]={1.0 ,
        0.946108423449 ,
        0.890438247012 ,
        0.844116391577 ,
        0.802539840637 ,
        0.762699203187 ,
        0.724879055208 ,
        0.687322140011 ,
        0.650803927149 ,
        0.617287990894 ,
        0.586361696073 ,
        0.554887592487 ,
        0.522410358566 ,
        0.489605862265 ,
        0.454275754126 ,
        0.414669891861 ,
        0.373221400114 ,
        0.326060045532 ,
        0.268554354013 ,
        0.187592487194 ,
    };
  f->cd();
   for (Int_t i=0;i<n;i++) {
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   TGraph *gr = new TGraph(n,x,y);
   gr->SetLineColor(kGreen);
   gr->SetLineWidth(4);
   gr->SetLineStyle(1);
    gr->SetMarkerSize(0);
   gr->SetMarkerColor(kRed);
   gr->SetMarkerStyle(21);
   gr->SetTitle("DeepCSV_SubJet_btagging_Run2VsPhase2");
   gr->GetXaxis()->SetTitle("b-tagging efficiency");
   gr->GetYaxis()->SetTitle("mistag rate");
   gr->Draw();
   gr->Write();
   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->SetLogy();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
   c1->Write();
   c1->SaveAs("udsg_r.png");
   f->Close();
}

