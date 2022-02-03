#!/bin/sh

# This file is used to quickly recompile the CentOS kernel. To execute, place the file in the root file of the kernel
# source and run the file
#   ./MakeKernel
# This will trigger all of the recompile tasks and post the kernel in the /boot directory.

build_kernel

# Check out command line arguments
for arg in "$@"
do
  if [ $arg = "-r" arg = "-R" ]
  then
    reboot
  fi
done


# Builds the kernel and installs it in the boot directory
function build_kernel() {
  make modules
  make modules_install
  export KERNELVERSION=$(make kernelversion)
  cp arch/x86/boot/bzImage /boot/vmlinuz-$kernelversion
  cp System.map /boot/System.map-$kernelversion
  new-kernel-pkg --mkinitrd --install $KERNELVERSION
}