// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// This class contains all needed variables to read ROOT ntuples for hgg analysis
// (automaticlly produced by ROOT, then slightly tuned manually)
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#ifndef ZTree_h
#define ZTree_h

#include <TROOT.h>
#include <TChain.h>

// Class which gives access to all information in each event stored in ntuples
class ZTree {
public :
   // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   // public members (for direct access outside the class)
   // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
   // pointer to the analyzed TTree or TChain
   TTree *fChain;  

   // MC flag (true for MC, false for data)
   bool _flagMC;

   // variable array max sizes
   static const int maxNph = 50; // photons

   // Ntuple variables (their description can be found also in Analyzer/src/Analyzer.cc)
   //[N] means that this is fixed size array with N elements
   Int_t           evRunNumber; // run number
   Int_t           evEventNumber; // event number
   Float_t         rho;
   
   Int_t           Nph;
   Float_t         phPt[maxNph];   //[Nph]
   Float_t         phEta[maxNph];   //[Nph]
   Float_t         phPhi[maxNph];   //[Nph]
   Float_t         phR9[maxNph];   //[Nph]
   Float_t         phTrkSumPtHollowConeDR04[maxNph];   //[Nph]
   Float_t         phEcalRecHitSumEtConeDR04[maxNph];   //[Nph]
   Float_t         phHcalTowerSumEtConeDR04[maxNph];   //[Nph]
   Float_t         phTrkSumPtHollowConeDR03[maxNph];   //[Nph]
   Float_t         phEcalRecHitSumEtConeDR03[maxNph];   //[Nph]
   Float_t         phHcalTowerSumEtConeDR03[maxNph];   //[Nph]
   Float_t         phHadronicOverEm[maxNph];   //[Nph]
   Float_t         phChargedHadronIsoDR04[maxNph];
   Float_t         phChargedHadronIsoDR02[maxNph];
   Float_t         phChargedHadronIsoDR03[maxNph];
   Float_t         phIsolationSumDR04[maxNph];
   Float_t         phIsolationSumDR03[maxNph];
   Float_t         phIsolationSumWrongVtxDR04[maxNph];
   Float_t         phIsolationSumWrongVtxDR03[maxNph];
   Int_t           phNumElectronsSuperCluster[maxNph];
   Int_t           elMissingHits[maxNph];
   Float_t         phElectronDR[maxNph];
   Int_t           phHasConversionTracks[maxNph];
   Float_t         phSigmaIetaIeta[maxNph];   //[Nph]
   Float_t         phMatch[maxNph];   //[Nph]
   Int_t           Triggers;
   Int_t           Npv;
   Int_t           pvNDOF;
   Float_t         pvZ;
   Float_t         pvRho;
   
   // variables for MC only
   Int_t           mcEventType; //
   float mcH[4];    // higgs four momentum
   float mcPh[2][4]; // ph1, ph2 four momentum

   // List of branches (their names follow variable names with prefix b_)
   TBranch        *b_evRunNumber;   //!
   TBranch        *b_evEventNumber;   //!
   TBranch        *b_rho; //!
   TBranch        *b_Nph;   //!
   TBranch        *b_phPt;   //!
   TBranch        *b_phEta;   //!
   TBranch        *b_phPhi;   //!
   TBranch        *b_phR9;   //!
   TBranch        *b_phTrkSumPtHollowConeDR04;   //!
   TBranch        *b_phEcalRecHitSumEtConeDR04;   //!
   TBranch        *b_phHcalTowerSumEtConeDR04;   //!
   TBranch        *b_phTrkSumPtHollowConeDR03;   //!
   TBranch        *b_phEcalRecHitSumEtConeDR03;   //!
   TBranch        *b_phHcalTowerSumEtConeDR03;   //!
   TBranch        *b_phHadronicOverEm;
   TBranch        *b_phChargedHadronIsoDR04;
   TBranch        *b_phChargedHadronIsoDR02;
   TBranch        *b_phChargedHadronIsoDR03;
   TBranch        *b_phIsolationSumDR04;
   TBranch        *b_phIsolationSumDR03;
   TBranch        *b_phIsolationSumWrongVtxDR04;
   TBranch        *b_phIsolationSumWrongVtxDR03;
   TBranch        *b_phNumElectronsSuperCluster;
   TBranch        *b_elMissingHits;
   TBranch        *b_phElectronDR;
   TBranch        *b_phHasConversionTracks;
   TBranch        *b_phSigmaIetaIeta;
   TBranch        *b_phMatch;
   TBranch        *b_Triggers;   //!
   TBranch        *b_Npv;   //!
   TBranch        *b_pvNDOF;   //!
   TBranch        *b_pvZ;   //!
   TBranch        *b_pvRho;   //!
   // for MC only
   TBranch        *b_mcEventType;   //!
   TBranch        *b_mcH;   //!
   TBranch        *b_mcPh;   //!

