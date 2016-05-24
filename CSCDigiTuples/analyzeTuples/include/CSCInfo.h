#ifndef CSCUCLA_CSCDIGITUPLES_ANALYZETUPLES_CSCINFO_H
#define CSCUCLA_CSCDIGITUPLES_ANALYZETUPLES_CSCINFO_H

#include <TFile.h>
#include <TString.h>
#include <TTree.h>
#include <assert.h>
#include <iostream>
#include "BaseTupleAnalyzer.h"


typedef   unsigned char        size8 ; // 8 bit 0->255
typedef   unsigned short int   size16; //16 bit 0->65536
typedef   unsigned int         size  ; //32 bit 0->4294967296

class EventInfo {
public:
  //Event Info
  int Event_EventNumber;
  int Event_RunNumber  ;
  int Event_LumiSection;
  int Event_BXCrossing ;
  void load(BaseTupleAnalyzer * analyzer) {
    analyzer->setBranchAddress("Event_EventNumber", &Event_EventNumber);
    analyzer->setBranchAddress("Event_RunNumber", &Event_RunNumber);
    analyzer->setBranchAddress("Event_LumiSection", &Event_LumiSection);
    analyzer->setBranchAddress("Event_BXCrossing", &Event_BXCrossing);
  }
};

class RecHitInfo {
public:
  std::vector<size16>* rh_id          ;
  std::vector<size8> * rh_lay         ;
  std::vector<float> * rh_pos_x       ;
  std::vector<float> * rh_pos_y       ;
  std::vector<size8> * rh_strip_1 ;
  std::vector<size8> * rh_strip_2 ;
  std::vector<size8> * rh_strip_3 ;
  std::vector<float> * rh_pos_strip   ;
  std::vector<size8> * rh_n_wiregroups;

  RecHitInfo() {
    rh_id           = new std::vector<size16>  ;
    rh_lay          = new std::vector<size8>   ;
    rh_pos_x        = new std::vector<float>            ;
    rh_pos_y        = new std::vector<float>            ;
    rh_strip_1      = new std::vector<size8>    ;
    rh_strip_2      = new std::vector<size8>    ;
    rh_strip_3      = new std::vector<size8>    ;
    rh_pos_strip    = new std::vector<float>               ;
    rh_n_wiregroups = new std::vector<size8>    ;
  }

  void load(BaseTupleAnalyzer * analyzer) {
    analyzer->setBranchAddress("rh_id"          ,&rh_id          );
    analyzer->setBranchAddress("rh_lay"         ,&rh_lay         );
    analyzer->setBranchAddress("rh_pos_x"       ,&rh_pos_x       );
    analyzer->setBranchAddress("rh_pos_y"       ,&rh_pos_y       );
    analyzer->setBranchAddress("rh_strip_1" ,&rh_strip_1 );
    analyzer->setBranchAddress("rh_strip_2" ,&rh_strip_2 );
    analyzer->setBranchAddress("rh_strip_3" ,&rh_strip_3 );
    analyzer->setBranchAddress("rh_pos_strip"   ,&rh_pos_strip   );
    analyzer->setBranchAddress("rh_n_wiregroups",&rh_n_wiregroups);
  }
};

class StripInfo {
public:
  std::vector<size16>   * strip_id    ;
  std::vector<size8>    * strip_lay   ;
  std::vector<size8>    * strip_number;

  StripInfo() {
    strip_id        = new std::vector<size16>;
    strip_lay       = new std::vector<size8> ;
    strip_number    = new std::vector<size8> ;
  }

  void load(BaseTupleAnalyzer * analyzer) {
    analyzer->setBranchAddress("strip_id"           ,&strip_id     );
    analyzer->setBranchAddress("strip_lay"       ,&strip_lay );
    analyzer->setBranchAddress("strip_number"          ,&strip_number    );
  }
};

class CompInfo {
public:
  std::vector<size16>    *                       comp_id    ;
  std::vector<size8>     *                       comp_lay   ;
  std::vector<size8>     *                       comp_strip ;
  std::vector<size8>     *                       comp_comp  ;


  CompInfo() {
    comp_id     = new std::vector<size16>;
    comp_lay    = new std::vector<size8> ;
    comp_strip  = new std::vector<size8> ;
    comp_comp   = new std::vector<size8> ;


  }

  void load(BaseTupleAnalyzer * analyzer) {
    analyzer->setBranchAddress("comp_id"          ,&comp_id    );
    analyzer->setBranchAddress("comp_lay"         ,&comp_lay   );
    analyzer->setBranchAddress("comp_strip"       ,&comp_strip );
    analyzer->setBranchAddress("comp_comp"        ,&comp_comp  );

  }
};

class WireInfo {
public:
  std::vector<size16>    *                       wire_id  ;
  std::vector<size8>     *                       wire_lay ;
  std::vector<size8>     *                       wire_grp ;
  std::vector<size8>     *                       wire_time;


