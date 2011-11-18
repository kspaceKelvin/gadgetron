#ifndef ACCUMULATORGADGET_H
#define ACCUMULATORGADGET_H

#include <complex>

#include "gadgetroncore_export.h"
#include "Gadget.h"
#include "GadgetMRIHeaders.h"
#include "hoNDArray.h"

class EXPORTGADGETSCORE AccumulatorGadget : 
public Gadget2< GadgetMessageAcquisition, hoNDArray< std::complex<float> > >
{
  
 public:
  GADGET_DECLARE(AccumulatorGadget);

  AccumulatorGadget();
  ~AccumulatorGadget();

 protected:
  virtual int process_config(ACE_Message_Block* mb);
  virtual int process(GadgetContainerMessage< GadgetMessageAcquisition >* m1,
		      GadgetContainerMessage< hoNDArray< std::complex<float> > > * m2);

  hoNDArray< std::complex<float> >* buffer_;
  std::vector<unsigned int> dimensions_;

  int image_counter_;
  int image_series_;

};

#endif //ACCUMULATORGADGET_H
