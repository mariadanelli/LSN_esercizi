rm *.dat
cp input.gas input.in
./NVE_NVT.exe
mv output_epot.dat 7.1/gas/output_epot.dat