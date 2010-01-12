
#ifndef DQMOffline_EGamma_ElectronTagProbeAnalyzer_h
#define DQMOffline_EGamma_ElectronTagProbeAnalyzer_h

#include "DQMOffline/EGamma/interface/ElectronDqmAnalyzerBase.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateTransform.h"


class MagneticField ;

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

class ElectronTagProbeAnalyzer : public ElectronDqmAnalyzerBase
 {
  public:

    explicit ElectronTagProbeAnalyzer(const edm::ParameterSet& conf);
    virtual ~ElectronTagProbeAnalyzer();

    virtual void book() ;
    virtual void analyze( const edm::Event & e, const edm::EventSetup & c) ;

  private:

    //=========================================
    // parameters
    //=========================================

    // general, collections
    int Selection_;
    edm::InputTag electronCollection_;
    edm::InputTag matchingObjectCollection_;
    edm::InputTag gsftrackCollection_;
    edm::InputTag trackCollection_;
    edm::InputTag vertexCollection_;
    bool readAOD_; //NEW

//    // matching
//    std::string matchingCondition_; //NEW
//    double maxPtMatchingObject_; // SURE ?
//    double maxAbsEtaMatchingObject_; // SURE ?
//    double deltaR_;

    // tag and probe NEW
    double massLow_;
    double massHigh_;
    bool TPchecksign_;
    bool TAGcheckclass_;
    bool PROBEetcut_;
    bool PROBEcheckclass_;

    // electron selection NEW
    double minEt_;
    double minPt_;
    double maxAbsEta_;
    bool isEB_;
    bool isEE_;
    bool isNotEBEEGap_;
    bool isEcalDriven_;
    bool isTrackerDriven_;
    double eOverPMinBarrel_;
    double eOverPMaxBarrel_;
    double eOverPMinEndcaps_;
    double eOverPMaxEndcaps_;
    double dEtaMinBarrel_;
    double dEtaMaxBarrel_;
    double dEtaMinEndcaps_;
    double dEtaMaxEndcaps_;
    double dPhiMinBarrel_;
    double dPhiMaxBarrel_;
    double dPhiMinEndcaps_;
    double dPhiMaxEndcaps_;
    double sigIetaIetaMinBarrel_;
    double sigIetaIetaMaxBarrel_;
    double sigIetaIetaMinEndcaps_;
    double sigIetaIetaMaxEndcaps_;
    double hadronicOverEmMaxBarrel_;
    double hadronicOverEmMaxEndcaps_;
    double mvaMin_;
    double tipMaxBarrel_;
    double tipMaxEndcaps_;
    double tkIso03Max_;
    double hcalIso03Depth1MaxBarrel_;
    double hcalIso03Depth1MaxEndcaps_;
    double hcalIso03Depth2MaxEndcaps_;
    double ecalIso03MaxBarrel_;
    double ecalIso03MaxEndcaps_;

    // for trigger NEW
    edm::InputTag triggerResults_;
//    std::vector<std::string > HLTPathsByName_;

    // histos limits and binning
    int nbineta; int nbineta2D; double etamin; double etamax;
    int nbinphi; int nbinphi2D; double phimin; double phimax;
    int nbinpt; int nbinpteff; int nbinpt2D; double ptmax;
    int nbinp; int nbinp2D; double pmax;
    int nbineop; int nbineop2D; double eopmax; double eopmaxsht;
    int nbindeta; double detamin; double detamax;
    int nbindphi; double dphimin; double dphimax;
    int nbindetamatch; int nbindetamatch2D; double detamatchmin; double detamatchmax;
    int nbindphimatch; int nbindphimatch2D; double dphimatchmin; double dphimatchmax;
    int nbinfhits; double fhitsmax;
    int nbinlhits; double lhitsmax;
    int nbinxyz; int nbinxyz2D;
    int nbinpoptrue; double poptruemin; double poptruemax; //NEW
    int nbinmee; double meemin; double meemax; //NEW
    int nbinhoe; double hoemin; double hoemax; //NEW

    //=========================================
    // general attributes and utility methods
    //=========================================

    unsigned int nEvents_ ;

    float computeInvMass
     ( const reco::GsfElectron & e1,
       const reco::GsfElectron & e2 ) ;
    void fillMatchedHistos
     ( const reco::SuperClusterCollection::const_iterator & moIter,
       const reco::GsfElectron & electron ) ;

    bool selected( const reco::GsfElectronCollection::const_iterator & gsfIter , double vertexTIP ) ;
    bool generalCut( const reco::GsfElectronCollection::const_iterator & gsfIter) ;
    bool etCut( const reco::GsfElectronCollection::const_iterator & gsfIter ) ;
    bool isolationCut( const reco::GsfElectronCollection::const_iterator & gsfIter, double vertexTIP ) ;
    bool idCut( const reco::GsfElectronCollection::const_iterator & gsfIter ) ;

//    bool trigger( const edm::Event & e ) ;
//    unsigned int nAfterTrigger_;
//    std::vector<unsigned int> HLTPathsByIndex_;

    TrajectoryStateTransform transformer_ ;
    edm::ESHandle<TrackerGeometry> pDD;
    edm::ESHandle<MagneticField> theMagField;

    float mcEnergy[10], mcEta[10], mcPhi[10], mcPt[10], mcQ[10];
    float superclusterEnergy[10], superclusterEta[10], superclusterPhi[10], superclusterEt[10];
    float seedMomentum[10], seedEta[10], seedPhi[10], seedPt[10], seedQ[10];

    //=========================================
    // histograms
    //=========================================

    // general
//    MonitorElement * h2_ele_beamSpotXvsY ;
//    MonitorElement * py_ele_nElectronsVsLs ;
//    MonitorElement * py_ele_nClustersVsLs ;
//    MonitorElement * py_ele_nGsfTracksVsLs ;
//    MonitorElement * py_ele_nTracksVsLs ;
//    MonitorElement * py_ele_nVerticesVsLs ;
//    MonitorElement * h1_ele_triggers ;

    // basic quantities
//    MonitorElement * h1_ele_num_ ; // number of electrons in a single event
//    MonitorElement * h1_ele_charge ;
//    MonitorElement * h1_ele_vertexP ;
//    MonitorElement * h1_ele_Et ;
//    MonitorElement * h1_ele_vertexTIP ;
//    MonitorElement * h1_ele_vertexEta ;
//    MonitorElement * h1_ele_vertexPhi ;
//    MonitorElement * h1_ele_vertexX ;
//    MonitorElement * h1_ele_vertexY ;
    MonitorElement * h1_ele_vertexPt_barrel ;
    MonitorElement * h1_ele_vertexPt_endcaps ;
    MonitorElement * h2_ele_vertexEtaVsPhi ;
    MonitorElement * h2_ele_vertexXvsY ;
    MonitorElement * h1_ele_vertexZ ;

    // super-clusters
//    MonitorElement * h1_scl_En ;
//    MonitorElement * h1_scl_Eta ;
//    MonitorElement * h1_scl_Phi ;
    MonitorElement * h1_scl_Et ;

    // gsf tracks
//    MonitorElement * h1_ele_ambiguousTracks ;
//    MonitorElement * h2ele_ambiguousTracksVsEta ;
//    MonitorElement * h2_ele_ambiguousTracksVsPhi ;
//    MonitorElement * h2_ele_ambiguousTracksVsPt ;
    MonitorElement * h1_ele_chi2 ;
//    MonitorElement * py_ele_chi2VsEta ;
//    MonitorElement * py_ele_chi2VsPhi ;
//    MonitorElement * h2_ele_chi2VsPt ;
    MonitorElement * h1_ele_foundHits ;
//    MonitorElement * py_ele_foundHitsVsEta ;
//    MonitorElement * py_ele_foundHitsVsPhi ;
//    MonitorElement * h2_ele_foundHitsVsPt ;
    MonitorElement * h1_ele_lostHits ;
//    MonitorElement * py_ele_lostHitsVsEta ;
//    MonitorElement * py_ele_lostHitsVsPhi ;
//    MonitorElement * h2_ele_lostHitsVsPt ;

    // electron matching and ID
    //MonitorElement * h_ele_EopOut ;
    //MonitorElement * h_ele_dEtaCl_propOut ;
    //MonitorElement * h_ele_dPhiCl_propOut ;
//    MonitorElement * h1_ele_Eop ;
//    MonitorElement * h2_ele_EopVsEta ;
    MonitorElement * h1_ele_Eop_barrel ;
    MonitorElement * h1_ele_Eop_endcaps ;
//    MonitorElement * py_ele_EopVsPhi ;
//    MonitorElement * h1_ele_EopVsPt ;
//    MonitorElement * h1_ele_EeleOPout ;
//    MonitorElement * h2_ele_EeleOPoutVsEta ;
    MonitorElement * h1_ele_EeleOPout_barrel ;
    MonitorElement * h1_ele_EeleOPout_endcaps ;
//    MonitorElement * h2_ele_EeleOPoutVsPhi ;
//    MonitorElement * h2_ele_EeleOPoutVsPt ;
//    MonitorElement * h1_ele_dEtaSc_propVtx ;
//    MonitorElement * h2_ele_dEtaSc_propVtxVsEta ;
    MonitorElement * h1_ele_dEtaSc_propVtx_barrel ;
    MonitorElement * h1_ele_dEtaSc_propVtx_endcaps ;
//    MonitorElement * py_ele_dEtaSc_propVtxVsPhi ;
//    MonitorElement * h2_ele_dEtaSc_propVtxVsPt ;
//    MonitorElement * h1_ele_dEtaEleCl_propOut ;
//    MonitorElement * h2_ele_dEtaEleCl_propOutVsEta ;
    MonitorElement * h1_ele_dEtaEleCl_propOut_barrel ;
    MonitorElement * h1_ele_dEtaEleCl_propOut_endcaps ;
//    MonitorElement * h2_ele_dEtaEleCl_propOutVsPhi ;
//    MonitorElement * h2_ele_dEtaEleCl_propOutVsPt ;
//    MonitorElement * h1_ele_dPhiSc_propVtx ;
//    MonitorElement * h2_ele_dPhiSc_propVtxVsEta ;
    MonitorElement * h1_ele_dPhiSc_propVtx_barrel ;
    MonitorElement * h1_ele_dPhiSc_propVtx_endcaps ;
//    MonitorElement * py_ele_dPhiSc_propVtxVsPhi ;
//    MonitorElement * h2_ele_dPhiSc_propVtxVsPt ;
//    MonitorElement * h1_ele_dPhiEleCl_propOut ;
//    MonitorElement * h2_ele_dPhiEleCl_propOutVsEta ;
    MonitorElement * h1_ele_dPhiEleCl_propOut_barrel ;
    MonitorElement * h1_ele_dPhiEleCl_propOut_endcaps ;
//    MonitorElement * h2_ele_dPhiEleCl_propOutVsPhi ;
//    MonitorElement * h2_ele_dPhiEleCl_propOutVsPt ;
//    MonitorElement * h1_ele_Hoe ;
//    MonitorElement * h2_ele_HoeVsEta ;
    MonitorElement * h1_ele_Hoe_barrel ;
    MonitorElement * h1_ele_Hoe_endcaps ;
//    MonitorElement * py_ele_HoeVsPhi ;
//    MonitorElement * h2_ele_HoeVsPt ;
    MonitorElement * h1_scl_SigEtaEta_barrel ;
    MonitorElement * h1_scl_SigEtaEta_endcaps ;

    // fbrem related variables
    //MonitorElement * h_ele_outerP ;
    //MonitorElement * h_ele_outerP_mode ;
//    MonitorElement * h_ele_innerPt_mean ;
//    MonitorElement * h_ele_outerPt_mean ;
//    MonitorElement * h_ele_outerPt_mode ;
//    MonitorElement * h_ele_PinMnPout ;
//    MonitorElement * h_ele_PinMnPout_mode ;
    MonitorElement * h1_ele_fbrem ;
//    MonitorElement * py_ele_fbremVsEta ;
//    MonitorElement * py_ele_fbremVsPhi ;
//    MonitorElement * h2_ele_fbremVsPt ;
    MonitorElement * h1_ele_classes ;

    // pflow
    MonitorElement * h1_ele_mva ;
    MonitorElement * h1_ele_provenance ;

    // isolation
    MonitorElement * h1_ele_tkSumPt_dr03 ;
    MonitorElement * h1_ele_ecalRecHitSumEt_dr03 ;
    MonitorElement * h1_ele_hcalTowerSumEt_dr03 ;
//    MonitorElement * h1_ele_hcalDepth1TowerSumEt_dr03 ;
//    MonitorElement * h1_ele_hcalDepth2TowerSumEt_dr03 ;
//    MonitorElement * h1_ele_tkSumPt_dr04 ;
//    MonitorElement * h1_ele_ecalRecHitSumEt_dr04 ;
//    MonitorElement * h1_ele_hcalTowerSumEt_dr04 ;
////    MonitorElement * h1_ele_hcalDepth1TowerSumEt_dr04 ;
////    MonitorElement * h1_ele_hcalDepth2TowerSumEt_dr04 ;

    // di-electron mass
    MonitorElement * h1_ele_mee ;
    MonitorElement * h1_ele_mee_os ;


    // histos for matching and matched objects

//    MonitorElement * h1_matchedEle_eta ;
//    MonitorElement * h1_matchedEle_eta_golden ;
//    MonitorElement * h1_matchedEle_eta_shower ;
//    //MonitorElement * h1_matchedEle_eta_bbrem ;
//    //MonitorElement * h1_matchedEle_eta_narrow ;

    MonitorElement * h1_matchedObject_Eta ;
//    MonitorElement * h1_matchedObject_AbsEta ;
    MonitorElement * h1_matchedObject_Pt ;
    MonitorElement * h1_matchedObject_Phi ;
    MonitorElement * h1_matchedObject_Z ;

//    MonitorElement * h1_matchingObject_Num ;
    MonitorElement * h1_matchingObject_Eta ;
//    MonitorElement * h1_matchingObject_AbsEta ;
//    MonitorElement * h1_matchingObject_P ;
    MonitorElement * h1_matchingObject_Pt ;
    MonitorElement * h1_matchingObject_Phi ;
    MonitorElement * h1_matchingObject_Z ;

 } ;

#endif



