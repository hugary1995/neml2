#pragma once

#include "models/SecDerivModel.h"

/// Similar to `SecDerivModel`, but uses automatic differention to get the model's second derivative.
class ADSecDerivModel : public SecDerivModel
{
public:
  using SecDerivModel::SecDerivModel;

  virtual std::tuple<LabeledVector, LabeledMatrix> value_and_dvalue(LabeledVector in) const;

  virtual std::tuple<LabeledMatrix, LabeledTensor<1, 3>> dvalue_and_d2value(LabeledVector in) const;
};
