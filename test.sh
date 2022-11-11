#!/bin/bash
echo >> export LD_LIBRARY_PATH=`pwd`/lib/encoder ~/.bashrc
echo >> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/lib/decoder ~/.bashrc 
