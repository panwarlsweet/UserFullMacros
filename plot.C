/// from https://root.cern/doc/master/hvector_8C_source.html

void plot(){
  ///// define canvas on which you will plot 
  TCanvas c1;
    
  ////// open root file in read mode and assign a pointer to file
  TFile *_file0 = TFile::Open("ForShreyas/out_tree_run_01.root", "READ");

  // declare varaibles and branches to assign as pointer to the tree branch
  std::vector<double> *pT = 0;
  std::vector<double> *eta = 0;
  std::vector<double> *phi = 0;
  std::vector<double> *mass = 0;
  std::vector<int> *pid = 0;

  TBranch *bpT = 0;
  TBranch *beta = 0;
  TBranch *bphi = 0;
  TBranch *bmass = 0;
  TBranch *bpid = 0;

  // define four vectors which we will construct from root file
  TLorentzVector p4_h, p4_a0, p4_zp;
    
  /// assign a poiter to the tree
  TTree *Tree0 = (TTree*)_file0->Get("ana/anatree");
    
  std::cout << Tree0->GetEntries()<< std::endl;
     
  /// set branch address to declared variable and branches
  Tree0->SetBranchAddress("GenParticles_genpid", &pid, &bpT);
  Tree0->SetBranchAddress("GenParticles_genpt", &pT, &beta);
  Tree0->SetBranchAddress("GenParticles_geneta", &eta, &bpid);
  Tree0->SetBranchAddress("GenParticles_genphi", &phi, &bphi);
  Tree0->SetBranchAddress("GenParticles_genmass", &mass, &bmass);
    
  /// define histogram
  TH1F *h_pT_H = new TH1F("","", 100, 0, 500);
  TH1F *h_eta_H = new TH1F("","", 100, 5, 5);
  TH1F *h_mass_zp = new TH1F("","", 200, 0, 1000 );
        
  Long64_t nentries = Tree0->GetEntries();  /// total no. of generated events

  // loop over events
  for (Long64_t i= 0; i< nentries  ; i++){
    // load entry from tree
    Long64_t tentry = Tree0->LoadTree(i);

    /// Get entry from branches

    bpT->GetEntry(tentry);
    beta->GetEntry(tentry);
    bphi->GetEntry(tentry);
    bmass->GetEntry(tentry);
    bpid->GetEntry(tentry);

    for(UInt_t j = 0; j < pid->size() ; ++j){
      if (pid->at(j) == 25){  /// for higgs
	       
	/// filling pT and eta inside loop
	h_pT_H->Fill(pT->at(j));
	h_eta_H->Fill(eta->at(j));
		  
	// making higgs four vector
	p4_h.SetPtEtaPhiM(pT->at(j), eta->at(j), phi->at(j), mass->at(j) );
      }
      if (pid->at(j) == 28){  /// for A0
	// making a0 four vector
	p4_a0.SetPtEtaPhiM(pT->at(j), eta->at(j), phi->at(j), mass->at(j) );
      }	    
		    
      //else continue;
    }

    // reconstruct zp from a0 and h
    p4_zp = p4_h + p4_a0;
    std::cout << p4_zp.M() << endl;
    h_mass_zp->Fill(p4_zp.M());
	
  }

  /// Draw and save histogram
  c1.cd();
  h_pT_H->DrawNormalized("hist");
  c1.SaveAs("h_pT.png");
  c1.SaveAs("h_pT.pdf");
  c1.SaveAs("h_pT.root");

  c1.cd();

  h_eta_H->DrawNormalized("hist");
  c1.SaveAs("h_eta.png");
  c1.SaveAs("h_eta.pdf");
  c1.SaveAs("h_eta.root");
    
  c1.cd();

  h_mass_zp->DrawNormalized("hist");
  c1.SaveAs("mass_zp.png");
  c1.SaveAs("mass_zp.pdf");
  c1.SaveAs("mass_zp.root");

    
    
    
}
