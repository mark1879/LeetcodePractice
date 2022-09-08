curr_work_path=`pwd`
build_dir_path="$curr_work_path/build"
echo ${build_dir_path}

rm -r -f ${build_dir_path}
mkdir ${build_dir_path}

cd ${build_dir_path}
curr_work_path=`pwd`
echo ${curr_work_path}

cmake ..
make

${build_dir_path}/bin/test_two_sum
${build_dir_path}/bin/test_add_two_numbers
${build_dir_path}/bin/test_length_of_longest_sub_string
${build_dir_path}/bin/test_max_area
${build_dir_path}/bin/test_can_jump
${build_dir_path}/bin/test_jump
${build_dir_path}/bin/test_is_match
${build_dir_path}/bin/test_can_complete_circuit


