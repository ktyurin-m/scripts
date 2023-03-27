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
    Double_t x;
    Double_t Edep;
    t->SetBranchAddress("y",&y);
    t->SetBranchAddress("z",&z);
    t->SetBranchAddress("x",&x);
    t->SetBranchAddress("Edep",&Edep);
    TH2F *h1 = new TH2F("h1","h1",100,-2000,2000,100,-2000,2000);
    TH2F *h2 = new TH2F("h2","h2",100,-10,0,100,0,10);
    Int_t ent = t->GetEntries();
    for (Int_t i = 0; i < ent; i++)
    {
        t->GetEntry(i);
        h1->Fill(y,z);
        h2->Fill(x,Edep);
    }
    
    t->ResetBranchAddresses();
    // h1->Draw("colz");
    h2->Draw("colz");

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