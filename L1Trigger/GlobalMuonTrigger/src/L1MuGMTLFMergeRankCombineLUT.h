//-------------------------------------------------
//
/** \class L1MuGMTLFMergeRankCombineLUT
 *
 *   LFMergeRankCombine look-up table
 *          
 *   this class was automatically generated by 
 *     L1MuGMTLUT::MakeSubClass()  
*/ 
//   $Date: 2007/04/02 15:45:38 $
//   $Revision: 1.3 $
//
//   Author :
//   H. Sakulin            HEPHY Vienna
//
//   Migrated to CMSSW:
//   I. Mikulec
//
//--------------------------------------------------
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTLFMergeRankCombineLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTLFMergeRankCombineLUT_h

//---------------
// C++ Headers --
//---------------


//----------------------
// Base Class Headers --
//----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLUT.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------


class L1MuGMTLFMergeRankCombineLUT : public L1MuGMTLUT {
  
 public:
  enum {DT, BRPC, CSC, FRPC};

  /// constuctor using function-lookup
  L1MuGMTLFMergeRankCombineLUT() : L1MuGMTLUT("LFMergeRankCombine", 
				       "DT BRPC CSC FRPC",
				       "rank_etaq(7) rank_ptq(2) rank_etaphi(1)",
				       "merge_rank(8)", 9, false) {
    InitParameters();
  } ;

  /// destructor
  virtual ~L1MuGMTLFMergeRankCombineLUT() {};

  /// specific lookup function for merge_rank
  unsigned SpecificLookup_merge_rank (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const {
    std::vector<unsigned> addr(3);
    addr[0] = rank_etaq;
    addr[1] = rank_ptq;
    addr[2] = rank_etaphi;
    return Lookup(idx, addr) [0];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const {
    std::vector<unsigned> addr(3);
    addr[0] = rank_etaq;
    addr[1] = rank_ptq;
    addr[2] = rank_etaphi;
    return LookupPacked(idx, addr);
  };



  /// access to lookup function with packed input and output

  virtual unsigned LookupFunctionPacked (int idx, unsigned address) const {
    std::vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx ,addr[0] ,addr[1] ,addr[2]);

  };

 private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const;

  /// Private data members (LUT parameters);
};
#endif



















