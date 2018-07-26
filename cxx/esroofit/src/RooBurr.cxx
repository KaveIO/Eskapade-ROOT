/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

//////////////////////////////////////////////////////////////////////////////
//
// BEGIN_HTML
// The Burr distribution is often used to describe insurance claims distributions or household imcome.
// This implementation follows wikipedia:
// https://en.wikipedia.org/wiki/Burr_distribution   
// END_HTML
//

#include "Riostream.h" 

#include <esroofit/RooBurr.h>
#include "RooAbsReal.h" 
#include "TMath.h" 

ClassImp(RooBurr) 

RooBurr::RooBurr(const char *name, const char *title, 
                       RooAbsReal& _x,
                       RooAbsReal& _c,
                       RooAbsReal& _k,
                       RooAbsReal& _lambda) :
  RooAbsPdf(name,title), 
  x("x","x",this,_x),
  c("c","c",this,_c),
  k("k","k",this,_k),
  lambda("lambda","lambda",this,_lambda)
{ 
} 


RooBurr::RooBurr(const RooBurr& other, const char* name) :  
  RooAbsPdf(other,name), 
  x("x",this,other.x),
  c("c",this,other.c),
  k("k",this,other.k),
  lambda("lambda",this,other.lambda)
{ 
} 



Double_t RooBurr::evaluate() const 
{ 
  // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
  return (c*k/lambda)*TMath::Power(x/lambda, c-1)*TMath::Power(1+TMath::Power(x/lambda, c), -k-1) ; 
} 



Int_t RooBurr::getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* /*rangeName*/) const  
{ 
  // LIST HERE OVER WHICH VARIABLES ANALYTICAL INTEGRATION IS SUPPORTED, 
  // ASSIGN A NUMERIC CODE FOR EACH SUPPORTED (SET OF) PARAMETERS 
  // THE EXAMPLE BELOW ASSIGNS CODE 1 TO INTEGRATION OVER VARIABLE X
  // YOU CAN ALSO IMPLEMENT MORE THAN ONE ANALYTICAL INTEGRAL BY REPEATING THE matchArgs 
  // EXPRESSION MULTIPLE TIMES

  if (matchArgs(allVars,analVars,x)) return 1 ; 
  return 0 ; 
} 



Double_t RooBurr::analyticalIntegral(Int_t code, const char* rangeName) const  
{ 
  // RETURN ANALYTICAL INTEGRAL DEFINED BY RETURN CODE ASSIGNED BY getAnalyticalIntegral
  // THE MEMBER FUNCTION x.min(rangeName) AND x.max(rangeName) WILL RETURN THE INTEGRATION
  // BOUNDARIES FOR EACH OBSERVABLE x

  if (code==1) { 
    return TMath::Power(1+TMath::Power(x.min(rangeName)/lambda, c), -k) - TMath::Power(1+TMath::Power(x.max(rangeName)/lambda, c), -k);
  } 
  return 0 ; 
} 



