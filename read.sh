#!/bin/sh
RED='\033[0;31m'
NC='\033[0m'
curr_install_path="/tmp/currently_installed"
ansible_install_path="/tmp/ansible_installed"
./read | sort  > $ansible_install_path
brew list | sort > $curr_install_path
printf "Diff programs in ansible: \n"
grep -v -f $curr_install_path $ansible_install_path
printf "Diff programs on local: \n"
grep -v -f $ansible_install_path $curr_install_path
rm $ansible_install_path
rm $curr_install_path