  WireInfo() {
    wire_id  = new std::vector<size16>;
    wire_lay = new std::vector<size8> ;
    wire_grp = new std::vector<size8> ;
    wire_time= new std::vector<size8> ;


  }

  void load(BaseTupleAnalyzer * analyzer) {
    analyzer->setBranchAddress("wire_id"     ,&wire_id  );
    analyzer->setBranchAddress("wire_lay"    ,&wire_lay );
    analyzer->setBranchAddress("wire_grp"    ,&wire_grp );
    analyzer->setBranchAddress("wire_time"   ,&wire_time);
  }
};

class LCTInfo {
public:
  std::vector<size16>* lct_id          ;
  std::vector<size8> * lct_quality     ;
  std::vector<size8> * lct_pattern     ;
  std::vector<size8> * lct_bend        ;
  std::vector<size8> * lct_keyWireGroup;
  std::vector<size8> * lct_keyHalfStrip;


  LCTInfo() {
    lct_id           = new std::vector<size16>;
    lct_quality      = new std::vector<size8> ;
    lct_pattern      = new std::vector<size8> ;
    lct_bend         = new std::vector<size8> ;
    lct_keyWireGroup = new std::vector<size8> ;
    lct_keyHalfStrip = new std::vector<size8> ;
  }

  void load(BaseTupleAnalyzer * analyzer) {

    analyzer->setBranchAddress("lct_id"          ,&lct_id          );
    analyzer->setBranchAddress("lct_quality"     ,&lct_quality     );
    analyzer->setBranchAddress("lct_pattern"     ,&lct_pattern     );
    analyzer->setBranchAddress("lct_bend"        ,&lct_bend        );
    analyzer->setBranchAddress("lct_keyWireGroup",&lct_keyWireGroup);
    analyzer->setBranchAddress("lct_keyHalfStrip",&lct_keyHalfStrip);
  }
};

class SegmentInfo {
public:
  std::vector<size16>*  segment_id             ;
  std::vector<float> *  segment_pos_x          ;
  std::vector<float> *  segment_pos_y          ;
  std::vector<float> *  segment_dxdz      ;
  std::vector<float> *  segment_dydz        ;
  std::vector<float> *  segment_chisq          ;
  std::vector<size8> *  segment_nHits          ;
  std::vector<size16>*  segment_recHitIdx_1    ;
  std::vector<size16>*  segment_recHitIdx_2    ;
  std::vector<size16>*  segment_recHitIdx_3    ;
  std::vector<size16>*  segment_recHitIdx_4    ;
  std::vector<size16>*  segment_recHitIdx_5    ;
  std::vector<size16>*  segment_recHitIdx_6    ;


  SegmentInfo() {
    segment_id          = new std::vector<size16>;
    segment_pos_x       = new std::vector<float> ;
    segment_pos_y       = new std::vector<float> ;
    segment_dxdz   = new std::vector<float> ;
    segment_dydz     = new std::vector<float> ;
    segment_chisq       = new std::vector<float> ;
    segment_nHits       = new std::vector<size8> ;
    segment_recHitIdx_1 = new std::vector<size16>;
    segment_recHitIdx_2 = new std::vector<size16>;
    segment_recHitIdx_3 = new std::vector<size16>;
    segment_recHitIdx_4 = new std::vector<size16>;
    segment_recHitIdx_5 = new std::vector<size16>;
    segment_recHitIdx_6 = new std::vector<size16>;

  }

  void load(BaseTupleAnalyzer * analyzer) {

    analyzer->setBranchAddress("segment_id"          ,&segment_id         );
    analyzer->setBranchAddress("segment_pos_x"       ,&segment_pos_x      );
    analyzer->setBranchAddress("segment_pos_y"       ,&segment_pos_y      );
    analyzer->setBranchAddress("segment_dxdz"   ,&segment_dxdz  );
    analyzer->setBranchAddress("segment_dydz"     ,&segment_dydz    );
    analyzer->setBranchAddress("segment_chisq"       ,&segment_chisq      );
    analyzer->setBranchAddress("segment_nHits"       ,&segment_nHits      );
    analyzer->setBranchAddress("segment_recHitIdx_1" ,&segment_recHitIdx_1);
    analyzer->setBranchAddress("segment_recHitIdx_2" ,&segment_recHitIdx_2);
    analyzer->setBranchAddress("segment_recHitIdx_3" ,&segment_recHitIdx_3);
    analyzer->setBranchAddress("segment_recHitIdx_4" ,&segment_recHitIdx_4);
    analyzer->setBranchAddress("segment_recHitIdx_5" ,&segment_recHitIdx_5);
    analyzer->setBranchAddress("segment_recHitIdx_6" ,&segment_recHitIdx_6);
  }
};




#endif