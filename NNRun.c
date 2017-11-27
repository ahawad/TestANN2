#include "fann.h"
#include <stdio.h>

int FANN_API test_callback(struct fann *ann, struct fann_train_data *train,
                           unsigned int max_epochs,
                           unsigned int epochs_between_reports,
                           float desired_error, unsigned int epochs) {
  printf("Epochs     %8d. MSE: %.5f. Desired-MSE: %.5f\n", epochs,
         fann_get_MSE(ann), desired_error);
  return 0;
}

int main() {
  fann_type *calc_out;
  const unsigned int num_input = 5;
  const unsigned int num_output = 1;
  const unsigned int num_layers = 3;
  const unsigned int num_neurons_hidden = 4;
  const float desired_error = (const float)0;
  const unsigned int max_epochs = 1000;
  const unsigned int epochs_between_reports = 10;
  struct fann *ann;
  struct fann_train_data *trainingdata, *testingdata;

  unsigned int i = 0;
  unsigned int decimal_point;

  printf("Creating network.\n");
  ann = fann_create_standard(num_layers, num_input, num_neurons_hidden,
                             num_output);

  trainingdata = fann_read_train_from_file("training.data");
  testingdata = fann_read_train_from_file("testing.data");

  fann_set_activation_steepness_hidden(ann, 1);
  fann_set_activation_steepness_output(ann, 1);

  fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
  fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

  fann_set_train_stop_function(ann, FANN_STOPFUNC_BIT);
  fann_set_bit_fail_limit(ann, 0.01f);

  fann_set_training_algorithm(ann, FANN_TRAIN_RPROP);

  fann_init_weights(ann, trainingdata);

  printf("Training network.\n");
  fann_train_on_data(ann, trainingdata, max_epochs, epochs_between_reports,
                     desired_error);

  printf("Testing network. %f\n", fann_test_data(ann, testingdata));

  for (i = 0; i < fann_length_train_data(testingdata); i++) {
    calc_out = fann_run(ann, testingdata->input[i]);
    printf("Test (%f,%f) -> %f, should be %f, difference=%f\n",
           testingdata->input[i][0], testingdata->input[i][1], calc_out[0],
           testingdata->output[i][0],
           fann_abs(calc_out[0] - testingdata->output[i][0]));

    // Add something to calculate accuracy here
  }

  printf("Saving network.\n");

  fann_save(ann, "TestANN.net");

  decimal_point = fann_save_to_fixed(ann, "TestANN_fixed.net");
  fann_save_train_to_fixed(trainingdata, "TestANN_fixed.data", decimal_point);

  printf("Cleaning up.\n");
  fann_destroy_train(trainingdata);
  fann_destroy_train(testingdata);
  fann_destroy(ann);

  return 0;
}
