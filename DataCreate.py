import numpy as np

input_size = 10
hidden_layer_size = 5
output_size = 1


weight_0_1 = 0.2 * np.random.rand(input_size, hidden_layer_size) - 0.1
weight_1_2 = 0.2 * np.random.rand(hidden_layer_size, output_size) - 0.1

bias_0_1 = 0.1 * np.random.rand(hidden_layer_size)
bias_1_2 = 0.1 * np.random.rand(output_size)

np.savetxt("Weight_0_1.txt", weight_0_1, fmt="%f")
np.savetxt("Bias_0_1.txt", bias_0_1, fmt="%f")
np.savetxt("weight_1_2.txt", weight_1_2, fmt="%f")
np.savetxt("Bias_1_2.txt", bias_1_2, fmt="%f")