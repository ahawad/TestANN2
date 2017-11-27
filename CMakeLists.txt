project(TestANN)
cmake_minimum_required(VERSION 3.5.1)

set(FANN_LIB_DIR "/usr/local/lib")
set(FANN_LIB_FLAGS "-lm -lfann")



add_executable(NNRun NNRun.c)
add_executable(GenerateSets GenerateSets.c)
add_executable(DataGenerator DataGenerator.c)

target_link_libraries(NNRun "-L${FANN_LIB_DIR} ${FANN_LIB_FLAGS}")
target_link_libraries(GenerateSets "-L${FANN_LIB_DIR} ${FANN_LIB_FLAGS}")
target_link_libraries(DataGenerator "-L${FANN_LIB_DIR} ${FANN_LIB_FLAGS}")
