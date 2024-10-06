#!/usr/bin/env bash

KNAME=$(uname -r|grep -Po '\d{1,2}\.\d{1,2}\.\d{1,2}\-\d{1,3}')


echo "Download kernel sources..."
curl https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-${KNAME}.tar.xz -o ./kernel.tar.xz
echo "Unpack kernel sources..."
tar -xvf ./kernel.tar.xz -C /usr/src

make