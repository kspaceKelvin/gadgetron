#pragma once

#include "cuSenseOperator.h"

template<class REAL, unsigned int D>
class EXPORTGPUPMRI cuCartesianSenseOperator 
	: public cuSenseOperator<REAL,D>
{
 public:

  cuCartesianSenseOperator() : cuSenseOperator<REAL,D>() {}
  virtual ~cuCartesianSenseOperator() {}

  typedef typename cuSenseOperator<REAL,D>::_complext _complext;

  virtual int mult_M( cuNDArray< _complext> *in, cuNDArray< _complext> *out, bool accumulate = false);
  virtual int mult_MH( cuNDArray< _complext> *in, cuNDArray< _complext> *out, bool accumulate = false);

  virtual int set_sampling_indices( boost::shared_ptr< cuNDArray<unsigned int> > idx) {
    if (idx.get()) {
      idx_ = idx;
      std::vector<unsigned int> tmp_dims;
      tmp_dims.push_back(idx_->get_number_of_elements());
      tmp_dims.push_back(this->ncoils_);
      this->set_codomain_dimensions(&tmp_dims);
    }
    return 0;
  }

  virtual boost::shared_ptr< linearOperator< REAL, cuNDArray< complext<REAL>  > > > clone(){
    return linearOperator< REAL, cuNDArray<complext<REAL> > >::clone(this);
  }
  
 protected:
  boost::shared_ptr< cuNDArray<unsigned int> > idx_;
};