   // constructor
   // argument: true for MC, false (default) for data
   ZTree(bool flagMC = false) : fChain(0), _flagMC(flagMC) { }
   
   // destructor
   virtual ~ZTree() { }
   
   // initialise with provided tree pointer
   virtual void    Init(TTree *tree);
};

// initialise with provided tree pointer
void ZTree::Init(TTree *tree)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evRunNumber", &evRunNumber, &b_evRunNumber);
   fChain->SetBranchAddress("evEventNumber", &evEventNumber, &b_evEventNumber);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("Nph", &Nph, &b_Nph);
   fChain->SetBranchAddress("phPt", phPt, &b_phPt);
   fChain->SetBranchAddress("phEta", phEta, &b_phEta);
   fChain->SetBranchAddress("phPhi", phPhi, &b_phPhi);
   fChain->SetBranchAddress("phR9", phR9, &b_phR9);
   fChain->SetBranchAddress("phTrkSumPtHollowConeDR04", phTrkSumPtHollowConeDR04, &b_phTrkSumPtHollowConeDR04);
   fChain->SetBranchAddress("phEcalRecHitSumEtConeDR04", phEcalRecHitSumEtConeDR04, &b_phEcalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("phHcalTowerSumEtConeDR04", phHcalTowerSumEtConeDR04, &b_phHcalTowerSumEtConeDR04);
   fChain->SetBranchAddress("phTrkSumPtHollowConeDR03", phTrkSumPtHollowConeDR03, &b_phTrkSumPtHollowConeDR03);
   fChain->SetBranchAddress("phEcalRecHitSumEtConeDR03", phEcalRecHitSumEtConeDR03, &b_phEcalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("phHcalTowerSumEtConeDR03", phHcalTowerSumEtConeDR03, &b_phHcalTowerSumEtConeDR03);
   fChain->SetBranchAddress("phHadronicOverEm", phHadronicOverEm, &b_phHadronicOverEm);
   fChain->SetBranchAddress("phChargedHadronIsoDR04", phChargedHadronIsoDR04, &b_phChargedHadronIsoDR04);
   fChain->SetBranchAddress("phChargedHadronIsoDR02", phChargedHadronIsoDR02, &b_phChargedHadronIsoDR02);
   fChain->SetBranchAddress("phChargedHadronIsoDR03", phChargedHadronIsoDR03, &b_phChargedHadronIsoDR03);
   fChain->SetBranchAddress("phIsolationSumDR04", phIsolationSumDR04, &b_phIsolationSumDR04);
   fChain->SetBranchAddress("phIsolationSumDR03", phIsolationSumDR03, &b_phIsolationSumDR03);
   fChain->SetBranchAddress("phIsolationSumWrongVtxDR04",phIsolationSumWrongVtxDR04, &b_phIsolationSumWrongVtxDR04);
   fChain->SetBranchAddress("phIsolationSumWrongVtxDR03", phIsolationSumWrongVtxDR03, &b_phIsolationSumWrongVtxDR03);
   fChain->SetBranchAddress("phNumElectronsSuperCluster", phNumElectronsSuperCluster, &b_phNumElectronsSuperCluster);
   fChain->SetBranchAddress("elMissingHits", elMissingHits, &b_elMissingHits);
   fChain->SetBranchAddress("phElectronDR", phElectronDR , &b_phElectronDR);
   fChain->SetBranchAddress("phHasConversionTracks",phHasConversionTracks, &b_phHasConversionTracks);
   fChain->SetBranchAddress("phSigmaIetaIeta", phSigmaIetaIeta, &b_phSigmaIetaIeta);
   fChain->SetBranchAddress("Triggers", &Triggers, &b_Triggers);
   fChain->SetBranchAddress("Npv", &Npv, &b_Npv);
   fChain->SetBranchAddress("pvNDOF", &pvNDOF, &b_pvNDOF);
   fChain->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   fChain->SetBranchAddress("pvRho", &pvRho, &b_pvRho);
   // MC
   if(_flagMC)
   {
     fChain->SetBranchAddress("mcEventType", &mcEventType, &b_mcEventType);
     fChain->SetBranchAddress("mcH", mcH, &b_mcH);
     fChain->SetBranchAddress("mcPh", mcPh, &b_mcPh);
     fChain->SetBranchAddress("phMatch", phMatch, &b_phMatch);
   }
}

#endif // #ifdef ZTree_h
