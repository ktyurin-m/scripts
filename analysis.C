#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
 

void analysis(){
    TFile *f = new TFile("B2out.root");
    TTree *t = (TTree*)f->Get("Data");
    Double_t z;
    Double_t y;
    t->SetBranchAddress("y",&y);
    t->SetBranchAddress("z",&z);

    TH2F *h = new TH2F("h","h",300,-2000,2000,300,-2000,2000);
    Int_t ent = t->GetEntries();
    for (Int_t i = 0; i < ent; i++)
    {
        t->GetEntry(i);
        h->Fill(y,z);
    }
    
    t->ResetBranchAddresses();
    h->Draw("colz");
    
}

// {
//     // auto file = new TFile("B2out.root","update");
//     // auto tree = file->Get<TTree>("Data");
//     // Float_t new_v;

//     // auto newBranch = tree->Branch("new_v", &new_v);
 
//     // Long64_t nentries = tree->GetEntries(); // read the number of entries in the t3
 
//     // for (Long64_t i = 0; i < nentries; i++) {
//     //     new_v = gRandom->Gaus(0, 1);
//     //     newBranch->Fill();
//     // };
//     // tree->Write("", TObject::kOverwrite); 



// }