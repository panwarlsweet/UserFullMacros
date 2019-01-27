//// This macro reads the branches of one tree and save in another tree in the same root file /////////

void Skim()
{
  //////   Set root file in update mode //////
TFile *_file0 = TFile::Open("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_numEvent100_0.root","update");

////// Assignm pointer to tree /////////
TTree *Tree1 = (TTree*)_file0->Get("genDiphotonDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");
TTree *Tree2 = (TTree*)_file0->Get("tagsDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");

/////// define varibales ////////
 float leadJet_bRegNN, leadingJet_bRegNNCorr, subleadJet_bRegNN, subleadingJet_bRegNNCorr,leadingJet_bRegNNResolution, subleadingJet_bRegNNResolution, leadJet_bRegNNResolution, subleadJet_bRegNNResolution;

 ////////// define branch ////////////
TBranch *bleadJet_bRegNN = Tree1->Branch("leadJet_bRegNN",&leadJet_bRegNN,"leadJet_bRegNN/F");
TBranch *bsubleadJet_bRegNN = Tree1->Branch("subleadJet_bRegNN",&subleadJet_bRegNN,"subleadJet_bRegNN/F");
TBranch *bleadJet_bRegNNResolution = Tree1->Branch("leadJet_bRegNNResolution",&leadJet_bRegNNResolution,"leadJet_bRegNNResolution/F");
TBranch *bsubleadJet_bRegNNResolution = Tree1->Branch("subleadJet_bRegNNResolution",&subleadJet_bRegNNResolution,"subleadJet_bRegNNResolution/F");

/////////// set branch address to the storable branch ////////
Tree2->SetBranchAddress("leadingJet_bRegNNCorr",&leadingJet_bRegNNCorr);
Tree2->SetBranchAddress("subleadingJet_bRegNNCorr",&subleadingJet_bRegNNCorr);
Tree2->SetBranchAddress("leadingJet_bRegNNResolution",&leadingJet_bRegNNResolution);
Tree2->SetBranchAddress("subleadingJet_bRegNNResolution",&subleadingJet_bRegNNResolution);

Long64_t nentries = Tree2->GetEntries();

////// loop over entries /////////
for (Long64_t i=0;i<nentries;i++){
  Tree2->GetEntry(i); 
  
  ////// assign value ///////
  leadJet_bRegNN = leadingJet_bRegNNCorr; 
  subleadJet_bRegNN = subleadingJet_bRegNNCorr;
  leadJet_bRegNNResolution = leadingJet_bRegNNResolution;
  subleadJet_bRegNNResolution = subleadingJet_bRegNNResolution;

  /////// fill branch////////////
  bleadJet_bRegNN->Fill();
  bsubleadJet_bRegNN->Fill(); 
  bleadJet_bRegNNResolution->Fill();
  bsubleadJet_bRegNNResolution->Fill();
   }

Tree1->Print(); 
Tree1->SetName("NewRegTree");
Tree1->SetTitle("NewRegTree");
//Tree1->AutoSave();
Tree1->Write();
 delete Tree1;
 delete Tree2;
//_file0->Write();
 delete _file0;  
}

