[Drivers]
  [unit]
    type = ModelUnitTest
    model = 'model'
    batch_shape = '(10,3)'
    output_scalar_names = 'state/internal/slip_hardening_rate'
    output_scalar_values = 'rate'
    input_scalar_names = 'state/internal/slip_hardening state/internal/sum_slip_rates'
    input_scalar_values = 'tau_bar sum_slip'
  []
[]

[Tensors]
  [tau_bar]
    type = Scalar
    values = '40.0'
  []
  [sum_slip]
    type = Scalar
    values = '0.1'
  []
  [rate]
    type = Scalar
    values = '20.0'
  []
[]

[Models]
  [model]
    type = LinearSingleSlipHardeningRule
    hardening_slope = 200.0
  []
[]
