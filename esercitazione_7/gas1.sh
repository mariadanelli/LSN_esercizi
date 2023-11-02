rm *.dat
cp input.gas input.in
./NVE_NVT.exe
mv output_epot.dat 7.4/gas/output_epot.dat
mv output_press.dat 7.4/gas/output_press.dat
mv output_gf.dat 7.4/gas/output_gf.dat