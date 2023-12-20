// Copyright 2023, UChicago Argonne, LLC
// All Rights Reserved
// Software Name: NEML2 -- the New Engineering material Model Library, version 2
// By: Argonne National Laboratory
// OPEN SOURCE LICENSE (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "neml2/models/solid_mechanics/crystal_plasticity/SlipStrengthMap.h"
#include "neml2/models/crystallography/CrystalGeometry.h"

#include "neml2/tensors/tensors.h"
#include "neml2/tensors/list_tensors.h"

using vecstr = std::vector<std::string>;

namespace neml2
{
OptionSet
SlipStrengthMap::expected_options()
{
  OptionSet options = Model::expected_options();

  options.set<LabeledAxisAccessor>("slip_strengths") =
      vecstr{"state", "internal", "slip_strengths"};
  options.set<std::string>("crystal_geometry_name") = "crystal_geometry";

  return options;
}

SlipStrengthMap::SlipStrengthMap(const OptionSet & options)
  : Model(options),
    crystal_geometry(include_data<crystallography::CrystalGeometry>(
        options.get<std::string>("crystal_geometry_name"))),
    slip_strengths(declare_output_variable_list<Scalar>(
        options.get<LabeledAxisAccessor>("slip_strengths"), crystal_geometry.nslip()))
{
  setup();
}

} // namespace neml2
