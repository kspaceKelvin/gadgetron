#ifndef ACQUISITIONPASSTHROUGHGADGET_H
#define ACQUISITIONPASSTHROUGHGADGET_H

#include "gadgetroncore_export.h"
#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"

#include <complex>

class EXPORTGADGETSCORE AcquisitionPassthroughGadget : 
public Gadget2<GadgetMessageAcquisition,hoNDArray< std::complex<float> > >
{
 public:
  GADGET_DECLARE(AcquisitionPassthroughGadget);
  
 protected:
  virtual int process(GadgetContainerMessage<GadgetMessageAcquisition>* m1,
		      GadgetContainerMessage< hoNDArray< std::complex<float> > >* m2);
};


#endif //ACQUISITIONPASSTHROUGHGADGET_H
